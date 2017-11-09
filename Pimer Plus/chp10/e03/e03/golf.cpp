#include <iostream>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;

Golf::Golf()
{
	char temp[LEN];
	int temp_hc;

	cout << "Podaj imie gracza" << endl;
	cin.getline(temp, LEN);
	cout << "Podaj handicap" << endl;
	cin >> temp_hc;
	cin.get();

	Golf temp_golf(temp, temp_hc);
	*this = temp_golf;

}
Golf::Golf(const char* name, int hc)
{
	strcpy_s(fullname, name);
	handicap = hc;
}
void Golf::showGolf() const
{
	cout << "Imie gracza: " << fullname << endl;
	cout << "Handicap: " << handicap << endl;
}