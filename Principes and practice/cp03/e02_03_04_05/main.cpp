#include <iostream>

using namespace std;

int main()
{
	const float Mil_to_km = 1.609;
	float miles;

	cout << "podaj ilosc mil: " << endl;
	cin >> miles;
	cout << miles << " mil = " << miles*Mil_to_km << " km" << endl;

	int ival1, ival2;

	cout << "Podaj dwie liczby calkowite: " << endl;
	cin >> ival1 >> ival2;

	cout << ((ival1 > ival2) ? ival1 : ival2 ) << " jest wieksza" << endl;
	cout << ((ival1 < ival2) ? ival1 : ival2) << " jest mniejsza" << endl;
	cout << ival1 << " + " << ival2 << " = " << ival1 + ival2 << endl;
	cout << ival1 << " - " << ival2 << " = " << ival1 - ival2 << endl;
	cout << ival1 << " * " << ival2 << " = " << ival1 * ival2 << endl;
	cout << ival1 << " / " << ival2 << " = " << ival1 / ival2 << endl;

	float fval1, fval2;
	cout << "Podaj dwie liczby zmiennoprzecikowe: " << endl;
	cin >> fval1 >> fval2;

	cout << ((fval1 > fval2) ? fval1 : fval2) << " jest wieksza" << endl;
	cout << ((fval1 < fval2) ? fval1 : fval2) << " jest mniejsza" << endl;
	cout << fval1 << " + " << fval2 << " = " << fval1 + fval2 << endl;
	cout << fval1 << " - " << fval2 << " = " << fval1 - fval2 << endl;
	cout << fval1 << " * " << fval2 << " = " << fval1 * fval2 << endl;
	cout << fval1 << " / " << fval2 << " = " << fval1 / fval2 << endl;


	return 0;
}