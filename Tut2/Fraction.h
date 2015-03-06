#ifndef FRACTION_H
#define FRACTION_H
	class Fraction {
	private:
		int numer;		// The numerator of the fraction
		int denom;		// The denominator of the fraction

	public:
		Fraction(int numerator = 0, int denominator = 1);
		~Fraction();

		Fraction add(Fraction other);
		Fraction subtract(Fraction other);
		Fraction multiply(Fraction other);
		Fraction divide(Fraction other);

		Fraction operator+(Fraction other);
		Fraction operator-(Fraction other);
		Fraction operator*(Fraction other);
		Fraction operator/(Fraction other);

		void print();
	};
#endif