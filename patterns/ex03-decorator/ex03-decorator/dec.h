#ifndef DEC_H_
#define DEC_H_

#include <string>

using std::string;

class Napoj
{
protected:
	string opis;
public:
	virtual string pobierzOpis() const {return opis;}
	virtual double koszt() const = 0;
};

class NapojDekorator : public Napoj
{
	virtual string pobierzOpis() const = 0;
};

class Espresso : public Napoj
{
public:
	Espresso()
	{
		opis = "Kawa Espresso";
	}
	double koszt() const { return 1.99; }
};

class Bezkofeinowa : public Napoj
{
public:
	Bezkofeinowa() 	
	{
		opis = "Kawa Bezkofeinowa";
	}
	double koszt() const { return 2.09; }
};

class Palona : public Napoj
{
public:
	Palona() 
	{
		opis = "Kawa Palona";
	}
	double koszt() const { return 1.59; }
};

class Czekolada : public NapojDekorator
{
private:
	Napoj* napoj;
public:
	Czekolada(Napoj* n) : napoj(n) { }
	string pobierzOpis() const
	{
		return napoj->pobierzOpis() + " + czekolada";
	}
	double koszt() const
	{
		return napoj->koszt() + 0.5;
	}
};


class BitaSmietana : public NapojDekorator
{
private:
	Napoj* napoj;
public:
	BitaSmietana(Napoj* n) : napoj(n) { }
	string pobierzOpis() const
	{
		return napoj->pobierzOpis() + " + bita smietana";
	}
	double koszt() const
	{
		return napoj->koszt() + 1.0;
	}
};

#endif // !DEC_H_
