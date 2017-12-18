
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
		rest += hours / Hmax;
		hours %= Hmax;
	}
}

Time::Time(const Time& t)
{
	int min = t.minutes;
	int hou = t.hours;
	int res = t.rest;
	this->set(hou, min);
	rest += res;
}

void Time::set(const int h, const int m)
{
	hours = h;
	minutes = m;
	rest = 0;
	if (minutes >= Mmax)
	{
		minutes %= Mmax;
		hours += m / Mmax;
	}
	if (hours >= Hmax)
	{
		rest += hours / Hmax;
		hours %= Hmax;
	}
}

void Time::add_min(const int m)
{
	minutes += m;
	hours += minutes / Mmax;
	minutes %= Mmax;
	rest += hours / Hmax;
	hours %= Hmax;
}
void Time::add_hour(const int h)
{
	hours += h;
	rest += hours / Hmax;
	hours %= Hmax;
}

Time& Time::operator+=(const Time& t)
{
	rest += t.rest;
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
	cout << rest << ' ' << hours
		 << ' ' << minutes << ' ';
}

ostream& operator<<(ostream& os, Time& t)
{
	os << t.hours << " : " << t.minutes << ' ';
	return os;
}

int Time::get_total_min() const
{
	// rest not included
	return  minutes + hours*Mmax;
}

Time operator+(const Time& t1, const Time& t2)
{
	int temp_m = t1.minutes + t2.minutes;
	int temp_h = t1.hours + t2.hours;
	int temp_r = t1.rest + t2.rest;
	Time temp_t(temp_h, temp_m);
	temp_t.rest += temp_r;
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

// Date methods
//****************************************************

Date::Date(const int y, const int m, const int d, const  int h, const int min) : year(y), month(m), day(d), time(h, min)
{

}

void Date::set_month_days()
{
	month_days = 30;
	for (int i = 0; i < M31days; i++)
		if (month == m31[i])
			month_days = 31;
	if (month = 2)
		month_days = leap ? 28 : 29;
}

