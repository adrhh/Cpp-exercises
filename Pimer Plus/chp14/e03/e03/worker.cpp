#include "worker.h"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

Worker::~Worker()
{
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Podaj numer id:" << endl;
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Data() const
{
	cout << "Id: " << id << endl;
	cout << "Imie i naziwsko: " << fullname << endl;
}

void Waiter::Set()
{
	cout << "Podaj imie i naziwsko kelnera:" << endl;
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Kategoria kelnera:" << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "Elegancja: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Podaj poziom elegenacji klenera: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

const char* Singer::pv[Singer::Vtypes] =
{
	"inna", "alt", "kontralt", "sopran", "bas", "baryton", "tenor"
};

void Singer::Set()
{
	cout << "Podaj imie i naziwsko piosenkarza:" << endl;
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Kategoria pisonekarza:" << endl;
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "Skala glosu: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Podaj nr skali glosu:" << endl;
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;

	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}

void SingingWaiter::Set()
{
	cout << "Podaj imie i naziwsko spiewajacego kelnera:" << endl;
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Kategoria spiewajcy kelner:" << endl;
	Worker::Data();
	Data();
}