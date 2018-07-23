#ifndef PIZZAFACTORY_H_
#define PIZZAFACTORY

#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Skladnik
{
	std::string opis;
public:
	std::string getOpis() const
	{	
		return opis; 
	}
	void setOpis(std::string str)
	{	
		opis = str; 
	}

	Skladnik(std::string ops = "brak") : opis(ops) 
	{
		std::cout << "skladnik utworzono\n";
	}
	virtual ~Skladnik() //virtual VERY important to delete derived objects
	{ 
		std::cout << "skladnik usunieto\n";
	}
};

class Ciasto : public Skladnik
{
public:
	Ciasto()
	{
		std::cout << "ciasto utworzono\n";
	}
	~Ciasto()
	{
		std::cout << "ciasto usunieto\n";
	}
};

class CienkiChrupkieCIasto : public Ciasto
{
public:
	CienkiChrupkieCIasto()
	{
		setOpis("cienkie chrupiace ciasto idelane na wloska pizze");
		std::cout << "cienkie ciasto utworzono\n";
	}
	~CienkiChrupkieCIasto()
	{
		std::cout << "cienkie ciasto usunieto\n";
	}
};

class Malze : public Skladnik
{
public:
	Malze()
	{
		std::cout << "mazle utworzono\n";
	}
	~Malze()
	{
		std::cout << "malze usunieto\n";
	}
};

class SwiezeMalze : public Malze
{
public:
	SwiezeMalze()
	{
		setOpis("swieze malze, dopiero co wywlowione z morza");
		std::cout << "swieze mazle utworzono\n";
	}
	~SwiezeMalze()
	{
		std::cout << "swieze mazle usunieto\n";
	}
};

class Ser : public Skladnik
{
public:
	Ser()
	{
		std::cout << "ser utworzono\n";
	}
	~Ser()
	{
		std::cout << "ser usunieto\n";
	}
};

class SerReggiano : public Ser
{
public:
	SerReggiano()
	{
		setOpis("twardy dlugo dojrzewajacy parmezan");
		std::cout << "ser parmezan utworzono\n";
	}
	~SerReggiano()
	{
		std::cout << "ser parmezan usunieto\n";
	}
};

class Warzywa : public Skladnik
{};

class Czosnek : public Warzywa
{
public:
	Czosnek()
	{
		setOpis("aromatyczny czosnek");
	}
};

class Pieczarki : public Warzywa
{
public:
	Pieczarki()
	{
		setOpis("biale pieczarki idelane do pieczenia");
	}
};

class FabrykaSkladnikowPizzy
{
public:
	virtual ~FabrykaSkladnikowPizzy() {}
	virtual std::unique_ptr<Ciasto> tworzCiasto() const = 0;
	virtual std::unique_ptr<Ser> tworzSer() const = 0;
	virtual std::vector< std::unique_ptr<Warzywa>> tworzWarzywa() const = 0;
	virtual std::unique_ptr<Malze> tworzMalze() const = 0;
};

class WloskaFabrykaSkladnikoPizzy : public FabrykaSkladnikowPizzy
{
public:
	virtual std::unique_ptr<Ciasto> tworzCiasto() const override
	{
		return std::make_unique<CienkiChrupkieCIasto>();
	}
	virtual std::unique_ptr<Ser> tworzSer() const override
	{
		return std::make_unique<SerReggiano>();
	}
	virtual std::vector< std::unique_ptr<Warzywa>> tworzWarzywa() const override
	{
		return std::vector< std::unique_ptr<Warzywa>>{};// {std::make_unique<Czosnek>(), std::make_unique<Pieczarki>()};
	}
	virtual std::unique_ptr<Malze> tworzMalze() const override
	{
		return std::make_unique<SwiezeMalze>();
	}
	virtual ~WloskaFabrykaSkladnikoPizzy() {};
};

class Pizza
{
protected:
	std::string nazwa;
	std::unique_ptr<Ciasto> ciasto;
	std::unique_ptr<Ser> ser;
	std::unique_ptr<Malze> malze;
public:
	virtual void przygotowanie() = 0;
	void pieczenie() const
	{
		std::cout << "Pieczenie: 25 minut w temperatourze 180 stopnie C.";
	}
	void setName(std::string str)
	{
		nazwa = str;
	}
	std::string getName() const
	{
		return nazwa;
	}
	std::string getCiasto() const
	{
		return ciasto->getOpis();
	}
	std::string getSer() const
	{
		return ser->getOpis();
	}
};

class PizzaSerowa : public Pizza
{
	FabrykaSkladnikowPizzy* fabrykaSkladnikow;
public:
	PizzaSerowa(FabrykaSkladnikowPizzy* f) : fabrykaSkladnikow(f) 
	{
		setName("Wloska Pizza serowa");
	}
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
			p->przygotowanie();

		}
		else if (nazwa == "owoce")
		{
			p = std::make_unique<PizzaOwoceMorza>(PizzaOwoceMorza(fab));
			p->przygotowanie();
		}
		return p;
	}
};

#endif // !PIZZAFACTORY_H_
