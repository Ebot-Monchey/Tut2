#include <iostream>
#include "Fraction.h"

int main() {
	cout << "Enter the fraction: ";
	Fraction num1;
	cin >> num1;
	Fraction num2(1, 3);
	Fraction ans = num1 + num2;
	std::cout << ans << endl;
	system("pause");
	return 0;
}