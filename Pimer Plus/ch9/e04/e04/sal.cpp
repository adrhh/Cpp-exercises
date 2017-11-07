#include "sal.h"
#include <iostream>

using namespace SALES;
using std::cout;
using std::cin;
using std::endl;

void setSales(Sales & s, const double ar[], int n)
{
	for (int i = 0; i < QART; i++)
		if (i < n)
			s.sales[i] = ar[i];
		else
			s.sales[i] = 0L;

	double min, max, av, total = 0L;
	min = max = s.sales[0];
	for (int i = 0; i < QART; i++)
	{ 
		if (min > s.sales[i])
			min = s.sales[i];
		if (max < s.sales[i])
			max = s.sales[i];
		total += s.sales[i];
	}	

	s.max = max;
	s.min = min;
	s.avrg = total / (double)QART;
}
void setSales(Sales & s)
{
	for (int i = 0; i < QART; i++)
	{
		cout << "Wypenij tablice sprzedazy, podaj element nr: "
			<< i + 1 << endl;
		cin >> s.sales[i];
	}

	double min, max, av, total = 0L;
	min = max = s.sales[0];
	for (int i = 0; i < QART; i++)
	{
		if (min > s.sales[i])
			min = s.sales[i];
		if (max < s.sales[i])
			max = s.sales[i];
		total += s.sales[i];
	}

	s.max = max;
	s.min = min;
	s.avrg = total / (double)QART;

}
void showSales(const Sales & s)
{
	for (int i = 0; i < QART; i++)
		cout << s.sales[i] << " ";
	cout << endl;
	cout << "max: " << s.max << endl;
	cout << "min: " << s.min << endl;
	cout << "srednia: " << s.avrg << endl;
}
