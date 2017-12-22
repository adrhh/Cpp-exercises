#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using std::ostream;

//hours and minutes
//24:60 max
//days only for add/sub
class Time
{
private:
	enum {Hmax = 24, Mmax = 60};
	int hours;
	int minutes;
	int days = 0;
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
	int get_rest() const { return days; }
	void set_rest(int n = 0) { days = n; }
	int get_total_min() const;
	Time& operator+=(const Time& t);
	Time& operator-=(const Time& t);
	Time& operator*=(const int x);
	Time& operator=(const Time& t);
	bool operator<(const Time& t);
	bool operator>(const Time& t);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend ostream& operator<<(ostream& os, Time& t);
};

class Date
{
private:
	enum {Mmax = 12, Leap_year = 4, M31days = 7, Mfeb = 2, Min_year = 2000};
	//31 days months
	const int m31[M31days] = { 1,3,5,7,8,10,12 };

	int year;
	int month;
	int day;
	Time time;

	bool leap;
	int month_days;
	void set_leap() { leap = (year % Leap_year == 0) ? true : false; }
	void set_month_days();
public:
	//default constructor
	Date(const int y = 0, const int m = 0, const int d = 0, const  int h = 0, const int min = 0);
	Date(const int y, const int m, const int d, const Time& t);
	Date(const Date& d);
	void show() const;
	//srat from Min_year = 2000
	int get_days_from_maxy() const;
	//strat 01.01.current year
	int get_minutes_from_start() const;
	int get_days_from_start() const;
	int get_day_name()const;
	bool operator<(const Date& d);
	Date& operator=(const Date& d);
	friend ostream& operator<<(ostream& os, Date& d);
	friend Time operator-(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
};

#endif // !DATE_H_