#include "base.h"
#include <iostream>

using std::endl;
using std::cout;

int main()
{
	Base b;
	Derived d;

	cout << "tworze obiekty" << endl;
	b.b();
	cout << "wywowlanie metod" << endl;
	d.a();
	d.b();
	d.c();
	cout << "metody przez wskazniki" << endl;
	Base* bp = &d;
	bp->a();
	bp->b();
	bp->c();

	return 0;
}