#ifndef EVENT_H_
#define EVENT_H_

#include <ctime>
#include <iostream>
#include <utility>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

class Event
{
private:
	enum { Minyear = 1900 };
	tm e_time;

public:
	Event(const string&s = "empty", int year = 0, int month = 0, int day = 0, int hour = 0);
	void set_time(int year=0, int month = 0, int day= 0, int hour = 0);
	virtual void show() const;
};


class Shopping : public Event
{
private:
	map<string, pair<int, float>> shopping_list;
public:
	Shopping() {};
	void add_item(const string& s, int quantity, float price);
	void show() const;
};

class Meeting : public Event
{
private:
	string place;
public:
	Meeting(const string& s="brak") : place(s) {}
	void show() const;
};

Event::Event(const string& s, int year, int month, int day, int hour) 
{
	e_time.tm_year = year;
	e_time.tm_mon = month;
	e_time.tm_mday = day;
	e_time.tm_hour = hour;
}

void Event::set_time(int year, int month, int day, int hour)
{
	e_time.tm_year = year;
	e_time.tm_mon = month;
	e_time.tm_mday = day;
	e_time.tm_hour = hour;
}

void Event::show() const
{
	cout << e_time.tm_year + Minyear;
}

void Shopping::add_item(const string& s, int quantity, float price)
{
	pair<int, float> temp(quantity, price);
	shopping_list.insert(pair<string, pair<int, float>>(s, temp));
}

void Shopping::show() const
{
	Event::show();
}

void Meeting::show() const
{
	Event::show();
	cout << place << endl;
}

#endif // !EVENT_H_