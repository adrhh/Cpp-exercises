#include "date.h"
#include <iostream>

using std::cout;
using std::endl;

void Date::show() const
{
	int day = days;
	int month = 1;
	int year = 1970;
	bool loopflag = true;
	while (loopflag)
	{
		switch (month)
		{
			case 4: case 6: case 9: case 11: //30days months
			{
				if (day < 30)
				{
					loopflag = false;
					break;
				}
				else
				{
					month += 1;
					day -= 30;
					break;
				}
			}
			case 2:
			{
				int maxd = (year % 4 == 0) ? 29 : 28;
				if (day < maxd)
				{
					loopflag = false;
					break;
				}
				else
				{
					month += 1;
					day -= maxd;
					break;
				}
			}
			case 12:
			{
				if (day < 31)
				{
					loopflag = false;
					break;
				}
				else
				{
					month = 1;
					day -= 31;
					year += 1;
					break;
				}
			}
			default:
			{
				if (day < 31)
				{
					loopflag = false;
					break;
				}
				else
				{
					month += 1;
					day -= 31;
					break;
				}
			}
		}
	}

	cout << day << "-" << month << "-" << year << endl;
}