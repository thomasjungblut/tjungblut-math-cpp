#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\tjungblut-math++\include\DenseVector.h"
#include "..\tjungblut-math++\include\CostGradientTuple.h"
#include "..\tjungblut-math++\include\Fmincg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(FmincgTest)
	{
	public:

		TEST_METHOD(TestSimpleParable)
		{
			// start at x = -5
			tjmath::DenseVector<double> theta (1, -5.);
			Assert::AreEqual(1, (int)theta.getLength());
			Assert::AreEqual(1, (int)theta.getDimension());
			Assert::AreEqual(-5., theta.get(0));


			std::function<tjmath::CostGradientTuple<double> (tjmath::DenseVector<double>)> cf ([] (tjmath::DenseVector<double> input)
			{
				// calculate the cost at our function input^2+10
				double cost = pow(4.0 - input.get(0), 2.0) + 10.0;
				// calculate the gradient as 2*input-8
				tjmath::DenseVector<double> gradient (1, 2. * input.get(0) - 8.0);
				return tjmath::CostGradientTuple<double>(cost, gradient);
			});

			tjmath::DenseVector<double> optimizedParameters = tjmath::Fmincg<double>().minimize(cf, theta, 100, true);
			Assert::AreEqual(4., optimizedParameters.get(0), 1e-5);

		}

	};
}