#include <cstring>
#include <iostream>
#include "classic.h"
#define _CRT_SECURE_NO_WARNINGS


using std::strlen;
using std::cout;
using std::endl;

Classic::Classic(const char* s0, const  char* s1, const  char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	title = new char[strlen(s0) + 1];
	strcpy(title, s0);
}

Classic::Classic(const char* s0, const Cd& cd) : Cd(cd)
{
	title = new char[strlen(s0) + 1];
	strcpy(title, s0);
}

Classic::Classic() : Cd()
{
	title = new char[1];
	title[0] = '\0';
}

Classic::Classic(const Classic& c) : Cd(c)
{
	title = new char[strlen(c.title) + 1];
	strcpy(title, c.title);
}

Classic::~Classic()
{
	delete[] title;
}


void Classic::report() const
{
	Cd::report();
	cout << "Tytul: " << title << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	delete[] title;
	Cd::operator=(c);
	title = new char[strlen(c.title) + 1];
	strcpy(title, c.title);
	return *this;

}