#pragma once

#include <memory>
#include "DenseVector.h"


namespace tjmath {

	template <class T>
	class CostGradientTuple
	{
	public:

		CostGradientTuple(void) : cost(0.0), gradient(nullptr)
		{}

		CostGradientTuple(CostGradientTuple<T>& copy)
		{
			this->cost = copy.getCost();
			this->gradient = new DenseVector<T>(copy.getGradient());
		}

		CostGradientTuple(double cost, DenseVector<T> gradient)
		{
			this->cost = cost;
			this->gradient = new DenseVector<T>(gradient);
		}

		virtual ~CostGradientTuple(void)
		{
			if(gradient != NULL)
			{
				delete gradient;
			}
		}

		double getCost() 
		{
			return this->cost;
		}

		DenseVector<T>& getGradient()
		{
			return *gradient;
		}


	private :
		double cost;
		DenseVector<T>* gradient;

	};

}