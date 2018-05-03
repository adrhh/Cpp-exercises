#include "kaczka.h"


void Kwacz::kwacz()
{
	cout << "Kwa Kwa!" << endl;
}

void NieKwacz::kwacz()
{
	cout << "<<Glucha cisza>>" << endl;
}

void Piszcz::kwacz()
{
	cout << "Pipipi piski" << endl;
}

void UmiemLatac::lec()
{
	cout << "ja latam!" << endl;
}

void NieUmiemLatac::lec()
{
	cout << "oj, nie umie latac!" << endl;
}

void LatnieZRakieta::lec()
{
	cout << "UUaaaa lece z napedem rakietowym" << endl;
}


void Kaczka::wykonajLec()
{
	ptrLatanie->lec();
}
void Kaczka::wykonajKwacz()
{
	ptrKwakanie->kwacz();
}
void Kaczka::wykonajPlywaj()
{
	cout << "wszytkie kaczki pywaja, nawet te sztuczne!" << endl;
}

void Kaczka::ustawLatanie(Latanie* lt)
{
	delete ptrLatanie;
	ptrLatanie = lt;
}
void Kaczka::ustawKwakanie(Kwakanie* kw)
{
	delete ptrKwakanie;
	ptrKwakanie = kw;
}

DzikaKaczka::DzikaKaczka()
{
	ptrKwakanie = new Kwacz();
	ptrLatanie = new UmiemLatac();
}

void DzikaKaczka::pokazKaczke()
{
	cout << "jestem prawdziwa dzika kakczka" << endl;
}

ModelKaczki::ModelKaczki()
{
	ptrKwakanie = new Piszcz();
	ptrLatanie = new NieUmiemLatac();
}


void ModelKaczki::pokazKaczke()
{
	cout << "jestem drewniana kaczka" << endl;
}