#ifndef OBSV_H_
#define OBSV_H_

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::find;
using std::endl;
using std::cout;

class Obserwator
{
public:
	virtual void aktualizajca(double temp, double wilg, double cisn) = 0;
};

class WyswietlElement
{
	virtual void wyswietl() const = 0;
};

class Podmiot
{
public:
	virtual void zarestrujObserwtora(Obserwator* o) = 0;
	virtual void usunObserwatora(Obserwator* o) = 0;
	virtual void powiadomObserwatorow() = 0;
};

class DanePogodowe : public Podmiot
{
private:
	vector<Obserwator*> obserwatorzy;
	double daneTemperatura;
	double daneWilgotnosc;
	double daneCisnienie;
public:
	DanePogodowe() {};
	void zarestrujObserwtora(Obserwator* o);
	void usunObserwatora(Obserwator* o);
	void powiadomObserwatorow();
	void odczytZmiana();
	void ustawOdczyt(double temp, double wilg, double cisn);
};

class WarunkiBiezaceWyswietl : public Obserwator, WyswietlElement
{
private:
	double temperatura;
	double wilgotnosc;
	DanePogodowe* danePogodowe;
public:
	WarunkiBiezaceWyswietl(DanePogodowe* dane);
	void wyswietl() const;
	void aktualizajca(double temp, double wilg, double cisn);
};

class StatystyczneWyswietl : public Obserwator, WyswietlElement
{
private:
	double maxTemp;
	double minTemp;
	double tempSum;
	int readings;
	DanePogodowe* danePogodowe;
public:
	StatystyczneWyswietl(DanePogodowe* dane);
	void wyswietl() const;
	void aktualizajca(double temp, double wilg, double cisn);
};



#endif // !OBSV_H_
