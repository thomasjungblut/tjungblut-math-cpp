#include <gtest/gtest.h>

// link the testcases, make sure no cyclic dependencies arise
#include "../tjungblut-math++/source/test/DenseVectorTest.cpp"
#include "../tjungblut-ml/source/test/CostGradientTupleTest.cpp"
#include "../tjungblut-ml/source/test/FmincgTest.cpp"


int main(int argument_count, char** argument_vars) {

	testing::InitGoogleTest(&argument_count, argument_vars);
	RUN_ALL_TESTS();

}

