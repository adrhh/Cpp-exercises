#include "fact.h"
#include <iostream>
#include <memory>

using std::endl;
using std::cout;
using std::unique_ptr;

int main()
{
	unique_ptr<Pizzeria> wloska(new WloskaPizzeria);
	unique_ptr<Pizzeria> amerykanska(new AmerykanskaPizzeria);

	Pizza pizza = wloska->zamowPizza("serowa");
	cout << "zamowiles: " << pizza.popierzNazwe() << endl << endl;

	pizza = amerykanska->zamowPizza("wege");
	cout << "zamowiles: " << pizza.popierzNazwe() << endl;

	return 0;
}