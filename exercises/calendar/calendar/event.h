#ifndef EVENT_H_
#define EVENT_H_

#include "date.h"
#include <string>
#include <vector>

using std::string;

class Event
{
private:
	Date date;
public:
	Event() : date() {}
	virtual ~Event() {}
	virtual void show() const;
	virtual void set() = 0;
};

class Meeting : public Event
{
private:
	string place;
public:
	Meeting() : place(""), Event() {};
	virtual ~Meeting() {};
	virtual void show() const;
	string get_place() const { return place; }
};

class Shoping : public Event
{
private:


};

#endif // !EVENT_H_
