#include "sala.h"

Sala::Sala(unsigned int wielkosc) : wielkosc_sali(wielkosc), id_sali(++counter) {}
unsigned int Sala::get_wielkosc()		const		{ return wielkosc_sali; }
unsigned int Sala::get_id()				const		{ return id_sali; }
void Sala::set_wielkosc(unsigned int wielkosc)		{ wielkosc_sali = wielkosc; }
void Sala::set_id(unsigned int id)					{ id_sali = id; }
void Sala::set_counter(unsigned int count)			{ counter = count; }

unsigned int Sala::counter = 0;