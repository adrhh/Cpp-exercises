#include "Date.h"

void Date::is_ok(int y = 0, int m = 0, int d = 0)
{
	if (   y < 1900
		|| m < 0
		|| m > 12
		|| d > monthDays(y, d))

		throw Invalid();
}

bool Date::leapYear(int y)
{
	bool leap = false;
	if (!(y % 4) && y % 100 != 0)
		leap = true;
	return leap;
}

Date::Date()
{}
Date::Date(int y, int m, int d)
{}
int Date::ymd2dfs(int y, int m, int d)
{
	is_ok(y, m, d);
	int year = y - start_year;
	int days = 0;
	days += d;

	//todo
}
void Date::getYMD(int& y, int& m, int& d)
{}
void Date::set(int y, int m, int d)
{}
string Date::toString(bool short_format)
{}
void Date::setToToday()
{}
string Date::getWeekDay() const
{}
bool Date::operator==(const Date& d)
{}
bool Date::operator<(const Date& d)
{}
bool Date::operator>(const Date& d)
{}
int Date::daysBetween(const Date& d)
{}
Date Date::addDays(const Date& d)
{}

string Date::monthName(int m)
{}

int Date::monthDays(int y, int m)
{
	is_ok(y, m);

	int days = 0;
	switch (m)
	{
	case 1: case 3: case 5: case 7: case 8: case 10:  case 12:
		days = 31;
		break;
	case 2:
		if (leapYear(y))
			days = 29;
		else
			days = 28;
		break;
	default:
		days = 30;
	};
	return days;
}