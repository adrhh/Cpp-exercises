#include "pizzafactory.h"

int main()
{
	Pizzeria* p = new WloskaPizzeria();
	{
		std::unique_ptr<Pizza> pizza1 = p->utworzPizza("serowa");
		std::cout << pizza1->getName() << std::endl;
		std::cout << pizza1->getCiasto() << std::endl;
		std::cout << pizza1->getSer() << std::endl;
		std::cout << std::endl << std::endl;
	}
	
	std::unique_ptr<Pizza> pizza2 = p->utworzPizza("owoce");
	std::cout << pizza2->getName() << std::endl;
	std::cout << pizza2->getCiasto() << std::endl;
	std::cout << std::endl << std::endl;
	delete p;

	p = new AmerykanskaPizzeria();
	std::unique_ptr<Pizza> pizza1 = p->utworzPizza("serowa");

	std::cout << std::endl << std::endl;
	std::cout << pizza1->getName() << std::endl;
	std::cout << pizza1->getCiasto() << std::endl;
	std::cout << pizza1->getSer() << std::endl;
	std::cout << std::endl << std::endl;

	delete p;
	return 0;
}