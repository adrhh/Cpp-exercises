#ifndef PIZZAFACTORY_H_
#define PIZZAFACTORY

#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Skladnik
{
public:
	std::string opis;
	std::string getOpis() const
	{
		return opis;
	}
	Skladnik(std::string ops = "") : opis(ops) {}
};

class Ciasto : public Skladnik
{};

class CienkiChrupkieCIasto : public Ciasto
{
public:
	CienkiChrupkieCIasto()
	{
		opis = "cienkie chrupi¹ce ciasto idelane na wloska pizze";
	}
};

class Malze : public Skladnik
{};

class SwiezeMalze : public Malze
{
public:
	SwiezeMalze()
	{
		opis = "swieze malze, dopiero co wywlowione z morza";
	}
};

class Ser : public Skladnik
{};

class SerReggiano : public Ser
{
public:
	SerReggiano()
	{
		opis = "twardy dlugo dojrzewajacy parmezan";
	}
};

class Warzywa : public Skladnik
{};

class Czosnek : public Warzywa
{
public:
	Czosnek()
	{
		opis = "aromatyczny czosnek";
	}
};

class Pieczarki : public Warzywa
{
public:
	Pieczarki()
	{
		opis = "biale pieczarki idelane do pieczenia";
	}
};

class FabrykaSkladnikowPizzy
{
public:
	virtual ~FabrykaSkladnikowPizzy() {}
	virtual std::unique_ptr<Ciasto> tworzCiasto() const = 0;
	virtual std::unique_ptr<Ser> tworzSer() const = 0;
	virtual std::vector<Warzywa*> tworzWarzywa() const = 0;
	virtual std::unique_ptr<Malze> tworzMalze() const = 0;
};

class WloskaFabrykaSkladnikoPizzy : public FabrykaSkladnikowPizzy
{
public:
	//RAII test
	virtual std::unique_ptr<Ciasto> tworzCiasto() const override
	{
		return std::make_unique<CienkiChrupkieCIasto>();
	}
	virtual std::unique_ptr<Ser> tworzSer() const override
	{
		return std::make_unique<SerReggiano>();
	}
	virtual std::vector<Warzywa*> tworzWarzywa() const override
	{
		return std::vector<Warzywa*> {new Czosnek(), new Pieczarki()};
	}
	virtual std::unique_ptr<Malze> tworzMalze() const override
	{
		return std::make_unique<SwiezeMalze>();
	}
	virtual ~WloskaFabrykaSkladnikoPizzy() {};
};

class Pizza
{
public:
	std::string nazwa;
	std::unique_ptr<Ciasto> ciasto;
	std::unique_ptr<Ser> ser;
	std::unique_ptr<Malze> malze;
	virtual void przygotowanie() = 0;
	void pieczenie() const
	{
		std::cout << "Pieczenie: 25 minut w temperatourze 180 stopnie C.";
	}
};

class PizzaSerowa : public Pizza
{
	FabrykaSkladnikowPizzy* fabrykaSkladnikow;
public:
	PizzaSerowa(FabrykaSkladnikowPizzy* f) : fabrykaSkladnikow(f) {}
	virtual void przygotowanie() override
	{
		ciasto = fabrykaSkladnikow->tworzCiasto();
		ser = fabrykaSkladnikow->tworzSer();
	}
};

class PizzaOwoceMorza : public Pizza
{
	FabrykaSkladnikowPizzy* fabrykaSkladnikow;
public:
	PizzaOwoceMorza(FabrykaSkladnikowPizzy* f) : fabrykaSkladnikow(f) {}
	virtual void przygotowanie() override
	{
		ciasto = fabrykaSkladnikow->tworzCiasto();
		malze = fabrykaSkladnikow->tworzMalze();
	}
};

class Pizzeria
{
public:
	virtual std::unique_ptr<Pizza> utworzPizza(std::string nazwa) const = 0;
};

class WloskaPizzeria : public Pizzeria
{
private:
	FabrykaSkladnikowPizzy* fab;
public:
	WloskaPizzeria() : fab(new WloskaFabrykaSkladnikoPizzy()) {}
	~WloskaPizzeria()
	{
		delete fab;
	}
	virtual std::unique_ptr<Pizza> utworzPizza(std::string nazwa) const override
	{
		std::unique_ptr<Pizza> p(nullptr);

		if (nazwa == "serowa")
		{
			p = std::make_unique<PizzaSerowa>(PizzaSerowa(fab));

		}
		else if (nazwa == "owoce morza")
		{
			p = std::make_unique<PizzaOwoceMorza>(PizzaOwoceMorza(fab));
		}
		return p;
	}
};

#endif // !PIZZAFACTORY_H_
