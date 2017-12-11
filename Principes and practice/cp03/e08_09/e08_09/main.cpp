#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int iin;
	cout << "Podaj liczbe calkowita:" << endl;
	cin >> iin;
	string even = (iin % 2 == 0) ? "parzysta" : "nie parzysta";
	cout << iin << " jest " << even << endl;

	cout << "Podaj liczbe od 0 do 4: " << endl;
	cin >> iin;
	string liczba;

	if (iin == 0)
		liczba = "zero";
	else if (iin == 1)
		liczba == "jeden";
	else if (iin == 2)
		liczba == "dwa";
	else if (iin == 3)
		liczba = "trzy";
	else if (iin == 4)
		liczba = "cztery";
	else
		liczba = "Glupi komputer";

	cout << iin << " = " << liczba << endl;

	return 0;
}