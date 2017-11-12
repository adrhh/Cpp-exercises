#include "mytime.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Time test1(3, 40);
	Time test2(2, 20);
	Time test3;

	cout << test1 << endl
		<< test2 << endl;

	test3 = test1 - test2;
	test1 = 3 * test1;
	test2 = test2 * 2;
	cout << test1 << endl
		<< test2 << endl
		<< test3 << endl;

	return 0;
}