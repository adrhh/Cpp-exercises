#ifndef TAB_LUDZI_H_
#define TAB_LUDZI_H_

#include "Pracownik.h"

class Tablica_ludzi
{
private:
	Pracownik *tablica;
	long int dlugosc;
	int aktualne_wypelnienie;
public:
	Tablica_ludzi(long int dlugosc = 0);
	~Tablica_ludzi();
	void wypelnij();
	void modyfikuj(int i);
	int sprawdz(const char* imie, const char* nazw);
	void wyswietl() const;
	Tablica_ludzi(const Tablica_ludzi &wzorzec); 
	Tablica_ludzi & operator =(const Tablica_ludzi &wzorzec);
};

#endif // !TAB_LUDZI_H_
