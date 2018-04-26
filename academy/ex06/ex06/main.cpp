#include "uml.h"

int main()
{
	testClass t1(1, 2), t2(2, 3), t3(0, 0);
	depenClass d1;
	assocClass c1(&t1);
	aggClass a1;
	d1.fun(&t1);
	c1.fun();
	a1.addPtr(&t1);
	a1.addPtr(&t2);
	a1.addPtr(&t3);
	a1.showAll();

	return 0;
}