/*
Write a C++ program that uses three user-defined functions (counting  main() as
one) and produces the following output:
Three blind mice
Three blind mice
See how they run
See how they run
One function, called two times, should produce the first two lines, and the remain-
ing function, also called twice, should produce the remaining output.
*/

#include <iostream>

using namespace std;

void fun1();
void fun2();

int main()
{
	fun1();
	fun1();
	fun2();
	fun2();

	return 0;
}

void fun1()
{ cout << "Three blind mice" << endl; }

void fun2()
{ cout << "See how they run" << endl; }