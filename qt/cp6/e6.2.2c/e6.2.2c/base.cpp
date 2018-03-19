#include "base.h"
#include <iostream>

using std::endl;
using std::cout;

Base::Base()
{
	cout << "Base::Base()" << endl;
	a();
	c();
}
void Base::a()
{
	cout << "Base::a()" << endl;
	b();
}
void Base::b()
{
	cout << "Base::b()" << endl;
}
void Base::c(bool con)
{
	cout << "Base::c()" << endl;
}

Derived::Derived()
{
	cout << "Derived::Derived()" << endl;
}
void Derived::a()
{
	cout << "Derived::a()" << endl;
	c();
}
void Derived::b()
{
	cout << "Derived::b()" << endl;
}
void Derived::c()
{
	cout << "Derived::c()" << endl;
}