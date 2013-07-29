#include <vector>
#include <unordered_set>
#include <math.h>

#include "gtest/gtest.h"
#include "DenseVector.cpp"


using namespace tjmath;

TEST(DenseVectorTest, TestAllocation)
{
	DenseVector<int> vx (25, 0);
	EXPECT_EQ(25, vx.getLength());
	EXPECT_EQ(25, vx.getDimension());
	int iterations = 0;
	for(auto it = vx.begin(); it != vx.end(); it++)
	{
		iterations++;
		EXPECT_EQ(0,*it);
	}
	EXPECT_EQ(25, iterations);
}

TEST(DenseVectorTest, TestAllocationCopy)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(2.f, vx.get(1));

	delete [] arr;
}

TEST(DenseVectorTest, TestCopyConstruction)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(2.f, vx.get(1));
	DenseVector<float> vx2 (vx);
	EXPECT_EQ(2, vx2.getLength());
	EXPECT_EQ(2, vx2.getDimension());
	EXPECT_EQ(1.f, vx2.get(0));
	EXPECT_EQ(2.f, vx2.get(1));
	delete [] arr;

}

TEST(DenseVectorTest, TestIteration)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2, arr);
	int numIterations = 0;
	std::unordered_set<float> set;
	for(auto it = vx.begin(); it != vx.end(); it++)
	{
		numIterations++;
		set.insert(*it);
	}

	EXPECT_EQ(2, numIterations);
	EXPECT_EQ(2, set.size());

	EXPECT_TRUE(set.find(1.f) != set.end());
	EXPECT_TRUE(set.find(2.f) != set.end());

	EXPECT_TRUE(set.find(5.f) == set.end());

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorAdditionVector)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(2.f, vx.get(1));

	float* arr2 = new float [2];
	arr2[0] = 3.f;
	arr2[1] = 5.f;
	DenseVector<float> vx2 (2, arr2);

	DenseVector<float> res = vx + vx2;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(4.f, res.get(0));
	EXPECT_EQ(7.f, res.get(1));

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestVectorAdditionScalar)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(2.f, vx.get(1));

	DenseVector<float> res = vx + 25.f;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(26.f, res.get(0));
	EXPECT_EQ(27.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorSubtractionVector)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 10.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(10.f, vx.get(1));

	float* arr2 = new float [2];
	arr2[0] = 3.f;
	arr2[1] = 5.f;
	DenseVector<float> vx2 (2, arr2);

	DenseVector<float> res = vx - vx2;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(-2.f, res.get(0));
	EXPECT_EQ(5.f, res.get(1));

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestVectorSubtractionScalar)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(25.f, vx.get(1));

	DenseVector<float> res = vx - 25.f;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(-24.f, res.get(0));
	EXPECT_EQ(0.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorSubtractionFromScalar)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(25.f, vx.get(1));

	DenseVector<float> res = vx.subtractFrom(25.f);

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(24.f, res.get(0));
	EXPECT_EQ(0.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorMultiplicationVector)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 10.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(10.f, vx.get(1));

	float* arr2 = new float [2];
	arr2[0] = 3.f;
	arr2[1] = 5.f;
	DenseVector<float> vx2 (2, arr2);

	DenseVector<float> res = vx * vx2;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(3.f, res.get(0));
	EXPECT_EQ(50.f, res.get(1));

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestVectorMultiplicationScalar)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(1.f, vx.get(0));
	EXPECT_EQ(25.f, vx.get(1));

	DenseVector<float> res = vx * 25.f;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(25.f, res.get(0));
	EXPECT_EQ(25.f * 25.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorDivisionVector)
{
	int* arr = new int [2];
	arr[0] = 100;
	arr[1] = 25;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(100, vx.get(0));
	EXPECT_EQ(25, vx.get(1));

	int* arr2 = new int [2];
	arr2[0] = 10;
	arr2[1] = 5;
	DenseVector<int> vx2 (2, arr2);

	DenseVector<int> res = vx / vx2;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(10, res.get(0));
	EXPECT_EQ(5, res.get(1));

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestVectorDivisionScalar)
{
	int* arr = new int [2];
	arr[0] = 50;
	arr[1] = 75;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(50, vx.get(0));
	EXPECT_EQ(75, vx.get(1));

	DenseVector<int> res = vx / 25;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(2, res.get(0));
	EXPECT_EQ(3, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorDivisionFromVector)
{
	int* arr = new int [2];
	arr[0] = 10;
	arr[1] = 5;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(10, vx.get(0));
	EXPECT_EQ(5, vx.get(1));

	int* arr2 = new int [2];
	arr2[0] = 100;
	arr2[1] = 25;
	DenseVector<int> vx2 (2, arr2);

	DenseVector<int> res = vx.divideFrom(vx2);

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(10, res.get(0));
	EXPECT_EQ(5, res.get(1));

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestVectorDivisionFromScalar)
{
	int* arr = new int [2];
	arr[0] = 5;
	arr[1] = 1;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(5, vx.get(0));
	EXPECT_EQ(1, vx.get(1));

	DenseVector<int> res = vx.divideFrom(25);

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(5, res.get(0));
	EXPECT_EQ(25, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestVectorFill)
{
	int* arr = new int [2];
	arr[0] = 5;
	arr[1] = 1;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(5, vx.get(0));
	EXPECT_EQ(1, vx.get(1));

	DenseVector<int> res(2, 0);
	res << vx;

	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(5, res.get(0));
	EXPECT_EQ(1, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestPow)
{
	float* arr = new float [2];
	arr[0] = 1.f;
	arr[1] = 2.f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());

	DenseVector<float> res = vx.pow(2.f);
	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(1.f, res.get(0));
	EXPECT_EQ(4.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestSqrt)
{
	float* arr = new float [2];
	arr[0] = 100.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());

	DenseVector<float> res = vx.sqrt();
	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(10.f, res.get(0));
	EXPECT_EQ(5.f, res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestLog)
{
	float* arr = new float [2];
	arr[0] = 100.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());

	DenseVector<float> res = vx.log();
	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(log(100.f), res.get(0));
	EXPECT_EQ(log(25.f), res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestExp)
{
	float* arr = new float [2];
	arr[0] = 0.1f;
	arr[1] = 0.2f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());

	DenseVector<float> res = vx.exp();
	EXPECT_EQ(2, res.getLength());
	EXPECT_EQ(2, res.getDimension());
	EXPECT_EQ(exp(0.1f), res.get(0));
	EXPECT_EQ(exp(0.2f), res.get(1));

	delete [] arr;

}

TEST(DenseVectorTest, TestSum)
{
	float* arr = new float [2];
	arr[0] = 10.f;
	arr[1] = 25.f;
	DenseVector<float> vx (2,arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(10.f, vx.get(0));
	EXPECT_EQ(25.f, vx.get(1));

	float res = vx.sum();
	EXPECT_EQ(35.f, res);

	delete [] arr;

}

TEST(DenseVectorTest, TestDotProduct)
{
	int* arr = new int [2];
	arr[0] = 10;
	arr[1] = 5;
	DenseVector<int> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());
	EXPECT_EQ(10, vx.get(0));
	EXPECT_EQ(5, vx.get(1));

	int* arr2 = new int [2];
	arr2[0] = 100;
	arr2[1] = 25;
	DenseVector<int> vx2 (2, arr2);

	int res = vx.dot(vx2);
	EXPECT_EQ(1125,res);

	delete [] arr;
	delete [] arr2;

}

TEST(DenseVectorTest, TestMinimum)
{
	int* arr = new int [5];
	arr[0] = 10;
	arr[1] = 25;
	arr[2] = 1;
	arr[3] = 3;
	arr[4] = 30;
	DenseVector<int> vx (5, arr);
	EXPECT_EQ(5, vx.getLength());
	EXPECT_EQ(5, vx.getDimension());

	EXPECT_EQ(2, vx.minIndex());
	EXPECT_EQ(1, vx.min());

	delete [] arr;

}

TEST(DenseVectorTest, TestMaximum)
{
	int* arr = new int [5];
	arr[0] = 10;
	arr[1] = 25;
	arr[2] = 1;
	arr[3] = 3;
	arr[4] = 30;
	DenseVector<int> vx (5, arr);
	EXPECT_EQ(5, vx.getLength());
	EXPECT_EQ(5, vx.getDimension());

	EXPECT_EQ(4, vx.maxIndex());
	EXPECT_EQ(30, vx.max());

	delete [] arr;

}

TEST(DenseVectorTest, TestChainedExpression)
{
	float* arr = new float [2];
	arr[0] = 10.0f;
	arr[1] = 25.0f;
	DenseVector<float> vx (2, arr);
	EXPECT_EQ(2, vx.getLength());
	EXPECT_EQ(2, vx.getDimension());

	float* arr2 = new float [2];
	arr2[0] = 10.0f;
	arr2[1] = 25.0f;
	DenseVector<float> vx2 (2, arr2);

	DenseVector<float> realres = vx + (vx * 2.f);

	EXPECT_EQ(30.f, realres.get(0));
	EXPECT_EQ(75.f, realres.get(1));

	delete [] arr;
	delete [] arr2;

}