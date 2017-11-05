/*Write a function that takes a reference to a  string object as its parameter and that
converts the contents of the  string to uppercase. Use the  toupper() function
described in Table 6.4 of Chapter 6.Write a program that uses a loop which allows
you to test the function with different input.A sample run might look like this:
Enter a string (q to quit): go away
GO AWAY
Next string (q to quit): good grief!
GOOD GRIEF!
Next string (q to quit): q
Bye.*/

#include <iostream>
#include <string>

using namespace std;

void toup(string &);

int main()
{
	string test;
	cout << "Podaj lancuch, q by zakonczyc" << endl;
	getline(cin, test);
	while (!(test == "q"))
	{
		toup(test);
		cout << test << endl;
		cout << "Podaj kolejny lancuch:" << endl;
		getline(cin, test);
	}

	return 0;
}

void toup(string &str)
{
	int n = size(str);
	for (int i = 0; i < n; i++)
		str[i]=toupper(str[i]);
}