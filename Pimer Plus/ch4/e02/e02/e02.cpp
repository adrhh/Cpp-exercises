/*Rewrite Listing 4.4, using the C++  string class instead of  char arrays.*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string imie;
	string deser;

	cout << "Jak masz na imie: ";
	cin >> imie;
	cout << "Jaki lubisz deser: ";
	cin >> deser;

	cout << "Mam dla Ciebie " << deser
		<< ", " << imie << endl;

	return 0;
}