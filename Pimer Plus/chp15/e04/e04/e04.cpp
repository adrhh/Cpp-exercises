#include <iostream>
#include "sales.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double vals1[12] =
	{
		1220, 1100, 1122, 212, 1232, 2334,
		2884, 2393, 3302, 2902, 3002, 2544
	};
	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1{ 2011, vals1, 12 };
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "pierwszy blok try:" << endl;
	try
	{
		int i;
		cout << "Rok = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Rok = " << sales2.Year() << endl;
		cout << "Etykieta = " << sales2.Label() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
	}
	catch(Sales::bad_index& err)
	{ 
		Sales::bad_index* e = &err;
		LabeledSales::nbad_index* ne;
		if (ne = dynamic_cast<LabeledSales::nbad_index*>(e))
			cout << ne->what();
		else
			cout << e->what();
	}

	try
	{
		sales2[20] = 37.5;
		sales1[11] = 23445;
	}
	catch (Sales::bad_index& err)
	{
		Sales::bad_index* e = &err;
		LabeledSales::nbad_index* ne;
		if (ne = dynamic_cast<LabeledSales::nbad_index*>(e))
			cout << ne->what();
		else
			cout << e->what();
	}

	try
	{
		sales2[2] = 37.5;
		sales1[111] = 23445;
	}
	catch (Sales::bad_index& err)
	{
		Sales::bad_index* e = &err;
		LabeledSales::nbad_index* ne;
		if (ne = dynamic_cast<LabeledSales::nbad_index*>(e))
			cout << ne->what();
		else
			cout << e->what();
	}

}