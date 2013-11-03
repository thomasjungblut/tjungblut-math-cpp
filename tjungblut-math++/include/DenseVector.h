#pragma once

#include <vector>

#include "VectorIterator.h"

namespace tjmath {

	template <class VALUE_TYPE>
	// basically for doubles and floats, templates for those are defined in the cpp file
	class DenseVector {

	public:

		DenseVector(void);

		DenseVector(DenseVector<VALUE_TYPE>& vx);

		DenseVector(unsigned int length, VALUE_TYPE defaultValue = 0);

		DenseVector(unsigned int length, VALUE_TYPE* lst);

		DenseVector(unsigned int length, std::vector<VALUE_TYPE> lst);

		virtual ~DenseVector();

		unsigned int getDimension();

		unsigned int getLength();

		VALUE_TYPE get(unsigned int index);

		void set(unsigned int index, VALUE_TYPE value);

		DenseVector<VALUE_TYPE> operator+(DenseVector<VALUE_TYPE> v);

		DenseVector<VALUE_TYPE> operator+(VALUE_TYPE scalar); 

		DenseVector<VALUE_TYPE> operator-(DenseVector<VALUE_TYPE> v);

		// DenseVector - scalar
		DenseVector<VALUE_TYPE> operator-(VALUE_TYPE scalar);

		// scalar - DenseVector
		DenseVector<VALUE_TYPE> subtractFrom(VALUE_TYPE scalar);

		DenseVector<VALUE_TYPE> operator*(DenseVector<VALUE_TYPE> v);

		DenseVector<VALUE_TYPE> operator*(VALUE_TYPE scalar);

		DenseVector<VALUE_TYPE> operator/(DenseVector<VALUE_TYPE> v);

		DenseVector<VALUE_TYPE> operator/(VALUE_TYPE scalar);

		// parameter DenseVector / this DenseVector
		DenseVector<VALUE_TYPE> divideFrom(DenseVector<VALUE_TYPE> v);

		// scalar / DenseVector
		DenseVector<VALUE_TYPE> divideFrom(VALUE_TYPE scalar);

		// this fills the current vector with the given vector values
		void operator<<(DenseVector<VALUE_TYPE> newValues);

		DenseVector<VALUE_TYPE> pow(VALUE_TYPE scalar);

		DenseVector<VALUE_TYPE> sqrt();

		DenseVector<VALUE_TYPE> log();

		DenseVector<VALUE_TYPE> exp();

		VALUE_TYPE sum();

		VALUE_TYPE dot(DenseVector<VALUE_TYPE> v);

		VALUE_TYPE min();

		unsigned int minIndex();

		VALUE_TYPE max();

		unsigned int maxIndex();

		VectorIterator<VALUE_TYPE> begin();

		VectorIterator<VALUE_TYPE> end();

	private : 

		unsigned int dimension;
		VALUE_TYPE* data;

	};


}
