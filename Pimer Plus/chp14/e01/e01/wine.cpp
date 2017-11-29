#include "wine.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Wine::Wine() : label("Brak"), years(0), yers_bottles(ArrInt(), ArrInt())
{
}

Wine::Wine(const char*l, int y, const int yr[], const int bot[]) : label(l), years(y), yers_bottles(ArrInt(yr,y), ArrInt(bot,y)) 
{
}

Wine::Wine(const char*l, int y) : label(l), years(y), yers_bottles(ArrInt(0,y), ArrInt(0,y))
{
}

void Wine::GetBottles()
{
	if (years)
	{
		for (int i = 0; i < years; i++)
		{
			cout << "Podaj rocznik:" << endl;
			cin >> yers_bottles.first()[i];
			cout << "Podaj lczbe butelek:" << endl;
			cin >> yers_bottles.second()[i];
		}
	}
	else
		cout << "Btak rocznikow" << endl;
}


int Wine::sum()
{
	ArrInt& botref = yers_bottles.second();
	return botref.sum();
}

void Wine::Show()
{
	cout << label << endl;
	cout << "Rocznik\t" << "butelki" << endl;
	for (int i = 0; i < years; i++)
		cout << "  " << yers_bottles.first()[i]
			 << "\t\t" << yers_bottles.second()[i] << endl;
}