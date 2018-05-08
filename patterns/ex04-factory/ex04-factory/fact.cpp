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

AmerykanskaWege::AmerykanskaWege()
{
	nazwa = "Amerykanska pizza wegeterianska";
	ciasto = "Grube ciatso";
	sos = "Sos amerykanski";

	dodatki.push_back("Ananas");
	dodatki.push_back("Oliwki");
	dodatki.push_back("Kukurydza");
	dodatki.push_back("Czerwona Cebula");
}

AmerykanskaPepperoni::AmerykanskaPepperoni()
{
	nazwa = "Amerykanska pizza pepperoni";
	ciasto = "Grube ciatso";
	sos = "Sos amerykanski";

	dodatki.push_back("Pepperoni");
	dodatki.push_back("Papryka jalepeno");
}

AmerykanskaSerowa::AmerykanskaSerowa()
{
	nazwa = "Amerykanska pizza serowa";
	ciasto = "Grube ciatso";
	sos = "Sos amerykanski";

	dodatki.push_back("Ser Parmezan");
	dodatki.push_back("Ser Gouda");
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

Pizza AmerykanskaPizzeria::utworzPizza(string type)
{
	if (type == "serowa")
		return AmerykanskaSerowa();
	else if (type == "pepperoni")
		return AmerykanskaPepperoni();
	else if (type == "wege")
		return  AmerykanskaWege();
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