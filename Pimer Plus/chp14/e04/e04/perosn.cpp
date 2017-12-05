#include "person.h"
#include <iostream>

using std::endl;
using std::cout;

const char* cv[Card::Colors] =
{ "kier", "pik", "karo", "trefl" };

ostream& operator<<(ostream& os, const Card& cd)
{
	os << cv[cd.color] << ' ' << cd.value;
	return os;
}

Person::Person(const char* n, const char* s)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	sname = new char[strlen(s) + 1];
	strcpy(sname, n);
}

Person::Person(const Person& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	sname = new char[strlen(p.sname) + 1];
	strcpy(sname, p.sname);
}


void Person::Show() const
{
	cout << "Imie: " << name << endl;
	cout << "Nazwisko: " << sname << endl;
}

void Gunslinger::Show() const
{
	Person::Show();
	cout << "Czas wyciagniecia rewolweru: " << get_rt() << endl;
	cout << "Liczba naciec na rewolwerze: " << marks << endl;
}