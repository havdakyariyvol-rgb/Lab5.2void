#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2void/Lab5.2void.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab52voidTest
{
	TEST_CLASS(Lab52voidTest)
	{
	public:

		TEST_METHOD(TestSum)
		{
			double x = 0.5;
			double expected = 1.284025;
			double eps = 0.0001;
			int n = 0;
			double actual = 0;
			Sum(x, eps, n, actual);
			Assert::AreEqual(expected, actual, 0.0001);
		}
		TEST_METHOD(TestA)
		{
			double x = 2.0;
			double actual = 4.0;
			int n = 2;
			double expected = 8.0;
			A(x, n, actual);
			Assert::AreEqual(expected, actual, 0.0001);
		}
	};
}