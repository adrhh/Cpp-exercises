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
	static int person_counter;
	int person_id;
	string fname;
	string sname;
	vector<Event*> e_list;
public:
	Person(const string& f = "brak", const string& s = "brak");
	friend class Todb;
	void add_event(Event* e);
	void delete_event(Event* e);
	void show_events() const;
	string get_name() const { return fname; }
	friend ostream& operator<<(ostream& os, const Person& p);

};

#endif // !PERSON_H_
