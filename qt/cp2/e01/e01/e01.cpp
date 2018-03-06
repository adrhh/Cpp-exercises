#include "thing.h"

void display(Thing& t, int n)
{
	for (int i = 0; i < n; i++)
		t.show();
}

int main()
{
	Thing t1, t2;
	t1.set(23, 'H');
	t2.set(1234, 'w');
	t1.inc();
	display(t1, 3);
	t2.show();
	return 0;
}