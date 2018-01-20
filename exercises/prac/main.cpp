#include "Pracownik.h"
#include "tab_ludzi.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

	//lab 3
	Data te;
	te.Wypisz();

	Tablica_ludzi test(10);

	cout << "wpisuj ludzi (q - zakoncz)";
	char ch;

	while (true)
	{
		test.wypelnij();
		cin.get(ch);
		if (ch == 'q')
			break;
		cout << "podaj koljengo pracwonika" << endl;
	}

	cout << "szukaj pracwonika" << endl;
	cout << "podaj imie i naziwsko" << endl;

	char imie[30];
	char nazwisko[30];

	cin >> imie >> nazwisko;
	
	cout << "idneks szukanego pracwonika:" << test.sprawdz(imie, nazwisko) << endl;

	return 0;
}
