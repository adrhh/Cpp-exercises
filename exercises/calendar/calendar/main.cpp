#include "date.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout << 50 % 60 << endl;
	Time test(23, 59);
	test.show();
	Time test2(0, 20);
	test2.show();
	test += test2;
	test.show();
	test *= 2;
	test.show();
	Time test3;
	test3 = test2 + test;
	test3.show();

	return 0;
}