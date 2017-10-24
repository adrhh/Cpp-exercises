/*Write a program that asks the user to enter his or her first name and then last
name, and that then constructs, stores, and displays a third string, consisting of the
user’s last name followed by a comma, a space, and first name. Use  char arrays and
functions from the  cstring header file.A sample run could look like this:
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip*/

#include <iostream>
#include <cstring>

const int MAXt = 40, MAX = 20;
using namespace std;

int main()
{
	char imie[MAX];
	char nazwisko[MAX];

	cout << "Podaj swoje imie: ";
	cin >> imie;
	cout << "Podaj swoje nazwisko: ";
	cin >> nazwisko;

	char napis[MAXt]; 
	strcpy_s(napis, nazwisko);
	strcat_s(napis, ", ");
	strcat_s(napis, imie);

	cout << "Oto informacja jako jeden napis: " << napis << endl;

	return 0;
}