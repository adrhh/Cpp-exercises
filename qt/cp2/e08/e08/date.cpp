#include "Date.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::to_string;

int Date::start_year = 1900;
vector<string> Date::days_names = { "pon", "wto", "sro", "czw", "pia", "sob", "nie" };
vector<string> Date::month_names = { "sty", "lut", "mar", "kwi", "maj", "cze", "lip", 
									"sie", "wrz", "paz", "lis", "gru" };

void Date::is_ok(int y, int m, int d)
{

	if (   y < 1900
		|| m < 1
		|| m > 12
		|| d > monthDays(y, d)
		|| d < 1)

		throw Invalid();
}

bool Date::leapYear(int y)
{
	bool leap = false;
	if (!(y % 4) && y % 100 != 0)
		leap = true;
	return leap;
}

Date::Date() : days_from_start(0)
{}

Date::Date(int y, int m, int d)
{
	is_ok(y, m, d);
	days_from_start = ymd2dfs(y, m, d);
}

int Date::ymd2dfs(int y, int m, int d)
{
	
	int t_year = y - start_year;
	int t_month = m;
	int days = 0;

	days += d;
	while (t_month != 1)
	{
		days += monthDays(t_year, t_month);
		t_month--;
	}
	while (t_year != 0)
	{
		if (leapYear(t_year))
			days += 366;
		else
			days += 365;
		t_year--;
	}

	return days;
}
void Date::getYMD(int& y, int& m, int& d)
{
	int temp_year = 1900;
	int temp_total_days = days_from_start;
	int days_in_year = 365;

	while (temp_total_days > days_in_year)
	{
		if (leapYear(temp_year))
			temp_total_days -= 366;
		else
			temp_total_days -= 365;
		temp_year++;
		days_in_year = leapYear(temp_year) ? 366 : 365;
	}

	int temp_month = 1;
	while (temp_total_days > monthDays(temp_year, temp_month))
	{
		temp_total_days -= monthDays(temp_year, temp_month);
		temp_month++;
	}

	int temp_day = temp_total_days;

	y = temp_year;
	m = temp_month;
	d = temp_day;
}

void Date::set(int y, int m, int d)
{
	days_from_start = ymd2dfs(y, m, d);
}

string Date::toString(bool short_format)
{
	int y, m, d;
	getYMD(y, m, d);
	string sdate;
	if (short_format)
		sdate += to_string(y) + '/' + to_string(m) + '/' + to_string(d);
	else
		sdate += to_string(y) + ' ' + monthName(m) + ' ' + to_string(d) + ' ' + getWeekDay();
	return sdate;
}

void Date::setToToday()
{}

string Date::getWeekDay() const
{
	//1.1.1900 = pon
	int day_nr = days_from_start % 7;

	return days_names[day_nr];
}

bool Date::operator==(const Date& d)
{
	return days_from_start == d.days_from_start;
}

bool Date::operator<(const Date& d)
{
	return days_from_start < d.days_from_start;
}

bool Date::operator>(const Date& d)
{
	return days_from_start > d.days_from_start;
}

int Date::daysBetween(const Date& d)
{
	return abs(days_from_start - d.days_from_start);
}

Date Date::addDays(const Date& d)
{
	int total_days = days_from_start + d.days_from_start;
	Date temp_d;
	temp_d.days_from_start = total_days;

	return temp_d;
}

string Date::monthName(int m)
{
	return month_names[m - 1];
}

int Date::monthDays(int y, int m)
{
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