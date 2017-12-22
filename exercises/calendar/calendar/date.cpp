#include <iostream>
#include "date.h"

using std::cout;
using std::wcerr;
using std::endl;

// Time methods
//****************************************************

Time::Time(const int h, const int m ) : hours(h), minutes(m)
{
	if (minutes >= Mmax)
	{
		minutes %= Mmax;
		hours += m / Mmax;
	}
	if (hours >= Hmax)
	{
		days += hours / Hmax;
		hours %= Hmax;
	}
}

Time::Time(const Time& t)
{
	int min = t.minutes;
	int hou = t.hours;
	int res = t.days;
	this->set(hou, min);
	days += res;
}

void Time::set(const int h, const int m)
{
	hours = h;
	minutes = m;
	days = 0;
	if (minutes >= Mmax)
	{
		minutes %= Mmax;
		hours += m / Mmax;
	}
	if (hours >= Hmax)
	{
		days += hours / Hmax;
		hours %= Hmax;
	}
}

void Time::add_min(const int m)
{
	minutes += m;
	hours += minutes / Mmax;
	minutes %= Mmax;
	days += hours / Hmax;
	hours %= Hmax;
}
void Time::add_hour(const int h)
{
	hours += h;
	days += hours / Hmax;
	hours %= Hmax;
}

Time& Time::operator=(const Time& t)
{
	hours = t.hours;
	minutes = t.minutes;
	days = t.days;
	return *this;
}

Time& Time::operator+=(const Time& t)
{
	days += t.days;
	int temp_m = minutes + t.minutes;
	int temp_h = hours + t.hours;
	this->set(temp_h, temp_m);
	return *this;
}

Time& Time::operator-=(const Time& t)
{
	//rest -= t.rest;
	int temp_m = minutes - t.minutes;
	int temp_h = hours - t.hours;
	this->set(temp_h, temp_m);
	return *this;
}

Time& Time::operator*=(const int x)
{
	int tot_min = get_total_min();
	tot_min *= x;
	set(0, tot_min);
	return *this;
}

void Time::show() const
{
	cout << days << ' ' << hours
		 << ' ' << minutes << ' ';
}

ostream& operator<<(ostream& os, Time& t)
{
	os << t.hours << " : " << t.minutes << ' ';
	return os;
}

int Time::get_total_min() const
{
	// days not included
	return  minutes + hours*Mmax;
}

Time operator+(const Time& t1, const Time& t2)
{
	int temp_m = t1.minutes + t2.minutes;
	int temp_h = t1.hours + t2.hours;
	int temp_r = t1.days + t2.days;
	Time temp_t(temp_h, temp_m);
	temp_t.days += temp_r;
	return temp_t;
}

Time operator-(const Time& t1, const Time& t2)
{
	Time temp;
	int tot_min = t1.get_total_min() - t2.get_total_min();
	if (tot_min < 0)
	{
		wcerr << "Nie mozna odjemowac mniejszej ilosci od wiekszej ilosci czasu" << endl
			<< "Zwracam obiekt pusty" << endl;
		temp.set(0, 0);
	}
	else
		temp.set(0, tot_min);

	return temp;
}

bool Time::operator<(const Time& t)
{
	return (get_total_min() < t.get_total_min()) ? true : false;
}

bool Time::operator>(const Time& t)
{
	return (get_total_min() > t.get_total_min()) ? true : false;
}

// Date methods
//****************************************************

Date::Date(const int y, const int m, const int d, const  int h, const int min) 
		  : year(y), month(m), day(d), time(h, min)
{
	set_month_days();
	if (day > month_days)
		//day to max value;
		day = month_days;
	if (month > Mmax)
		//month to max value
		month = Mmax;
}

Date::Date(const int y, const int m, const int d, const Time& t)
	: year(y), month(m), day(d), time(t)
{
	set_month_days();
	if (day > month_days)
		//day to max value;
		day = month_days;
	if (month > Mmax)
		//month to max value
		month = Mmax;
}

Date::Date(const Date& d) 
{
	year = d.year;
	month = d.month;
	day = d.day;
	time = d.time;
}

void Date::set_month_days()
{
	month_days = 30;
	for (int i = 0; i < M31days; i++)
		if (month == m31[i])
			month_days = 31;
	if (month == Mfeb)
		month_days = leap ? 28 : 29;
}

void Date::show() const
{
	time.show();
	cout << year << ' ' << month << ' ' << day;
}

ostream& operator<<(ostream& os, Date& d)
{
	os << d.year << '-' << d.month << '-' << d.day << ' ';
	os << d.time;
	return os;
}

Time operator-(const Date& d1, const Date& d2)
{
	Time temp;
	return temp;
}

bool Date::operator<(const Date& d)
{
	bool answ = true;

	if (year > d.year)
		answ = false;
	else if (year < d.year)
		answ = true;
	else
	{
		if (month > d.month)
			answ = false;
		else if (month < d.month)
			answ = true;
		else
		{
			if (day > d.day)
				answ = false;
			else if (day < d.day)
				answ = true;
			else
				answ = time < d.time;
		}
	}

	return answ;
}

bool operator==(const Date& d1, const Date& d2)
{
	if (d1.year == d2.year &&
		d1.month == d2.month &&
		d1.day == d2.day)
		return true;
	return false;
}

Date& Date::operator=(const Date& d)
{
	year = d.year;
	month = d.month;
	day = d.day;
	time = d.time;
	return *this;
}

int Date::get_days_from_maxy() const
{
	int total_days = 0;
	int m = Min_year;
	while (m++ < year )
	{
		Date temp(m, 12, 31, 23, 59);
		total_days += temp.get_days_from_start();
	}
	total_days += get_days_from_start();
	return total_days;
}

int Date::get_minutes_from_start() const
{
	return get_days_from_start() * 60 * 24 - time.get_total_min();
}

int Date::get_days_from_start() const
{
	int days = 0;
	bool is30d = true;
	for (int i = 0; i < month - 1; i++)
	{
		is30d = true;
		for (int j = 0; j < M31days; j++)
			if (i == m31[j])
			{
				days += 31;
				is30d = false;
			}		
		if (i == Mfeb)
		{ 
			days += (year % 4 == 0)? 29 : 28;
			is30d = false;
		}
		if (is30d)
			days += 30;
	}

	days += day;

	return days;
}