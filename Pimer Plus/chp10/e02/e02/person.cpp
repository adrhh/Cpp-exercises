#include "person.h"

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	if (strlen(fn) > LIMIT)
		cout << "Zbyt dluga nazwa" << endl;
	else
		strcpy_s(fname, fn);
}

void Person::Show() const
{
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
	cout << lname << " " << fname << endl;
}