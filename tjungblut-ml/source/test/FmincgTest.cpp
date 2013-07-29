#include <math.h>
#include <functional>

#include "gtest/gtest.h"
#include "DenseVector.cpp"
#include "CostGradientTuple.h"
#include "Fmincg.cpp"

using namespace tjmath;


TEST(Fmincg, TestSimpleParable)
{
	// start at x = -5
	DenseVector<double> theta (1, -5.);
	EXPECT_EQ(1, theta.getLength());
	EXPECT_EQ(1, theta.getDimension());
	EXPECT_EQ(-5., theta.get(0));

	Fmincg<double> minimizer;

	std::function<CostGradientTuple<double> (DenseVector<double>)> cf ([] (DenseVector<double> input)
	{
		// calculate the cost at our function input^2+10
		double cost = pow(4.0 - input.get(0), 2.0) + 10.0;
		// calculate the gradient as 2*input-8
		DenseVector<double> gradient (1, 2. * input.get(0) - 8.0);
		return CostGradientTuple<double>(cost, gradient);
	});

	DenseVector<double> optimizedParameters = minimizer.minimize(cf, theta, 100, true);
	ASSERT_NEAR(4., optimizedParameters.get(0), 1e-5);

}