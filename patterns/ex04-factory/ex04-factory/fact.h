#ifndef FACT_H_
#define FACT_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Pizza
{
protected:
	string nazwa;
	string ciasto;
	string sos;
	vector<string> dodatki;
public:
	void przygotowanie();
	void pieczenie();
	void krojenie();
	void pakowanie();
	string popierzNazwe() const { return nazwa; }
};

class WloskaSerowa : public Pizza
{
public:
	WloskaSerowa();
};

class WloskaPepperoni : public Pizza
{
public:
	WloskaPepperoni();
};

class WloskaWege : public Pizza
{
public:
	WloskaWege();
};

class AmerykanskaSerowa : public Pizza
{
public:
	AmerykanskaSerowa();
};

class AmerykanskaPepperoni : public Pizza
{
public:
	AmerykanskaPepperoni();
};

class AmerykanskaWege : public Pizza
{
public:
	AmerykanskaWege();
};

class Pizzeria
{
public:
	Pizza zamowPizza(string type);
	virtual Pizza utworzPizza(string type) = 0;
};

class WloskaPizzeria : public Pizzeria
{
	Pizza utworzPizza(string type);
};

class AmerykanskaPizzeria : public Pizzeria
{
	Pizza utworzPizza(string type);
};

#endif // !FACT_H_
