#include "person.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;

const char* cv[Card::Colors] =
{ "kier", "pik", "karo", "trefl" };

ostream& operator<<(ostream& os, const Card& cd)
{
	os << cv[cd.color] << ' ' << cd.value;
	return os;
}

Deck::Deck()
{
	int k = 0;
	while (k < Maxsize)
	{
		for (int i = 0; i < Card::Colors; i++)
			for (int j = 0; j < Card::Maxvalue; j++)
				deck[k++] = Card(j, i);
	}
}

Person::Person(const char* n, const char* s)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	sname = new char[strlen(s) + 1];
	strcpy(sname, n);
}

Person::Person(const Person& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	sname = new char[strlen(p.sname) + 1];
	strcpy(sname, p.sname);
}


void Person::Show() const
{
	cout << "Imie: " << name << endl;
	cout << "Nazwisko: " << sname << endl;
}

void Gunslinger::Data() const
{
	cout << "Czas wyciagniecia rewolweru: " << get_rt() << endl;
	cout << "Liczba naciec na rewolwerze: " << marks << endl;
}

void Gunslinger::Show() const
{
	Person::Show();
	Data();
}

Card& PokerPlayer::draw() const
{
	srand(time(0));
	int choice = rand() % 52;
	return talia[choice];
}

void PokerPlayer::Data() const
{
	Card& inhand = draw();
	cout << inhand;
}

void PokerPlayer::Show() const
{
	Person::Show();
	Data();
}

void BadDude::Show() const
{
	Person::Show();
	PokerPlayer::Data();
	Gunslinger::Data();
}