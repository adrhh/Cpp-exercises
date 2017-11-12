#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>

using std::ostream;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void Addmin(int m);
	void Addhr(int h);
	void reset(int h, int m = 0);
	friend Time operator+(const Time &t1, const Time &t2);
	friend Time operator-(const Time &t1, const Time &t2);
	friend Time operator*(const Time &t, int n);
	friend Time operator*(int n, const Time &t)
	{
		return t*n;
	};
	friend ostream & operator<<(ostream &os, const Time &t);
};

#endif // !MYTIME_H_
