/* Write a program that asks the user to enter his or her first name and then last
name, and that then constructs, stores, and displays a third string consisting of the
user’s last name followed by a comma, a space, and first name. Use  string objects
and methods from the  string header file.A sample run could look like this:
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string imie, nazwisko;

	cout << "Podaj swoje imie: ";
	cin >> imie;
	cout << "Podaj swoje nazwisko: ";
	cin >> nazwisko;

	string napis = nazwisko + ", " + imie;

	cout << "Oto informacja jako jeden napis: " << napis << endl;

	return 0;
}
