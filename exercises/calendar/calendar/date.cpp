#include "date.h"

using std::cout;

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

void Time::add_min(int m)
{
	minutes += m;
	hours += minutes / Mmax;
	minutes %= Mmax;
	rest += hours / Hmax;
	hours %= Hmax;
}
void Time::add_hour(int h)
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




