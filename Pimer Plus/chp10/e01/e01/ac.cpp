#include "ac.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Bank_acc::Bank_acc(const string str, const int n, const double val)
{
	name = str;
	nr = n;
	total = val;
}

void Bank_acc::show() const
{
	cout << "Imie wlsaciciela: " << name << endl;
	cout << "Nr konta: " << nr << endl;
	cout << "Stan konta " << total << endl;
}

void Bank_acc::add(double n)
{
	total += n;
}

void Bank_acc::pop(double n)
{
	if (n > total)
		cout << "Nie mozesz wybrac kownty wiekszej niz stan konta" << endl;
	else
		total -= n;
}