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

	return 0;
}