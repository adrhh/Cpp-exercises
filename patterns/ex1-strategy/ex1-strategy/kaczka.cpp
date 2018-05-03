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

DzikaKaczka::DzikaKaczka()
{
	ptrKwakanie = new Kwacz();
	ptrLatanie = new UmiemLatac();
}

DzikaKaczka::~DzikaKaczka()
{
	delete ptrKwakanie;
	delete ptrLatanie;
}

void DzikaKaczka::pokazKaczke()
{
	cout << "jestem prawdziwa dzika kakczka" << endl;
}