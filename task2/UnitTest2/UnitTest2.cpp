#include "pch.h"
#include "CppUnitTest.h"
#include "../linear equation system/Class2.h"
#include "../linear equation system/Class2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(LinearEquationTest)
	{
	public:

		TEST_METHOD(CorrectIndex1)
		{
			vector<double>_a{ 1,2,3,4,6,7 };
			LinearEquation a(_a);
			Assert::AreEqual(2.0, a[1]);
		}
		TEST_METHOD(CorrectIndex2)
		{
			string s = "4,5,6,-7,4,2.9,1,2";
			LinearEquation a(s);
			Assert::AreEqual(2.9, a[5]);
		}

		TEST_METHOD(CorrectIndex3)
		{
			LinearEquation a(10);
			Assert::AreEqual(0.0, a[5]);
		}
		TEST_METHOD(CorrectMult1)
		{
			string s = "4,5,6,-7,4,2.9,1,2";
			LinearEquation a(s);
			a = a * 3.0;
			Assert::AreEqual(12.0, a[0]);
		}
		TEST_METHOD(CorrectMult2)
		{
			string s = "4,5,6,-7,4,2.9,1,2";
			LinearEquation a(s);
			a = 4.0 * a;
			Assert::AreEqual(11.6, a[5]);
		}

		TEST_METHOD(CorrectSum)
		{
			string s1 = "4,5,6,-7,4,2.9,1,2";
			string s2 = "8,13,45.7,7,4,3.2,5,6";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("12,18,51.7,0,8,6.1,6,8");
			Assert::AreEqual(true, res == (a + b));
		}
		TEST_METHOD(CorrectSub)
		{
			string s1 = "4, 5, 6  ,-7,4,2.9,1,2";
			string s2 = "8,13,45.7, 7,4,3.2,5,6";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("-4,-8,-39.7,-14,0,-0.3,-4,-4");
			Assert::AreEqual(true, res == (a - b));
		}

		TEST_METHOD(SameInit)
		{
			LinearEquation a(10);
			a.same_initialization(15.432);
			Assert::AreEqual(15.432, a[6]);
		}

		TEST_METHOD(CorrectUnaryMinus)
		{
			LinearEquation a("-4,-8,-39.7,-14,0,-0.3,-4,-4");
			a = -a;
			Assert::AreEqual(8.0, a[1]);
		}

		TEST_METHOD(CheckContradictoryEquation)
		{
			LinearEquation a("0,0,0,-4");
			bool check = (a) ? true : false;
			Assert::AreEqual(false, check);
		}


		TEST_METHOD(CheckSolvableEquation)
		{
			LinearEquation a("0,2,0,-4");
			bool check = (a) ? true : false;
			Assert::AreEqual(true, check);
		}
		TEST_METHOD(CopyToList)
		{
			LinearEquation a("0,2,0,-4");
			list<double> tmp = a;
			Assert::AreEqual(0.0, tmp.front());
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto func = []() {

				LinearEquation a("0,2,0,-4");
				double tmp = a[-1];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto func = []() {

				LinearEquation a("0,2,0,-4");
				double tmp = a[15];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}
