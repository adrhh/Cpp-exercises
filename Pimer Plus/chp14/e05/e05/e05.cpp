#include <iostream>
#include "emp.h"

using namespace std;

int main()
{
	employee em("Tadeusz", "Hubert", "Sprzedawca");
	cout << em << endl;
	em.ShowAll();

	manager ma("Zbigniew", "Zboj", "Malarz", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Maurycy", "Okulksi", "Hydraulik", "Julian Bar");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Jan Kudlaty");
	cout << hf << endl;
	hf.ShowAll();

	return 0;
}