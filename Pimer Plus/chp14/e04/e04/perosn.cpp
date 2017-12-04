#include "person.h"

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