#include <vector>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main()
{
	const double M_to_cm = 100;
	const double Foot_to_inch = 12;
	const double Cm_to_m = 1 / M_to_cm;
	const double Inch_to_cm = 2.54;

	const vector <string> units{ "cm", "m", "inch", "foot" };
	vector <double> all_val;
	double total = 0;
	double din = 0;
	double max = DBL_MIN;
	double min = DBL_MAX;
	double val_in_meters = 0;
	string sin = "";

	cout << "Podaj liczbe wraz z jednostka (| zakoncz)" << endl;
	while (cin >> din)
	{
		bool flag = false;
		cout << "Podaj jednostke" << endl;
		cin >> sin;
		for (int i = 0; i < units.size(); i++)
			if (sin == units[i])
			{	
				flag = true;
				break;
			}
				
		if (!flag)
		{
			cout << "podaj poprawna jednostke [cm, m, inch, foot]" << endl;
			continue;
		}
		// cm
		if (sin == units[0]) 
		{
			val_in_meters = din * Cm_to_m;
			cout << din << units[0] << endl;
		}
		//inch
		else if (sin == units[1])
		{
			val_in_meters = din;
			cout << din << units[1] << endl;
		}
		//m
		else if (sin == units[2])
		{
			val_in_meters = din* Inch_to_cm * Cm_to_m;
			cout << din << units[2] << endl;
		}
		//foot
		else if (sin == units[3])
		{
			val_in_meters = din * Foot_to_inch * Inch_to_cm * Cm_to_m;
			cout << din << units[3] << endl;
		}
		if (min > val_in_meters)
		{
			cout << "to najmniejsza podana wartosc w [m]: " << val_in_meters << endl;
			min = val_in_meters;
		}
		if (max < val_in_meters)
		{
			cout << "to najwieksza podana wartosc w [m]: " << val_in_meters << endl;
			max = val_in_meters;
		}
		all_val.push_back(val_in_meters);
	}

	cout << "wysztkie wartosci w metrach" << endl;
	for (int i = 0; i < all_val.size(); i++)
		cout << all_val[i] << ' ';
	cout << endl;

	sort(all_val.begin(), all_val.end());
	cout << "wysztkie posrtowane wartosci w metrach" << endl;
	for (int i = 0; i < all_val.size(); i++)
		cout << all_val[i] << ' ';
	cout << endl;

	return 0;
}