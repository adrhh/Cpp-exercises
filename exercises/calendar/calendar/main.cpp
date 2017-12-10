#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	cout << 50 % 60 << endl;
	Time test(23, 59);
	test.show();
	Time test2(0, 20);
	test2.show();
	test += test2;
	test.show();

	return 0;
}