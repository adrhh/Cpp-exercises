#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	cout << 50 % 60 << endl;
	Time test(23, 59);
	test.show();
	test.add_min(20);
	test.show();

	return 0;
}