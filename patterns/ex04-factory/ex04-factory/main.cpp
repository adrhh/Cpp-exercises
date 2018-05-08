#include "fact.h"
#include <iostream>
#include <memory>

using std::endl;
using std::cout;
using std::unique_ptr;

int main()
{
	unique_ptr<Pizzeria> wloska(new WloskaPizzeria);

	Pizza pizza = wloska->zamowPizza("serowa");
	cout << "zamowiles: " << pizza.popierzNazwe() << endl;


	return 0;
}