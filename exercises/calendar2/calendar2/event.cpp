#include "event.h"

//convert time to string
string Event::get_stime()
{
	char buffer[30];
	ctime_s(buffer, sizeof buffer, &e_time);
	string answ = buffer;
	return answ;
}

Event::Event(int year, int month, int day, int hour)
{
	time(&e_time);
}

Event::Event(const Event& e)
{
	e_time = e.e_time;
}

ostream& operator<<(ostream& os, const Event& e)
{
	tm local_time;
	localtime_s(&local_time, &e.e_time );
	os << local_time.tm_year + Event::Minyear << '-'
		<< local_time.tm_mon + 1 << '-'
		<< local_time.tm_mday;

	return os;
}

ostream& operator<<(ostream& os, const Shopping& s)
{
	tm local_time;
	localtime_s(&local_time, &s.e_time);
	os << local_time.tm_year + Shopping::Minyear << '-'
		<< local_time.tm_mon + 1 << '-'
		<< local_time.tm_mday;

	return os;
}

void Event::set_time(int year, int month, int day, int hour)
{
	tm temp_time;
	localtime_s(&temp_time, &e_time);

	temp_time.tm_year = year - Minyear;
	temp_time.tm_mon = month;
	temp_time.tm_mday = day;
	temp_time.tm_hour = hour;

	e_time = mktime(&temp_time);
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
		total_price += get<0>(p.second) * get<1>(p.second);
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