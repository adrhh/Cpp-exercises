#ifndef PRACOWNIK_H_
#define PRACOWNIK_H_

#include "Data.h"

class Pracownik
{
private:
	char* m_pszImie;
	char* m_pszNazwisko;
	Data m_DataUrodzenia;
public:
	Pracownik(const char * imie = "", const char * nazwisko = "");
	~Pracownik();
	const char* Imie() const { return  m_pszImie; }
	const char* Nazwisko() const { return m_pszNazwisko; }
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	bool SprawdzImie(const char* por_imie) const;
	bool SprawdzNazwisko(const char* por_nazwisko) const;
	Pracownik(const Pracownik &wzorzec); 
	Pracownik & operator =(const Pracownik & wzorzec);
	Pracownik & operator ==(const Pracownik & wzorzec);
};


#endif // !PRACOWNIK_H_
