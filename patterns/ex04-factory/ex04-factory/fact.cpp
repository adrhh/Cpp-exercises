#include "fact.h"
#include <iostream>

using std::cout;
using std::endl;

WloskaWege::WloskaWege() 
{
	nazwa = "Wloska pizza wegeterianska";
	ciasto = "Cienkie kruche ciatso";
	sos = "Wloski sos pomidorowy";
	
	dodatki.push_back("Rukola");
	dodatki.push_back("Kapary");
}

WloskaPepperoni::WloskaPepperoni()
{
	nazwa = "Wloska pizza pepperoni";
	ciasto = "Cienkie kruche ciatso";
	sos = "Wloski sos pomidorowy";

	dodatki.push_back("Pepperoni");
	dodatki.push_back("Slodka papryka");
	dodatki.push_back("Czarne oliwki");
}

WloskaSerowa::WloskaSerowa()
{
	nazwa = "Wloska pizza serowa";
	ciasto = "Cienkie kruche ciatso";
	sos = "Wloski sos pomidorowy";

	dodatki.push_back("Ser Regiano");
}


Pizza Pizzeria::zamowPizza(string type)
{
	Pizza pizza = utworzPizza(type);
	pizza.przygotowanie();
	pizza.pieczenie();
	pizza.krojenie();
	pizza.pakowanie();

	return pizza;
}

Pizza WloskaPizzeria::utworzPizza(string type)
{
	if (type == "serowa")
		return WloskaSerowa();
	else if (type == "pepperoni")
		return WloskaPepperoni();
	else if (type == "wege")
		return  WloskaWege();
}

void Pizza::przygotowanie()
{
	cout << "Przygotowanie: " << nazwa << endl;
	cout << "Dotaki: ";
	for (int i = 0; i < dodatki.size(); i++)
	{
		cout << dodatki[i];
		if (i == dodatki.size() - 1)
			cout << endl;
		else
			cout << ", ";
	}
}

void Pizza::pieczenie()
{
	cout << "Piczenie 20 minut w 300 stopniach" << endl;
}
void Pizza::krojenie()
{
	cout << "Krojenie na 8 czesci" << endl;
}
void Pizza::pakowanie()
{
	cout << "Pakowanie w deykowane pudelko" << endl;
}