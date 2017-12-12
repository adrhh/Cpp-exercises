#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	const int Gro_types = 6;
	int max_val = 0;
	int total = 0;
	int temp;
	string end;

	const string gro = "groszow";
	const string e1 = "ke", e23 = "ki", e4 = "ek";
	const string g1 = "jedno", g2 = "dwu", g5 = "pieco",
		g10 = "dziesiecio", g20 = "dwudziesto", g50 = "piedziesiecio";

	const string gro_arr[Gro_types] = { g1,g2,g5,g10,g20,g50 };
	const int gro_multiper[Gro_types] = { 1,2,5,10,20,50 };
	int gro_val[Gro_types];

	for (int i = 0; i < Gro_types; i++) 
	{
		cout << "Ile masz " << gro_arr[i] + gro + e4 << " ?" << endl;
		cin >> temp;
		gro_val[i] = temp;
		if (max_val < temp)
			max_val = temp;
		total += temp * gro_multiper[i];
	}

	while (max_val != 0)
		max_val /= 10;

	for (int i = 0; i < Gro_types; i++)
	{
		if(gro_val[i])
		{ 
		cout << "Masz " << std::setw(max_val) << gro_val[i] << ' ' + gro_arr[i] + gro;
		if (gro_val[i] == 1)
			cout << e1;
		else if (gro_val[i]%10 == 2 || gro_val[i]%10 == 3)
			cout << e23;
		else
			cout << e4;
		cout << endl;
		}
	}

	cout << "Lacznie masz " << total << " groszy(" << std::setprecision(2) <<(double) total / 100 << " zlotego)" << endl;


	return 0;
}