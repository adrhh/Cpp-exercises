#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int choice;
	int const Limit = 100;
	int const Minlimit = 1;
	cout << "Podaj liczbe <1 - 100>" << endl;
	cin >> choice;

	while ( choice > Limit || choice < Minlimit)
	{
		cout << "Podaj prawidlowa liczbe <1 - 100>" << endl;
		cin >> choice;
	}

	int min_v = Minlimit;
	int max_v = Limit;
	int guess = (min_v + max_v) / 2;
	while (guess != choice)
	{
		cout << "moja proba: " << guess << endl;
		if (guess < choice)
			min_v = guess + 1;
		else
			max_v = guess - 1;
		guess = (min_v + max_v) / 2;
	}

	cout << "zgadlem! " << guess << " = " << choice << endl;

	return 0;
}