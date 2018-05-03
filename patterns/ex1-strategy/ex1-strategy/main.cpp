#include "kaczka.h"

int main()
{
	//ptr to check destructors;
	Latanie* ptrLt = nullptr;
	{
		Kaczka* dzika = new DzikaKaczka();
		dzika->pokazKaczke();
		dzika->wykonajKwacz();
		dzika->wykonajLec();
		dzika->wykonajPlywaj();


		Latanie* zRakieta = new LatnieZRakieta();
		ptrLt = zRakieta;
		ptrLt->lec();

		Kaczka* sztuczna = new ModelKaczki();
		dzika->pokazKaczke();
		sztuczna->wykonajLec();
		sztuczna->ustawLatanie(zRakieta);
		sztuczna->wykonajLec();

		delete dzika;
		delete sztuczna;
	}
	
	//ptrLt->lec(); OK! dost work becouse Kaczka's dectructor kill object
	return 0;
}