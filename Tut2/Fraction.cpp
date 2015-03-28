// Fraction.cpp implements the Fraction class found in Fraction.h
#include <iostream>
#include "Fraction.h"

/*
 * Creates a new Fraction object with the given arguments. The denominator defaults to 1 and the numerator to 0.
 */
Fraction::Fraction(int numerator, int denominator) {
	numer = numerator;
	denom = denominator;
	reduce();
}

/*
 * Destructor doen't need to be implemented. No manual memory allocation is done.
 */
Fraction::~Fraction() {

}

/*
 * Gets the numerator part of the fraction.
 */
int Fraction::getNumerator() {
	return numer;
}

/*
 * Sets the numerator part of the fraction.
 */
void Fraction::setNumerator(int numerator) {
	numer = numerator;
}

/*
 * Gets the denominator part of the fraction.
 */
int Fraction::getDenominator() {
	return denom;
}

/*
 * Sets the denominator part of the fraction.
 */
void Fraction::setDenominator(int denominator) {
	denom = denominator;
}

/*
 * Adds another fraction to this fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::add(Fraction other) {
	return Fraction(numer*other.denom + other.numer*denom, denom*other.denom);
}

/*
 * Subtracts another fraction from this fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::subtract(Fraction other) {
	return Fraction(numer*other.denom - other.numer*denom, denom*other.denom);
}

/*
 * Multiplies this fraction by another fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::multiply(Fraction other) {
	return Fraction(numer*other.numer, denom*other.denom);
}

/*
 * Divides this fraction by another fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::divide(Fraction other) {
	return Fraction(numer*other.denom, denom*other.numer);
}

/*
 * Prints the fraction in standard form.
 */
void Fraction::print() {
	if (numer == 0) {
		std::cout << "0";
	}
	else if (denom == 1) {
		std::cout << numer;
	}
	else {
		// Display in mixed form
		int mixed = numer / denom;
		if (mixed != 0) {
			std::cout << mixed << " ";
		}
		std::cout << numer%denom << "/" << denom;
	}
}

/*
 * Adds another fraction to this fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::operator+(Fraction other) {
	return Fraction(numer*other.denom + other.numer*denom, denom*other.denom);
}

/*
 * Subtracts another fraction from this fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::operator-(Fraction other) {
	return Fraction(numer*other.denom - other.numer*denom, denom*other.denom);
}

/*
 * Multiplies this fraction by another fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::operator*(Fraction other) {
	return Fraction(numer*other.numer, denom*other.denom);
}

/*
 * Divides this fraction by another fraction and returns a new Fraction object containing the result.
 */
Fraction Fraction::operator/(Fraction other) {
	return Fraction(numer*other.denom, denom*other.numer);
}

/*
 * Reads a fraction in the form of a mixed number from the keyboard.
 */
Fraction read() {
	int mixed, numer, denom;
	std::cout << "Enter the whole number part: ";
	std::cin >> mixed;
	std::cout << "Enter the numerator: ";
	std::cin >> numer;
	std::cout << "Enter the denominator: ";
	std::cin >> denom;
	return Fraction(mixed*denom + numer, denom);
}

/*
 * Overload << to handle output of Fraction class.
 */
std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
	if (frac.numer == 0) {
		out << "0";
	}
	else if (frac.denom == 1) {
		out << frac.numer;
	}
	else {
		// Display in mixed form
		int mixed = frac.numer / frac.denom;
		if (mixed != 0) {
			out << mixed << " ";
		}
		out << frac.numer%frac.denom << "/" << frac.denom;
	}
	return out;
}

/*
* Overload >> to handle input of Fraction class.
*/
std::istream& operator>>(std::istream& in, Fraction& frac) {
	int mixed, numer, denom;
	char temp;		// Holds temporary characters
	in >> noskipws >> mixed;	// Try to read in the whole number part
	in >> temp;
	if (temp == '/') {
		numer = mixed;
		mixed = 0;
		in >> noskipws >> denom;
	}
	else {
		// temp was a space so the whole number was in fact read in
		in >> noskipws >> numer;
		in >> noskipws >> temp;
		in >> noskipws >> denom;
	}
	frac.numer = mixed*denom + numer;
	frac.denom = denom;
	return in;
}

/*
 * Reduces the fraction to its lowest terms using the divisor algorithm to find the gcd.
 */
void Fraction::reduce() {
	int dividend, divisor, quotient, remainder;
	quotient = numer;
	remainder = denom;

	do {
		dividend = quotient;
		divisor = remainder;
		quotient = dividend / divisor;
		remainder = dividend % divisor;
	} while (remainder != 0);

	// divisor contains the gcd
	numer /= divisor;
	denom /= divisor;
}