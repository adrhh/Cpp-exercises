#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using std::ostream;

//hours and minutes
//24:60 max
class Time
{
private:
	enum {Hmax = 24};
	enum {Mmax = 60};
	int hours;
	int minutes;
	int rest = 0;
public:
	//default constructor
	Time(const int h = 0, const int m = 0);
	void add_min(int m);
	void add_hour(int h);
	void set(const int h, const int m);
	void show() const;
	int get_min() { return minutes; }
	int get_hour() { return hours; }
	Time& operator+=(const Time& t);
	friend ostream& operator<<(ostream& os, Time& t);
};

#endif // !DATE_H_
