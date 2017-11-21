#include "cd.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using std::cout;
using std::endl;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	perf = new char[strlen(s1) + 1];
	label = new char[strlen(s1) + 1];
	strcpy(perf, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	perf = new char[strlen(d.perf) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(perf, d.perf);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	perf = new char[1];
	label = new char[1];
	perf[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	cout << "Usunieto" << endl;
	delete[] perf;
	delete[] label;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;

	delete[] perf;
	delete[] label;

	perf = new char[strlen(d.perf) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(perf, d.perf);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

void Cd::report() const
{
	cout << "Muzyk: " << perf << endl;
	cout << "Wytwornia: " << label << endl;
	cout << "Liczba utworow: " << selections << endl;
	cout << "Dlugosc trwania [min]: " << playtime << endl;
}