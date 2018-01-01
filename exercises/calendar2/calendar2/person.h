#ifndef PERSON_H_
#define PERSON_H_

#include <vector>
#include <algorithm>
#include "event.h"

using std::vector;
using std::find;

class Person
{
private:
	vector<Event*> e_list;
public:
	Person() {};
	friend class Todb;
	void add_event(Event* e);
	void delete_event(Event* e);
	void show_events() const;
};

void Person::add_event(Event* e)
{
	e_list.push_back(e);
}

void Person::delete_event(Event* e)
{
	auto it = find(e_list.begin(), e_list.end(), e);
	if (it != e_list.end())
		e_list.erase(it);
}

void Person::show_events() const
{
	for (auto e : e_list)
		e->show();
}

#endif // !PERSON_H_
