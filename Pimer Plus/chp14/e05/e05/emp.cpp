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

void manager::SetAll()
{
	abstr_emp::SetAll();
	cin >> inchargeof;
	while (cin.get() != '\n')
		continue;
}