#include "uml.h"

int main()
{
	testClass t1(1, 2);
	depenClass d1;
	assocClass c1(&t1);
	d1.fun(&t1);
	c1.fun();

	return 0;
}