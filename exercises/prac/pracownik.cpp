#include "Pracownik.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


Pracownik::Pracownik(const char * imie, const char * nazwisko) 
{
	Data temp;
	m_DataUrodzenia = temp;

	int ilen = strlen(imie);
	m_pszImie = new char[ilen + 1];
	strcpy(m_pszImie, imie);

	int nlen = strlen(nazwisko);
	m_pszNazwisko = new char[nlen + 1];
	strcpy(m_pszNazwisko, nazwisko);
}

Pracownik::~Pracownik()
{
	delete[] m_pszNazwisko;
	delete[] m_pszNazwisko;
}


void Pracownik::Imie(const char* nowe_imie)
{
	int len = strlen(nowe_imie);
	m_pszImie = new char[len + 1];
	strcpy(m_pszImie, nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	int len = strlen(nowe_nazwisko);
	m_pszNazwisko = new char[len + 1];
	strcpy(m_pszNazwisko, nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	cout << "Imie: " << m_pszImie
		<< "Nazwisko: " << m_pszNazwisko;
	m_DataUrodzenia.Wypisz();
}

bool Pracownik::SprawdzImie(const char* por_imie) const
{
	bool answ = false;
	if (!strcmp(m_pszImie, por_imie))
		answ = true;

	return answ;
}

bool Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	bool answ = false;
	if (!strcmp(m_pszNazwisko, por_nazwisko))
		answ = true;

	return answ;
}


void Pracownik::Wpisz()
{
	char temp_i[25];
	cout << "Podaj imie:" << endl;
	cin >> temp_i;
	Imie(temp_i);

	char temp_n[30];
	cout << "Podaj nazwisko:" << endl;
	cin >> temp_n;
	Nazwisko(temp_n);

	m_DataUrodzenia.Wpisz();
}

Pracownik::Pracownik(const Pracownik &wzorzec)
{
	m_pszImie = new char[strlen(wzorzec.m_pszImie) + 1];
	strcpy(m_pszImie, wzorzec.m_pszNazwisko);

	m_pszNazwisko = new char[strlen(wzorzec.m_pszNazwisko) + 1];
	strcpy(m_pszNazwisko, wzorzec.m_pszNazwisko);

	m_DataUrodzenia = wzorzec.m_DataUrodzenia;

}

Pracownik & Pracownik::operator =(const Pracownik & wzorzec)
{
	if (this == &wzorzec)
		return *this;

	delete[] m_pszImie;
	m_pszImie = new char[strlen(wzorzec.m_pszImie) + 1];
	strcpy(m_pszImie, wzorzec.m_pszNazwisko);

	delete[] m_pszNazwisko;
	m_pszNazwisko = new char[strlen(wzorzec.m_pszNazwisko) + 1];
	strcpy(m_pszNazwisko, wzorzec.m_pszNazwisko);

	m_DataUrodzenia = wzorzec.m_DataUrodzenia;
}
Pracownik & Pracownik::operator ==(const Pracownik & wzorzec)
{
	if (this == &wzorzec)
		return *this;
	Pracownik* temp = new Pracownik(wzorzec);
	return* temp;
}
