#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	vector <double> temps;
	double temp;

	cout << "Podawaj liczby (|by zkaonczyc)" << endl;
	while (cin >> temp)
		temps.push_back(temp);

	double sum = 0;
	for (int i = 0; i < temps.size(); i++)
		sum += temps[i];

	sort(temps.begin(), temps.end());
	double median;
	if (temps.size() % 2 != 0)
		median = temps[temps.size() / 2];
	else
	{
		median = temps[temps.size() / 2] + temps[temps.size() / 2 +1];
		median /= 2;
	}

	cout << "srednia podanych lidzb wynosi: " << sum / temps.size() << endl;
	cout << "mediana wynosi: " << median << endl;
}