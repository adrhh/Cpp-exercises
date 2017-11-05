/* Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type  int , argument is provided and is
nonzero, the function should print the string a number of times equal to the num-
ber of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it is
equal to the number of times the function has been called.) Yes, this is a silly func-
tion, but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works.*/

#include <iostream>

using namespace std;

void f1(const char* s, int n = 0);
int counter = 0;

int main()
{
	char *test = "test test";
	
	for (int i = 0; i < 5; i++)
		f1(test);
	cout << ::counter << endl;
	f1(test, 1);

	return 0;
}

void f1(const char* s, int n)
{
	
	if (!n)
	{
		cout << s << endl;
		::counter++;
	}
	else
		for (int j = 0; j < ::counter; j++)
			cout << s << endl;
}