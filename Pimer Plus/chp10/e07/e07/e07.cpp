#include "prolg.h"

int main()
{
	Prolg test1;
	Prolg test2("Franek", 20);

	test1.show();
	test2.show();
	test2.change(10);
	test2.show();

	return 0;
}