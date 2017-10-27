/*Write a program that matches the description of the program in Programming
Exercise 8, but use a  string class object instead of an array. Include the  string
header file and use a relational operator to make the comparison test.*/

#include <string>
#include <iostream>

using namespace std;

int main()
{
	const int MAX = 20;
	const string done = "done";
	string word;
	int counter = 0;

	cout << "Enter words (to stop, type the word done):" << endl;
	cin >> word;
	while (!(word==done))
	{
		cout << "Enter words(to stop, type the word done): " << endl;
		cin >> word;
		counter++;
	}

	cout << "You entered a total of " << counter << " words" << endl;

	return 0;
}