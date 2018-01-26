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
using std::ostream;

class Event
{
protected:
	enum { Minyear = 1900 };
	time_t e_time;
public:
	//default constructor
	Event(int year = 0, int month = 0, int day = 0, int hour = 0);
	//copy constructor
	Event(const Event& e);
	void set_time(int year=0, int month = 0, int day= 0, int hour = 0);
	string get_stime();

	friend ostream& operator<<(ostream& os, const Event& e);

	//virtual methodts
	virtual void show() const;
	virtual void add_item(const string& s, int quantity, float price) = 0;
};



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

	friend ostream& operator<<(ostream& os, const Shopping& s);
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


#endif // !EVENT_H_