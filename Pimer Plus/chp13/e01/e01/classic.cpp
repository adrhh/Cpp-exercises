#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "classic.h"


using std::strlen;
using std::cout;
using std::endl;

Classic::Classic(const char* s0, const  char* s1, const  char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy(title, s0);
}

Classic::Classic(const char* s0, const Cd& cd) : Cd(cd)
{
	strcpy(title, s0);
}

Classic::Classic() : Cd()
{
	title[0] = '\0';
}

Classic::~Classic()
{

}


void Classic::report() const
{
	Cd::report();
	cout << "Tytul: " << title << endl;
}

