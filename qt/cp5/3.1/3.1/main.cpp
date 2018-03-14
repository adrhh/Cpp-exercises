#include "complex.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Complex c1(1, 2), c2(3, 4), c3;
	cout << c1 << endl;
	c1 *= 2;
	c3 = c1 * c2;
	cout << c1 << endl << c3 << endl;
	c3 = c3 + 25;
	cout << c3 << endl;
	Complex c4 = c1 / c2;
	cout << c4 << endl;

	return 0;
}