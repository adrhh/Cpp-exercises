#define _CRT_SECURE_NO_WARNINGS
#include "classic.h"
#include <cstring>
#include <iostream>


using std::strlen;
using std::cout;
using std::endl;

Classic::Classic(char* s0, char* s1, char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	int len = strlen(s0);
	title = new char[len + 1];
	strcpy(title, s0);
}

Classic::Classic(char* s0, const Cd& cd) : Cd(cd)
{
	int len = strlen(s0);
	title = new char[len + 1];
	strcpy(title, s0);
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

Classic::Classic() : Cd()
{
	title = new char[1];
	title[0] = '\0';
}