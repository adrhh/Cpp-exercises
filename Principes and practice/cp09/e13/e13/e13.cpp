#include <iostream>
#include "rational.h"

int main()
{
	Rational t1(2, 5), t2(1,3);
	Rational t3 = t1 + t2;
	t3.show();

	return 0;
}