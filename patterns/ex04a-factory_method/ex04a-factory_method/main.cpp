#include "pizzafactory.h"

int main()
{
	Pizzeria* p = new WloskaPizzeria();
	std::unique_ptr<Pizza> pizza1 = p->utworzPizza("serowa");

	delete p;
	return 0;
}