#include "gtest/gtest.h"
#include "DenseVector.cpp"
#include "CostGradientTuple.h"


using namespace tjmath;


TEST(CostGradientTuple, TestCostGradientAllocation)
{
	DenseVector<int> vx (25, 0);
	vx.set(10, 3);
	EXPECT_EQ(25, vx.getLength());
	EXPECT_EQ(25, vx.getDimension());
	EXPECT_EQ(3, vx.get(10));

	CostGradientTuple<int> costGradient (2.0, vx);
	EXPECT_EQ(2.0, costGradient.getCost());
	DenseVector<int> vxRes = costGradient.getGradient();
	EXPECT_EQ(25, vxRes.getLength());
	EXPECT_EQ(25, vxRes.getDimension());
	EXPECT_EQ(3, vxRes.get(10));

}