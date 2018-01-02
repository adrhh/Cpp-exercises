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
	vector<Event*> list(3);
	list[0] = new Meeting;
	list[1] = new Meeting("test");
	list[2] = new Shopping;
	list[2]->add_item("ziemniaki", 10, 2.5);
	list[2]->add_item("papryka", 2, 10);
	list[0]->set_time(2016, 16, 10);
	for (auto e : list)
	{	
		e->show();
		cout << "\n--------------" << endl;
	}
	cout << list[1]->get_stime() << endl;

	Person test;
	test.add_event(list[0]);
	test.add_event(list[1]);
	test.show_events();
	
	try
	{
		Todb test1;
		test1.open_db("test.db");
		test1.make_columns();
		test1.add(test);
		
	}
	catch (Todb::db_err& e)
	{
		cout << e.what() << " : " << e.info() << endl;
	}

	return 0;
}


