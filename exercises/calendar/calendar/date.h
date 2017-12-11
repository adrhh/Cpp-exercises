#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using std::ostream;

//hours and minutes
//24:60 max
class Time
{
private:
	enum {Hmax = 24, Mmax = 60};
	int hours;
	int minutes;
	//only for + and *
	int rest = 0;
public:
	//default constructor
	Time(const int h = 0, const int m = 0);
	//copy construcotr
	Time(const Time& t);
	void add_min(const int m);
	void add_hour(const int h);
	void set(const int h, const int m);
	void show() const;
	int get_min() const { return minutes; }
	int get_hour() const { return hours; }
	int get_rest() const { return rest; }
	void set_rest(int n = 0) { rest = n; }
	int get_total_min() const;
	Time& operator+=(const Time& t);
	Time& operator-=(const Time& t);
	Time& operator*=(const int x);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend ostream& operator<<(ostream& os, Time& t);
};

class Date
{
private:
	enum {Mmax = 12, Leap_year = 4, M31days = 7};
	//31 days months
	const int m31[M31days] = { 1,3,5,7,8,10,12 };
	const int mfeb = 2;
	int year;
	int month;
	int day;
	bool leap;
	int month_days;
	Time time;
public:
	//default constructor
	Date(const int y = 0, const int m = 0, const int d = 0, const  int h = 0, const int min = 0);
	//set(const int y = 0, const int m = 0, const int d = 0, const int h = 0, const int min = 0);
	void set_leap() { leap = (year % Leap_year == 0) ? true : false; }
	void set_month_days();
};

#endif // !DATE_H_