#include "uml.h"
#include <iostream>

using namespace std;


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

void aggClass::showAll() const
{
	for (int i = 0; i < iter; i++)
		ptrTable[i]->show();
}

