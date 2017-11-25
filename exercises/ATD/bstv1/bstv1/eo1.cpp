#include "bst.h"
#include <iostream>

using namespace std;

int main()
{
	int inttab[6] = { 1,5,7,2,3,3 };
	Bst test;
	for (int i = 0; i < 6; i++)
		test.insert(inttab[i]);


	test.in_order(test.get_root());
	test.delete_node(test.get_root());
	cout << endl;
	test.in_order(test.get_root());
	cout << endl;
	cout << test.get_key( test.find(3) )  << endl;

	return 0;
}