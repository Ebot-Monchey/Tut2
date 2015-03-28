#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
	class _declspec(dllexport) Fraction {
	private:
		int numer;		// The numerator of the fraction
		int denom;		// The denominator of the fraction
		void reduce();	// Reduces the fraction into its lowest equivalent form

	public:
		Fraction(int numerator = 0, int denominator = 1);
		~Fraction();

		int getNumerator();
		void setNumerator(int numerator);
		int getDenominator();
		void setDenominator(int denominator);

		Fraction operator+(Fraction other);
		Fraction operator-(Fraction other);
		Fraction operator*(Fraction other);
		Fraction operator/(Fraction other);

		void print();
		friend ostream& operator<<(ostream&, const Fraction&);
		friend istream& operator>>(istream&, Fraction&);
	};

	_declspec(dllexport) Fraction read();
#endif