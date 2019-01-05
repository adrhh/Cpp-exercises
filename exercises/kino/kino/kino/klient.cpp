#include "klient.h"

unsigned int Klient::counter = 0;

Klient::Klient(const str& im, const str& nz) : imie(im), nazwisko(nz), klient_id(++counter) {}
str Klient::get_imie()					const { return imie; }
str Klient::get_nazwisko()				const { return nazwisko; }
unsigned int Klient::get_id()			const { return klient_id; }
void Klient::set_imie(const str& s)			  { imie = s; }
void Klient::set_nazwisko(const str& s)		  { nazwisko = s; }
void Klient::set_id(unsigned int id)		  { klient_id = id; }
void Klient::set_counter(unsigned int count)  { counter = count; }