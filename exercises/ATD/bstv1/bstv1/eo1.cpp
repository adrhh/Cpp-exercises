#include "bst.h"
#include <iostream>

using namespace std;

int main()
{
	int inttab[7] = { 6,4,8,2,5,7,10 };
	Bst test;
	for (int i = 0; i < 7; i++)
		test.insert(inttab[i]);

	test.in_order(test.get_root());
	cout << endl;
	test.pre_order(test.get_root());
	cout << endl;
	test.post_order(test.get_root());
	cout << endl;
	test.delete_node(test.get_root());
	cout << endl;
	test.in_order(test.get_root());
	cout << endl;
	cout << test.get_key( test.find(7) )  << endl;
	test.delete_node(test.find(10));
	test.in_order(test.get_root());

	return 0;
}