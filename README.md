This here is a Visual C++ port of specific parts of my common and math library.

These parts include:
- Fmincg (Conjugate Gradient minimizer)
- Templated Dense Vector
- Testcases with Google Test Framework

Vector Arithmetics
------------------

The only currently implemented vector type is currently the dense vector, which directly operates on a chunk of memory.
On the contrary to the Java library I have added a few language features that aren't available in Java.
For example the DenseVector class is now templated and can be used within every type that inherits the used operators.  

So instead of the code in Java:

```java
DoubleVector vx = new DenseDoubleVector(new double[] {x, y});
DoubleVector vx2 = new DenseDoubleVector(new double[] {1, 1});
DoubleVector result = vx.add(vx2.multiply(2d));
```

You can use the overloaded operators:

```cpp
float* arr = new float [2];
arr[0] = 10.0f;
arr[1] = 25.0f;

DenseVector<float> vx (2, arr);
DenseVector<float> vx2 (2, arr);

DenseVector<float> result = vx + (vx2 * 2.f);

delete [] arr;
```

Also instead of the iterator facility in Java:
```java
Iterator<DoubleVectorElement> iter = vector.iterateNonZero();
while (iter.hasNext()) {
    DoubleVectorElement e = iter.next();
	System.print.out(e);
}
```

You can use the widely used begin() and end() iterators in C++:

```cpp
DenseVector<int> vx (25, 0);
for(auto it = vx.begin(); it != vx.end(); it++)
{
	cout << *it << endl;
}

```

Please note that there are no other vector implementations currently. I tried to keep it as minimalistic and lightweight as possible.

FminCG
------------------

The Conjugate Gradient minimizer itself is based on the octave implementation from ml-class. [You can read my write-up about it](http://codingwiththomas.blogspot.de/2012/02/nonlinear-conjugate-gradient-method-in.html "read it!").
After a lot of changes on the Java side, I used a semi-improved version in this c++ version. For example, you can now use lambdas to create the cost function!

```cpp
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
```

To optimize more sophisticated cost functions, you can use an external BLAS library (e.g. ATLAS or LAPACK) and implement a linear regression for example.
I will try to come up with a CUDA implementation using CUBLAS anytime soon, which can also be used for larger neural networks or restricted boltzmann machines.

License
-------

Since I am Apache committer, I consider everything inside of this repository licensed by Apache 2.0 license, although I haven't put the usual header into the source files.

If something is not licensed via Apache 2.0, there is a reference or an additional licence header included in the specific source file.

Package Layout
--------------

This whole project is divided into three packages:
- Main (simple main method that runs an example fmincg optimization)
- Core math (compiles into a *.lib) contains the math related stuff like Vector implementations.
- Tests (simple visual studio unit tests)

Build
-----

You can easily import the solution into Visual Studio 2012. 
The whole build process is already preconfigured, but the order is to compile the tjungblut-math++ subproject, then using the resulted lib\*.lib the test and main projects are compiled.

Have fun hacking!

BTW: If you have improvement suggestions and bug fixes, please write me an e-mail or open an issue! Thank you very much :-)
