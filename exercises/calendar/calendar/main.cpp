#include <iostream>
#include "date.h"
#include "Arr.h"


using std::cout;
using std::endl;

int main()
{
	Time test(23, 59);
	test.show();
	Time test2(0, 20);
	test2.show();
	test += test2;
	test.show();
	test *= 2;
	test.show();
	Time test3;
	test3 = test2 + test;
	test3.show();

	const int size = 3;

	Arr<Time*> arr_test(size);
	
	arr_test[0] = &test;
	arr_test[1] = &test2;
	arr_test[2] = &test3;

	arr_test[1]->show();

	try
	{
		arr_test[4]->show();
	}
	catch(Arr<Time*>::index_err& e)
	{ 
		cout << e.what() << endl;
		cout << "indeks: " << e.get_index() << " jest nieporawny" << endl;
	}

	cout << arr_test.get_size() << endl;
	arr_test.pop_end();
	cout << arr_test.get_size() << endl;
	arr_test[1]->show();
	arr_test.push_back(&test);
	cout << arr_test.get_size() << endl;
	arr_test[2]->show();
	test.show();

	cout << "\n\n\n\n";

	Date d1(2017, 12, 14, test);
	d1.show();

	cout << '\n' << d1 << endl;
	cout << d1.get_days_from_start() << endl;

	return 0;
}

