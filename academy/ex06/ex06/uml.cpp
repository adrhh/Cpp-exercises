#include "uml.h"
#include <iostream>

using namespace std;

aggClass::MAX_SIZE = 10;

void assocClass::fun() const
{
	ptrToTest->show();
}

void testClass::show() const
{
	cout << x << " : " << y << endl;
}

void depenClass::fun(testClass* ptr) const
{
	int sum = ptr->getX() + ptr->getY();

	cout << "suma ";
	ptr->show();
	cout << " wynosi: " << sum << endl;
}

