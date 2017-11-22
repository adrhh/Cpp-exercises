#include "port.h"
#include <iostream>

using std::endl;
using std::cout;

int main()
{
	Port p1("Ab", "czerwone", 20);
	Port p2 = p1;
	VintagePort p3("BC", "biale", 50, "wypas", 2017);
	p1.show();
	p1 += 2;
	p2 -= 15;
	cout << p2 << endl << endl;

	Port* arr[3] = {&p1, &p2, &p3 };
	for (int i = 0; i < 3; i++)
	{
		cout << *arr[i];
		arr[i]->show();
		cout << endl;
	}
	p3.show();
	cout << endl << p3 << endl;

	return 0;
}