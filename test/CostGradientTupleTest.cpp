#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\tjungblut-math++\include\DenseVector.h"
#include "..\tjungblut-math++\include\CostGradientTuple.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(CostGradientTupleTest)
	{
	public:

		TEST_METHOD(TestCostGradientAllocation)
		{
			tjmath::DenseVector<int> vx (25, 0);
			vx.set(10, 3);
			Assert::AreEqual(25, (int)vx.getLength());
			Assert::AreEqual(25, (int)vx.getDimension());
			Assert::AreEqual(3, vx.get(10));

			tjmath::CostGradientTuple<int> costGradient (2.0, vx);
			Assert::AreEqual(2.0, costGradient.getCost());
			tjmath::DenseVector<int> vxRes = costGradient.getGradient();
			Assert::AreEqual(25, (int)vxRes.getLength());
			Assert::AreEqual(25, (int)vxRes.getDimension());
			Assert::AreEqual(3, vxRes.get(10));

		}

	};
}