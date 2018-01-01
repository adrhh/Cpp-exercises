#include <iostream>
#include <vector>
#include "event.h"
#include "person.h"

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

	return 0;
}