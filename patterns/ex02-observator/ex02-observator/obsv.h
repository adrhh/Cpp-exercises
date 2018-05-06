#ifndef OBSV_H_
#define OBSV_H_

#include <vector>
#include <algorithm>

using std::vector;
using std::find;

class Obserwator
{
public:
	virtual void aktualizajca(double temp, double wilgotnosc, double cisnienie) = 0;
};

class WyswietlElement
{
	virtual void wyswietl() = 0;
};

class Podmiot
{
public:
	virtual void zarestrujObserwtora(Obserwator* o) = 0;
	virtual void usuunObserwatora(Obserwator* o) = 0;
	virtual void powiadomObserwatorow() = 0;
};

class DanePogodowe : public Podmiot
{
private:
	vector<Obserwator*> obserwatorzy;
	double temperatura;
	double wilgotnosc;
	double cisnienie;
public:
	DanePogodowe() {};
	void zarestrujObserwtora(Obserwator* o)
	{
		obserwatorzy.push_back(o);
	}
	void usuunObserwatora(Obserwator* o)
	{
		auto it = find(obserwatorzy.begin(), obserwatorzy.end(), o);
		obserwatorzy.erase(it, it);
	}
	void powiadomObserwatorow()
	{
		for (auto it : obserwatorzy)
			it->aktualizajca(temperatura, wilgotnosc, cisnienie);
	}
	void odczytZmiana()
	{
		powiadomObserwatorow();
	}

	void ustawOdczyt(double temp, double wilg, double cisn)
	{
		temperatura = temp;
		wilgotnosc = wilgotnosc;
		cisnienie = cisn;
	}
};

#endif // !OBSV_H_
