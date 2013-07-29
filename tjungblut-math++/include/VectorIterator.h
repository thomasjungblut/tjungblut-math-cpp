#pragma once

namespace tjmath {

	template <class VALUE_TYPE>
	class VectorIterator : public std::iterator<std::input_iterator_tag, VALUE_TYPE>
	{
		VALUE_TYPE* p;

	public:
		VectorIterator(VALUE_TYPE* x) :p(x) {}
		VectorIterator(const VectorIterator& mit) : p(mit.p) {}
		VectorIterator& operator++() {++p;return *this;}
		VectorIterator operator++(int) {VectorIterator tmp(*this); operator++(); return tmp;}
		bool operator==(const VectorIterator& rhs) {return p==rhs.p;}
		bool operator!=(const VectorIterator& rhs) {return p!=rhs.p;}
		VALUE_TYPE& operator*() {return *p;}
	};

}