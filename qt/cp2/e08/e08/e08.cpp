#include <iostream>
#include "Date.h"

using std::endl;
using std::cout;

int main()
{
	Date d1(2018, 3, 11);
	
	cout << d1.monthDays(2018, 3) << endl;
	cout << d1.getDaysFromStart() << endl;
	cout << d1.getWeekDay() << endl;
	cout << d1.monthName(3) << endl;

	int y, m, d;
	d1.getYMD(y, m, d);

	cout << y << " " << m << " " << d << endl;
	cout << d1.toString(true) << endl;
	cout << d1.toString(false) << endl;

	return 0;
}