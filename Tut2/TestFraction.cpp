#include <cstdio>
#include "Fraction.h"

int main() {
	Fraction num1(2, 3);
	Fraction num2(1, 3);
	Fraction ans = num1 / num2;
	ans.print();
	std::getchar();
	return 0;
}