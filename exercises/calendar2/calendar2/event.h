#ifndef EVENT_H_
#define EVENT_H_

#include <ctime>
#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::for_each;
using std::get;
using std::cerr;

class Event
{
private:
	enum { Minyear = 1900 };
protected:
	time_t e_time;
public:
	Event(int year = 0, int month = 0, int day = 0, int hour = 0);
	void set_time(int year=0, int month = 0, int day= 0, int hour = 0);
	string get_stime();

	//virtual methodts
	virtual void show() const;
	virtual void add_item(const string& s, int quantity, float price) = 0;
};

//convert time to string
string Event::get_stime()
{
	char buffer[30];
	ctime_s(buffer, sizeof buffer, &e_time);
	string answ = buffer;
	return answ;
}

class Shopping : public Event
{
private:
	float total_price;
	map<string, pair<int, float>> shopping_list;
	void set_total();
public:
	//default total price = 0
	Shopping() : Event(), total_price(0) {} 
	void add_item(const string& s, int quantity, float price);
	void show() const;

};

class Meeting : public Event
{
private:
	string place;
public:
	Meeting(const string& s="brak") : place(s), Event() {}
	void show() const;

	virtual void add_item(const string& s, int quantity, float price) {};
};

Event::Event(int year, int month, int day, int hour) 
{
	time(&e_time);
}

void Event::set_time(int year, int month, int day, int hour)
{
	tm temp_time;
	localtime_s(&temp_time, &e_time);

	temp_time.tm_year = year - Minyear;
	temp_time.tm_mon = month;
	temp_time.tm_mday = day;
	temp_time.tm_hour = hour;

	e_time= mktime(&temp_time);
}

void Event::show() const
{
	tm local_time;
	localtime_s(&local_time, &e_time);
	cout << local_time.tm_year + Minyear << '-'
		 << local_time.tm_mon + 1 << '-'
		 << local_time.tm_mday;
}

void Shopping::set_total()
{
	//get quantity and price value from pair in map
	//for each item in shoping_list:
	//total_price += item quantity * item price
	for (auto p : shopping_list)
	{ 
		total_price += get<0>(p.second) * get<1>(p.second);  															 
	}													     
}

void Shopping::add_item(const string& s, int quantity, float price)
{
	pair<int, float> temp(quantity, price);
	shopping_list.insert(pair<string, pair<int, float>>(s, temp));

	//set new total
	total_price = 0;
	set_total(); 
}

void Shopping::show() const
{
	Event::show();
	for (auto p : shopping_list)
		cout << p.first << " : " << get<0>(p.second) << " " << get<1>(p.second);
	cout << "lacznie do zaplaty: " << total_price;
}

void Meeting::show() const
{
	Event::show();
	cout << place;
	cout << "meeting " << endl;
}

#endif // !EVENT_H_