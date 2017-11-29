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

	return 0;
}