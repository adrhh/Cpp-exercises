#define _CRT_SECURE_NO_WARNINGS
#include "stcok3.h"
#include <cstring>

using std::cout;
using std::endl;

Stock::Stock()
{
	char* s= "bez nazwy";
	company = new char[strlen(s) + 1];
	strcpy(company, s);

	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* s, long n, double pr)
{
	company = new char[strlen(s) + 1];
	strcpy(company, s);

	if (n < 0)
	{
		cout << "Liczba udzialow nie moze byc ujemna\n"
			"udziali zostalu ustalone na 0" << endl;
		shares = 0.0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(long num, double price)
{

	if (num < 0)
		cout << "Liczba udzialow nie moze byc ujemna\n"
			"Tranzackja przewana" << endl;
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
		cout << "Liczba udzialow nie moze byc ujemna\n"
		"Tranzackja przewana" << endl;
	else if (num > shares)
		cout << "Liczba udzialow do sprzedazy nie moze byc wieksza niz posiadana\n"
		"Tranzackja przewana" << endl;
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

ostream & operator<<(ostream& os, const Stock& st)
{
	os << "Spolka: " << st.company << endl
		<< "Liczba udzialow: " << st.shares << endl
		<< "Cena udzialu: " << st.share_val << endl
		<< "Laczna wartosc: " << st.total_val << endl;
	return os;

}
const Stock & Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}