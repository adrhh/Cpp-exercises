/* Write a template function max5() that takes as its argument an array of five items
of type T and returns the largest item in the array. (Because the size is fixed, it can
be hard-coded into the loop instead of being passed as an argument.) Test it in a
program that uses the function with an array of five int value and an array of five
double values.*/

#include <iostream>

using namespace std;

template <typename T>
T max5(T t[]);

int main()
{
	double d_arr[5] = { 2.22, 2.221, 2.2, 0.001, 2.0 };
	int i_arr[5] = { 1,6,5,3,3 };

	cout << max5(d_arr) << endl;
	cout << max5(i_arr) << endl;

	return 0;
}

template <typename T>
T max5(T t[])
{
	T max = 0;
	for (int i = 0; i < 5; i++)
		if (t[i] > max)
			max = t[i];

	return max;
}