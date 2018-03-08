#include "emp.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Employer e1("DDD", "food");
	Position p1("cook", "prepare meal");
	cout << e1.toString() << endl;
	cout << p1.toString() << endl;
	Person per1("Adam");
	cout << per1.toString() << endl;
	e1.hire(per1, p1);
	cout << per1.toString() << endl;

	return 0;
}