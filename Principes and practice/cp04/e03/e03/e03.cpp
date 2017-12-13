#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	vector <double> temps; //odleglosci
	double temp;

	cout << "Podawaj liczby (|by zkaonczyc)" << endl;
	while (cin >> temp)
		temps.push_back(temp);

	double sum = 0;
	for (int i = 0; i < temps.size(); i++)
		sum += temps[i];

	sort(temps.begin(), temps.end());
	double min_val = temps[0];
	double max_val = temps[temps.size()-1];
	double max_val_neigh = 0;
	double min_val_neigh = DBL_MAX;
	double sub_neigh;
	for (int i = 0; i < temps.size()-1; i++)
	{
		sub_neigh = abs(temps[i+1] - temps[i]);
		max_val_neigh = max_val_neigh < sub_neigh ? sub_neigh : max_val_neigh;
		min_val_neigh = min_val_neigh > sub_neigh ? sub_neigh : min_val_neigh;
	}

	cout << "srednia wszytkich lidzb wynosi: " << sum / temps.size() << endl;
	cout << "suma wszytkich liczb: " << sum << endl;
	cout << "najmniejsza roznica miedzy sasiadami: " << min_val_neigh << endl;
	cout << "najwieksza roznica miedzy sasiadami: " << max_val_neigh << endl;

	return 0;
}