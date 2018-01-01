#include <iostream>
#include <vector>
#include "person.h"
#include "event.h"
#include "todb.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;



int main()
{
	vector<Event*> list(2);
	list[0] = new Shopping;
	list[1] = new Meeting;
	list[0]->set_time(120);
	for (auto e : list)
		e->show();

	Person test;
	test.add_event(list[0]);
	test.add_event(list[1]);
	test.show_events();

	Todb test1;
	test1.open_db("test.db");
	test1.make_columns();

	return 0;
}


