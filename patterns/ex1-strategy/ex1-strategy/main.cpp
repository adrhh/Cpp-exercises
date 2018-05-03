#include "kaczka.h"

int main()
{
	Kaczka* dzika = new DzikaKaczka();
	dzika->pokazKaczke();
	dzika->wykonajKwacz();
	dzika->wykonajLec();
	dzika->wykonajPlywaj();

	Kaczka* sztuczna = new ModelKaczki();
	dzika->pokazKaczke();
	sztuczna->wykonajLec();
	sztuczna->ustawLatanie(new LatnieZRakieta());
	sztuczna->wykonajLec();

	delete dzika;
	delete sztuczna;

	return 0;
}