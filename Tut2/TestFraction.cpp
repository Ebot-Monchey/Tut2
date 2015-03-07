#include <iostream>
#include "Fraction.h"

int main() {
	Fraction num1 = read();
	Fraction num2(1, 3);
	Fraction ans = num1 + num2;
	ans.print();
	system("pause");
	return 0;
}