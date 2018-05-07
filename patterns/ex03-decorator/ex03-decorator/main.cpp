#include "dec.h"
#include <iostream>

using std::endl;
using std::cout;

int main()
{
	//Napoj* ptr = nullptr;
	{
	Napoj* napoj = new Espresso;
	cout << napoj->koszt() << " " << napoj->pobierzOpis() << endl;
	delete napoj;

	Napoj* napoj2 = new Espresso;
	cout << napoj2->koszt() << " " << napoj2->pobierzOpis() << endl;
	Napoj* napoj3 = new Czekolada(napoj2);
	cout << napoj3->koszt() << " " << napoj3->pobierzOpis() << endl;
	delete napoj2;
	delete napoj3;

	Napoj* napoj4 = new Palona;
	Napoj* napoj5 = new Czekolada(napoj4);
	Napoj* napoj6 = new Czekolada(napoj5);
	Napoj* napoj7 = new BitaSmietana(napoj6);
	cout << napoj7->koszt() << " " << napoj7->pobierzOpis() << endl;

	delete napoj4;
	delete napoj5;	
	delete napoj6;
	delete napoj7;
	}
	//cout << ptr->koszt() << endl;

	return 0;
}