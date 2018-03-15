#include "constoverload.h"
#include <iostream>

using std::endl;
using std::cout;

int main()
{
	Point3 p1(2,1,2), p2(2, 3, 4);
	Point3 p3 = p1 + p2;
	p1 = p1 * 3;
	cout << p1 << endl << p2 << endl << p3 << endl;

	return 0;
}