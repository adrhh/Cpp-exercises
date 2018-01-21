#include "Data.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

void Data::Wypisz() const
{
	cout << m_nDzien << ' ' << m_nMiesiac << ' ' << m_nRok;
}

void Data::Wpisz()
{
	cout << "Podaj dzien:" << endl;
	cin >> m_nDzien;
	cout << "Podaj miesiac:" << endl;
	cin >> m_nMiesiac;
	cout << "Podaj rok:" << endl;
	cin >> m_nRok;

	Koryguj();
}

bool Data::Porownaj(const Data& wzor) const
{
	bool answ = false;
	if (m_nDzien == wzor.m_nDzien &&
		m_nMiesiac == wzor.m_nMiesiac &&
		m_nRok == wzor.m_nRok)
		answ = true;

	return answ;
}

void Data::Koryguj()
{
	bool przestepny = false;
	if (m_nRok % 4 == 0)
		przestepny = true;

	if (m_nMiesiac > m_nMaxmiesiace)
		m_nMiesiac = 12;

	int iledni = m_nMiesiace[m_nMiesiac - 1];

	if (m_nMiesiac == 2 && przestepny)
		iledni = 29;

	if (m_nDzien > iledni)
		m_nDzien = iledni;
}

Data::Data(const Data &wzorzec)
{
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
	Koryguj();
}

Data & Data::operator =(const Data & wzorzec)
{
	if (this == &wzorzec)
		return *this;
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
	Koryguj();
	return *this;
}

Data& Data::operator ==(const Data & wzorzec) 
{
	if (this == &wzorzec)
		return *this;
	Data* temp = new Data(wzorzec);
	return *temp;
}
