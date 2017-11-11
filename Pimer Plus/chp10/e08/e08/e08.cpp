#include "list.h"

int main()
{
	List test;
	test.add(2);
	test.add(3);
	test.add(9);
	test.showall();
	test.visit(show);
	test.visit(mult, 3);
	test.visit(show);

	return 0;
}