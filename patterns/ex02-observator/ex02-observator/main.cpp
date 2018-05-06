#include "obsv.h"

int main()
{
	DanePogodowe stacjaMeteo;
	WarunkiBiezaceWyswietl warunkiOb(&stacjaMeteo);
	StatystyczneWyswietl statystykaOb(&stacjaMeteo);

	stacjaMeteo.ustawOdczyt(24.6, 70, 1025);
	stacjaMeteo.ustawOdczyt(23.1, 80, 900);
	stacjaMeteo.ustawOdczyt(27, 60, 1002);

	return 0;
}