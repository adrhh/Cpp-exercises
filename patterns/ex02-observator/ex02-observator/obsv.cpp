#include "obsv.h"

void DanePogodowe::zarestrujObserwtora(Obserwator* o)
{
	obserwatorzy.push_back(o);
}
void DanePogodowe::usunObserwatora(Obserwator* o)
{
	auto it = find(obserwatorzy.begin(), obserwatorzy.end(), o);
	obserwatorzy.erase(it, it);
}
void DanePogodowe::powiadomObserwatorow()
{
	for (auto it : obserwatorzy)
		it->aktualizajca(daneTemperatura, daneWilgotnosc, daneCisnienie);
}
void DanePogodowe::odczytZmiana()
{
	powiadomObserwatorow();
}
void DanePogodowe::ustawOdczyt(double temp, double wilg, double cisn)
{
	daneTemperatura = temp;
	daneWilgotnosc = wilg;
	daneCisnienie = cisn;
	odczytZmiana();
}

WarunkiBiezaceWyswietl::WarunkiBiezaceWyswietl(DanePogodowe* dane)
{
	danePogodowe = dane;
	danePogodowe->zarestrujObserwtora(this);
}
void WarunkiBiezaceWyswietl::wyswietl() const
{
	cout << "Warunki biezace, temperatura: " << temperatura
		<< " stopni C, wilgotnosc: " << wilgotnosc << " %" << endl;
}
void WarunkiBiezaceWyswietl::aktualizajca(double temp, double wilg, double cisn)
{
	temperatura = temp;
	wilgotnosc = wilg;
	wyswietl();
}

StatystyczneWyswietl::StatystyczneWyswietl(DanePogodowe* dane) : readings(0), minTemp(100), maxTemp(0)
{
	danePogodowe = dane;
	danePogodowe->zarestrujObserwtora(this);
}
void StatystyczneWyswietl::wyswietl() const
{
	cout << "Srednia/Max/Min " << tempSum / readings << "/"
		<< maxTemp << "/" << minTemp << endl;
}
void StatystyczneWyswietl::aktualizajca(double temp, double wilg, double cisn)
{
	readings++;
	tempSum += temp;
	if (temp > maxTemp) maxTemp = temp;
	if (temp < minTemp) minTemp = temp;
	wyswietl();
}