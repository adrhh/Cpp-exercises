#ifndef PIZZAFACTORY_H_
#define PIZZAFACTORY

#include <vector>
#include <string>

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
	virtual Ciasto* tworzCiasto() const = 0;
	virtual Ser* tworzSer() const = 0;
	virtual std::vector<Warzywa*> tworzWarzywa() const = 0;
	virtual Malze* tworzMalze() const = 0;
};

class WloskaFabrykaSkladnikoPizzy : public FabrykaSkladnikowPizzy
{
	virtual Ciasto* tworzCiasto() const override
	{
		return new CienkiChrupkieCIasto();
	}
	virtual Ser* tworzSer() const override
	{
		return new SerReggiano();
	}
	virtual std::vector<Warzywa*> tworzWarzywa() const override
	{
		return std::vector<Warzywa*> {new Czosnek(), new Pieczarki()};
	}
	virtual Malze* tworzMalze() const override
	{
		return new SwiezeMalze();
	}
};

#endif // !PIZZAFACTORY_H_
