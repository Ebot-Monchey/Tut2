// Fraction.cpp implements the Fraction class found in Fraction.h
#include <iostream>
#include "Fraction.h"

/*
 * Creates a new Fraction object with the given arguments. The denominator defaults to 1 and the numerator to 0.
 */
Fraction::Fraction(int numerator, int denominator) {
	numer = numerator;
	denom = denominator;
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