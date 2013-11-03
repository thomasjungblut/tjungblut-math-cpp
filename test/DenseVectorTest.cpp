#include "stdafx.h"
#include "CppUnitTest.h"

#include <unordered_set>

#include "..\tjungblut-math++\include\DenseVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{		
	TEST_CLASS(DenseVectorTest)
	{
	public:

		TEST_METHOD(TestAllocation)
		{
			tjmath::DenseVector<int> vx (25, 0);
			Assert::AreEqual(25, (int) vx.getLength());
			Assert::AreEqual(25, (int) vx.getDimension());
			int iterations = 0;
			for(auto it = vx.begin(); it != vx.end(); it++)
			{
				iterations++;
				Assert::AreEqual(0,*it);
			}
			Assert::AreEqual(25, iterations);
		}

		TEST_METHOD(TestAllocationCopy)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int) vx.getLength());
			Assert::AreEqual(2, (int) vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(2.f, vx.get(1));

			delete [] arr;
		}

		TEST_METHOD(TestCopyConstruction)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int) vx.getLength());
			Assert::AreEqual(2, (int) vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(2.f, vx.get(1));
			tjmath::DenseVector<float> vx2 (vx);
			Assert::AreEqual(2, (int) vx2.getLength());
			Assert::AreEqual(2, (int) vx2.getDimension());
			Assert::AreEqual(1.f, vx2.get(0));
			Assert::AreEqual(2.f, vx2.get(1));
			delete [] arr;

		}

		TEST_METHOD(TestIteration)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2, arr);
			int numIterations = 0;
			std::unordered_set<float> set;
			for(auto it = vx.begin(); it != vx.end(); it++)
			{
				numIterations++;
				set.insert(*it);
			}

			Assert::AreEqual(2, numIterations);
			Assert::AreEqual(2, (int) set.size());

			Assert::IsTrue(set.find(1.f) != set.end());
			Assert::IsTrue(set.find(2.f) != set.end());

			Assert::IsTrue(set.find(5.f) == set.end());

			delete [] arr;

		}

		TEST_METHOD(TestVectorAdditionVector)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(2.f, vx.get(1));

			float* arr2 = new float [2];
			arr2[0] = 3.f;
			arr2[1] = 5.f;
			tjmath::DenseVector<float> vx2 (2, arr2);

			tjmath::DenseVector<float> res = vx + vx2;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(4.f, res.get(0));
			Assert::AreEqual(7.f, res.get(1));

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestVectorAdditionScalar)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(2.f, vx.get(1));

			tjmath::DenseVector<float> res = vx + 25.f;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(26.f, res.get(0));
			Assert::AreEqual(27.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorSubtractionVector)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 10.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(10.f, vx.get(1));

			float* arr2 = new float [2];
			arr2[0] = 3.f;
			arr2[1] = 5.f;
			tjmath::DenseVector<float> vx2 (2, arr2);

			tjmath::DenseVector<float> res = vx - vx2;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(-2.f, res.get(0));
			Assert::AreEqual(5.f, res.get(1));

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestVectorSubtractionScalar)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(25.f, vx.get(1));

			tjmath::DenseVector<float> res = vx - 25.f;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(-24.f, res.get(0));
			Assert::AreEqual(0.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorSubtractionFromScalar)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(25.f, vx.get(1));

			tjmath::DenseVector<float> res = vx.subtractFrom(25.f);

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(24.f, res.get(0));
			Assert::AreEqual(0.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorMultiplicationVector)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 10.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(10.f, vx.get(1));

			float* arr2 = new float [2];
			arr2[0] = 3.f;
			arr2[1] = 5.f;
			tjmath::DenseVector<float> vx2 (2, arr2);

			tjmath::DenseVector<float> res = vx * vx2;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(3.f, res.get(0));
			Assert::AreEqual(50.f, res.get(1));

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestVectorMultiplicationScalar)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(1.f, vx.get(0));
			Assert::AreEqual(25.f, vx.get(1));

			tjmath::DenseVector<float> res = vx * 25.f;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(25.f, res.get(0));
			Assert::AreEqual(25.f * 25.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorDivisionVector)
		{
			int* arr = new int [2];
			arr[0] = 100;
			arr[1] = 25;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(100, vx.get(0));
			Assert::AreEqual(25, vx.get(1));

			int* arr2 = new int [2];
			arr2[0] = 10;
			arr2[1] = 5;
			tjmath::DenseVector<int> vx2 (2, arr2);

			tjmath::DenseVector<int> res = vx / vx2;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(10, res.get(0));
			Assert::AreEqual(5, res.get(1));

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestVectorDivisionScalar)
		{
			int* arr = new int [2];
			arr[0] = 50;
			arr[1] = 75;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(50, vx.get(0));
			Assert::AreEqual(75, vx.get(1));

			tjmath::DenseVector<int> res = vx / 25;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(2, res.get(0));
			Assert::AreEqual(3, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorDivisionFromVector)
		{
			int* arr = new int [2];
			arr[0] = 10;
			arr[1] = 5;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(10, vx.get(0));
			Assert::AreEqual(5, vx.get(1));

			int* arr2 = new int [2];
			arr2[0] = 100;
			arr2[1] = 25;
			tjmath::DenseVector<int> vx2 (2, arr2);

			tjmath::DenseVector<int> res = vx.divideFrom(vx2);

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(10, res.get(0));
			Assert::AreEqual(5, res.get(1));

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestVectorDivisionFromScalar)
		{
			int* arr = new int [2];
			arr[0] = 5;
			arr[1] = 1;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(5, vx.get(0));
			Assert::AreEqual(1, vx.get(1));

			tjmath::DenseVector<int> res = vx.divideFrom(25);

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(5, res.get(0));
			Assert::AreEqual(25, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestVectorFill)
		{
			int* arr = new int [2];
			arr[0] = 5;
			arr[1] = 1;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(5, vx.get(0));
			Assert::AreEqual(1, vx.get(1));

			tjmath::DenseVector<int> res(2, 0);
			res << vx;

			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(5, res.get(0));
			Assert::AreEqual(1, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestPow)
		{
			float* arr = new float [2];
			arr[0] = 1.f;
			arr[1] = 2.f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());

			tjmath::DenseVector<float> res = vx.pow(2.f);
			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(1.f, res.get(0));
			Assert::AreEqual(4.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestSqrt)
		{
			float* arr = new float [2];
			arr[0] = 100.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());

			tjmath::DenseVector<float> res = vx.sqrt();
			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(10.f, res.get(0));
			Assert::AreEqual(5.f, res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestLog)
		{
			float* arr = new float [2];
			arr[0] = 100.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());

			tjmath::DenseVector<float> res = vx.log();
			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(log(100.f), res.get(0));
			Assert::AreEqual(log(25.f), res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestExp)
		{
			float* arr = new float [2];
			arr[0] = 0.1f;
			arr[1] = 0.2f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());

			tjmath::DenseVector<float> res = vx.exp();
			Assert::AreEqual(2, (int)res.getLength());
			Assert::AreEqual(2, (int)res.getDimension());
			Assert::AreEqual(exp(0.1f), res.get(0));
			Assert::AreEqual(exp(0.2f), res.get(1));

			delete [] arr;

		}

		TEST_METHOD(TestSum)
		{
			float* arr = new float [2];
			arr[0] = 10.f;
			arr[1] = 25.f;
			tjmath::DenseVector<float> vx (2,arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(10.f, vx.get(0));
			Assert::AreEqual(25.f, vx.get(1));

			float res = vx.sum();
			Assert::AreEqual(35.f, res);

			delete [] arr;

		}

		TEST_METHOD(TestDotProduct)
		{
			int* arr = new int [2];
			arr[0] = 10;
			arr[1] = 5;
			tjmath::DenseVector<int> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());
			Assert::AreEqual(10, vx.get(0));
			Assert::AreEqual(5, vx.get(1));

			int* arr2 = new int [2];
			arr2[0] = 100;
			arr2[1] = 25;
			tjmath::DenseVector<int> vx2 (2, arr2);

			int res = vx.dot(vx2);
			Assert::AreEqual(1125,res);

			delete [] arr;
			delete [] arr2;

		}

		TEST_METHOD(TestMinimum)
		{
			int* arr = new int [5];
			arr[0] = 10;
			arr[1] = 25;
			arr[2] = 1;
			arr[3] = 3;
			arr[4] = 30;
			tjmath::DenseVector<int> vx (5, arr);
			Assert::AreEqual(5, (int)vx.getLength());
			Assert::AreEqual(5, (int)vx.getDimension());

			Assert::AreEqual(2, (int)vx.minIndex());
			Assert::AreEqual(1, vx.min());

			delete [] arr;

		}

		TEST_METHOD(TestMaximum)
		{
			int* arr = new int [5];
			arr[0] = 10;
			arr[1] = 25;
			arr[2] = 1;
			arr[3] = 3;
			arr[4] = 30;
			tjmath::DenseVector<int> vx (5, arr);
			Assert::AreEqual(5, (int)vx.getLength());
			Assert::AreEqual(5, (int)vx.getDimension());

			Assert::AreEqual(4, (int)vx.maxIndex());
			Assert::AreEqual(30, vx.max());

			delete [] arr;

		}

		TEST_METHOD(TestChainedExpression)
		{
			float* arr = new float [2];
			arr[0] = 10.0f;
			arr[1] = 25.0f;
			tjmath::DenseVector<float> vx (2, arr);
			Assert::AreEqual(2, (int)vx.getLength());
			Assert::AreEqual(2, (int)vx.getDimension());

			float* arr2 = new float [2];
			arr2[0] = 10.0f;
			arr2[1] = 25.0f;
			tjmath::DenseVector<float> vx2 (2, arr2);

			tjmath::DenseVector<float> realres = vx + (vx * 2.f);

			Assert::AreEqual(30.f, realres.get(0));
			Assert::AreEqual(75.f, realres.get(1));

			delete [] arr;
			delete [] arr2;

		}

	};
}