#include "sales.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace SALES
{
	Sales::Sales()
	{
		for (int i = 0; i < QART; i++)
		{
			cout << "Wypenij tablice sprzedazy, podaj element nr: "
				<< i + 1 << endl;
			cin >> sales[i];
		}

		double mint, maxt, av, total = 0L;
		mint = maxt = sales[0];
		for (int i = 0; i < QART; i++)
		{
			if (mint > sales[i])
				mint = sales[i];
			if (maxt < sales[i])
				maxt = sales[i];
			total += sales[i];
		}

		max = maxt;
		min = mint;
		avrg = total / (double)QART;
	}

	Sales::Sales(const double ar[], int n)
	{
		for (int i = 0; i < QART; i++)
			if (i < n)
				sales[i] = ar[i];
			else
				sales[i] = 0L;

		double mint, maxt, av, total = 0L;
		mint = maxt = sales[0];
		for (int i = 0; i < QART; i++)
		{
			if (mint > sales[i])
				mint = sales[i];
			if (maxt < sales[i])
				maxt = sales[i];
			total += sales[i];
		}

		max = maxt;
		min = mint;
		avrg = total / (double)QART;

	}

	void Sales::showSales()
	{
		for (int i = 0; i < QART; i++)
			cout << sales[i] << " ";
		cout << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
		cout << "srednia: " << avrg << endl;
	}
}