#include "prolg.h"

Prolg::Prolg()
{
	strcpy_s(name, "Prolg");
	satiety = 50;
}

Prolg::Prolg(const char str[20], int x)
{
	strcpy_s(name, str);
	satiety = x;
}

void Prolg::show() const
{
	cout << "Imie: " << name << endl;
	cout << "Sytosc: " << satiety << endl;
}

void Prolg::change(int x)
{
	satiety = x;
}