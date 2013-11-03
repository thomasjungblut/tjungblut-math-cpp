
#include <iostream>

#include "DenseVector.h"
#include "CostGradientTuple.h"
#include "Fmincg.h"


using namespace tjmath;

int main(int argument_count, char** argument_vars) {

	tjmath::DenseVector<double> theta (1, -5.);
	std::function<tjmath::CostGradientTuple<double> (tjmath::DenseVector<double>)> cf ([] (tjmath::DenseVector<double> input)
	{
		// calculate the cost at our function input^2+10
		double cost = pow(4.0 - input.get(0), 2.0) + 10.0;
		// calculate the gradient as 2*input-8
		tjmath::DenseVector<double> gradient (1, 2. * input.get(0) - 8.0);
		return tjmath::CostGradientTuple<double>(cost, gradient);
	});

	tjmath::DenseVector<double> optimizedParameters = tjmath::Fmincg<double>().minimize(cf, theta, 100, true);

	for(auto it = optimizedParameters.begin(); it != optimizedParameters.end(); it++) {
		std::cout << *it << std::endl;
	}

	getchar();

}