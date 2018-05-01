#include "stack.h"
#include "list.h"
#include <iostream>

using namespace std;
void st1();
void st2();
void lt1();

int main()
{
	//st1();
	//lt1();
	//st2();

	return 0;
}

void st1()
{
	IntStackOnArrConstSizeChange testStack(5);
	for (int i = 0; i < 10; i++)
		testStack.push(i);

	int x;
	for (int i = 0; i < 10; i++)
	{
		x = testStack.pop();
		cout << x << endl;
	}

	try
	{
		x = testStack.pop();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
}

void lt1()
{
	IntListForward l1;
	for (int i = 0; i < 10; i++)
		l1.push_back(i);
	cout << l1[4] << endl;
	l1.insert(4, 10);
	cout << l1[4] << endl;
	cout << l1[5] << endl;
	cout << l1[6] << endl;
	cout << l1.pop_back() << endl;
	cout << l1.pop_back() << endl;
	cout << l1.find_value(5) << endl;
	l1.erase_at(6);
	cout << l1[6] << endl;
	l1[6] = 100;
	cout << l1[6] << endl;
}

void st2()
{
	IntStackAsForwardList testStack;
	for (int i = 0; i < 10; i++)
		testStack.push(i);
	int x;
	for (int i = 0; i < 10; i++)
	{
		x = testStack.pop();
		cout << x << endl;
	}
}