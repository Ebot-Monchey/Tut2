#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Tut2\Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFraction
{		
	TEST_CLASS(FractionTesting)
	{
	public:
		
		TEST_METHOD(FractionReduction)
		{
			Fraction num1(1, 3);
			Fraction num2(2, 6);
			Assert::AreEqual(num1.getNumerator(), num2.getNumerator());
			Assert::AreEqual(num1.getDenominator(), num2.getDenominator());
		}

		TEST_METHOD(AddPositive)
		{
			Fraction num1(1, 2);
			Fraction num2(1, 3);
			Fraction ans = num1 + num2;
			Assert::AreEqual(ans.getNumerator(), 5);
			Assert::AreEqual(ans.getDenominator(), 6);
		}

		TEST_METHOD(AddNegative)
		{
			Fraction num1(1, 2);
			Fraction num2(-1, 3);
			Fraction ans = num1 + num2;
			Assert::AreEqual(ans.getNumerator(), 1);
			Assert::AreEqual(ans.getDenominator(), 6);
		}

		TEST_METHOD(SubtractPositive)
		{
			Fraction num1(1, 2);
			Fraction num2(1, 3);
			Fraction ans = num1 - num2;
			Assert::AreEqual(ans.getNumerator(), 1);
			Assert::AreEqual(ans.getDenominator(), 6);
		}

		TEST_METHOD(SubtractNegative)
		{
			Fraction num1(1, 2);
			Fraction num2(-1, 3);
			Fraction ans = num1 - num2;
			Assert::AreEqual(ans.getNumerator(), 5);
			Assert::AreEqual(ans.getDenominator(), 6);
		}
	};
}