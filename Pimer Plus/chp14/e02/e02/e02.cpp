#include <iostream>
#include "wine.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	cout << "Podaj nazwe wina:" << endl;
	char lab[50];
	cin.getline(lab, 50);
	cout << "podaj liczbr rocznikow:" << endl;
	int yrs;
	cin >> yrs;

	Wine hold(lab, yrs);
	hold.GetBottles();
	hold.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };
	Wine more("Grape Red", YRS, y, b);
	more.Show();

	cout << "Wszytkich butelek: " << more.sum() + hold.sum() << endl;

	return 0;
}