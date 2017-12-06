#include "emp.h"

using std::cin;
using std::cout;
using std::endl;

void abstr_emp::SetAll()
{
	cout << "Podaj imie:" << endl;
	cin >> fname;
	cout << "Podaj nazwisko:" << endl;
	cin >> lname;
	cout << "Podaj zawod:" << endl;
	cin >> job;
}

void abstr_emp::ShowAll() const
{
	cout << "Imie: " << fname << endl;
	cout << "Nazwisko: " << lname << endl;
	cout << "zawod: " << job << endl;
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	const abstr_emp* ptr = &e;
	os << "Dane pracwonika:" << endl;
	ptr->ShowAll();
	return os;
}

abstr_emp::~abstr_emp()
{

}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Iloma pracownikami zarzdza:" << endl;
	cin >> inchargeof;
	while (cin.get() != '\n')
		continue;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Komu donosi:";
	cin >> reportsto;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Iloma pracownikami zarzdza:" << endl;
	cin >> InChargeOf();
	while (cin.get() != '\n')
		continue;
	cout << "Komu donosi:";
	cin >> ReportsTo();
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout <<  "Zarzadza: " << InChargeOf() << endl;
	cout << "Donosi na: " << ReportsTo();
}