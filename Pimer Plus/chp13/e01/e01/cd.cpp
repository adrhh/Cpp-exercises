#include "cd.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy_s(perf, s1);
	strcpy_s(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy_s(perf, d.perf);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	perf[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	cout << "Usunieto" << endl;
}

void Cd::report() const
{
	cout << "Muzyk: " << perf << endl;
	cout << "Wytwornia: " << label << endl;
	cout << "Liczba utworow: " << selections << endl;
	cout << "Dlugosc trwania [min]: " << playtime << endl;
	cout << endl;
}

