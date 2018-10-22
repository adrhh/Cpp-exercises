#include "rec.h"
#include <iostream>

using namespace std;
unsigned int Test::copies = 0;
unsigned int Test::counter = 0;
unsigned int Test::assigments = 0;

Test::Test(const Test& t) : x(t.x), y(t.y)
{
	copies++;
}

Test& Test::operator=(const Test& t)
{
	if (this != &t)
	{
		x = t.x;
		y = t.y;
	}
	assigments++;
	return *this;
}

Test Test::by_val(Test t)
{
	Test temp = t;
	return temp;
}

void Test::show_counters()
{
	cout << "counter: " << counter << endl;
	cout << "copies: " << copies << endl;
	cout << "assigments: " << assigments << endl;
}

void test()
{
	Test t1 = 2;
	Test t2(1);
	Test t3(2, 3);
	Test t4 = t3;  //copy
	t3 = t2;	
	Test t5 = t4.by_val(t3);

	Test::show_counters();
}
