#include "wine.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Wine::Wine() : string("Brak"), years(0), Pair(ArrInt(), ArrInt())
{
}

Wine::Wine(const char*l, int y, const int yr[], const int bot[]) 
	: string("Brak"), years(y), Pair(ArrInt(yr, y), ArrInt(bot, y))
{
}

Wine::Wine(const char*l, int y) : string(l), years(y), Pair(ArrInt(0, y), ArrInt(0, y))
{
}

void Wine::GetBottles()
{
	if (years)
	{
		for (int i = 0; i < years; i++)
		{
			cout << "Podaj rocznik:" << endl;
			cin >> Pair::first()[i];
			cout << "Podaj lczbe butelek:" << endl;
			cin >> Pair::second()[i];
		}
	}
	else
		cout << "Btak rocznikow" << endl;
}


int Wine::sum()
{
	ArrInt& botref = Pair::second();
	return botref.sum();
}

void Wine::Show()
{
	cout << (string)*this << endl;
	cout << "Rocznik\t" << "butelki" << endl;
	for (int i = 0; i < years; i++)
		cout << "  " << Pair::first()[i]
		<< "\t\t" << Pair::second()[i] << endl;
}