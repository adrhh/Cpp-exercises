#include "kaczka.h"

int main()
{
	Kaczka* dzika = new DzikaKaczka();
	dzika->wykonajKwacz();
	dzika->wykonajLec();
	dzika->wykonajPlywaj();

	return 0;
}