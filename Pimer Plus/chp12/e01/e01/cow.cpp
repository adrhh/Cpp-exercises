#define _CRT_SECURE_NO_WARNINGS
#include "cow.h"
#include <cstring>
#include <iostream>

using namespace std;

int Cow::cow_counter = 0;

Cow::Cow()
{
	strcpy(name, "Testowa krowa");
	char* temp_hobby = "Trawa";
	hobby = new char[strlen(temp_hobby) + 1];
	strcpy(hobby, temp_hobby);
	weight = 1000.0;
	cow_counter++;
	cout << "Konstruktor domyslny: Utworzono obiekt nr: " << cow_counter << endl;
}
Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
	cow_counter++;
	cout << "Konstruktor: Utworzono obiekt nr: " << cow_counter << endl;
}
Cow::Cow(const Cow &c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	cow_counter++;
	cout << "Konstruktor kopjujacy: Utworzono obiekt nr: " << cow_counter << endl;
}
Cow::~Cow()
{
	cow_counter--;
	delete[] hobby;
	cout << "Zniszczono obiekt, liczba krow wynosi tera: " << cow_counter << endl;

}

Cow & Cow::operator=(const Cow &c)
{
	if (this == &c)
		return *this;
	delete hobby;
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.name);
	weight = c.weight;

	return *this;
}
void Cow::ShowCow() const
{
	cout << "Imie: " << name << endl
		<< "Hobby: " << hobby << endl
		<< "Waga: " << weight << endl;
}