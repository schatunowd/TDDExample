#include "pch.h"
#include <stdexcept>
#include "../task1/Indexer.h"
#include "../task1/Indexer.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		double* array = new double[4]{ 1, 2, 3, 4 };
		TEST_METHOD(HaveCorrectLength)
		{
			indexer ind = indexer(array, 4, 1, 2);
			Assert::AreEqual(2, ind.length);
		}
		TEST_METHOD(GetCorrectly)
		{
			indexer ind = indexer(array, 4, 1, 2);
			Assert::AreEqual(2.0, ind[0]);
			Assert::AreEqual(3.0, ind[1]);
		}
		TEST_METHOD(SetCorrectly)
		{
			indexer ind = indexer(array, 4, 1, 2);
			ind[0] = 10;
			Assert::AreEqual(10.0, ind[0]);
		}
		TEST_METHOD(IndexerDoesNotCopyArray)
		{
			indexer ind0 = indexer(array, 4, 1, 2);
			indexer ind1 = indexer(array, 4, 0, 2);
			ind0[0] = 10;
			Assert::AreEqual(10.0, ind1[1]);
		}
		TEST_METHOD(FailWithWrongArguments1)
		{

			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				indexer ind = indexer(array, 4, -1, 2);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments2)
		{

			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				indexer ind = indexer(array, 4, 1, -2);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments3)
		{

			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				indexer ind = indexer(array, 4, 1, 10);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{

			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				indexer ind = indexer(array, 4, 1, 1);
				ind[-1] = 0;
			};
			Assert::ExpectException<out_of_range>(func);
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{

			auto func = []
			{
				double* array = new double[4]{ 1, 2, 3, 4 };
				indexer ind = indexer(array, 4, 1, 1);
				ind[10] = 0;
			};
			Assert::ExpectException<out_of_range>(func);
		}
	};
}