#include "seans.h"

unsigned int Seans::counter = 0;
Seans::Seans(Film* f,Sala* s) : film(f), sala(s), zajete_miejsca(0),  seans_id(++counter) {}

unsigned int Seans::get_data()				  { return mktime(&data_seansu); }
Film*		 Seans::get_film()			const { return film; }
Sala*		 Seans::get_sala()			const { return sala; }
unsigned int Seans::get_id()			const { return seans_id; }
unsigned int Seans::get_ilosc_miejsc()  const { return ilosc_miejsc; }
unsigned int Seans::get_wolne_miejsca() const { return ilosc_miejsc - zajete_miejsca; }
void		 Seans::set_data(unsigned int data) { tm* temp = gmtime((time_t*)&data); 
																data_seansu = *temp;}

void		 Seans::set_id(unsigned int id)			{ seans_id = id; }
void		 Seans::set_counter(unsigned int count) { counter = count; }
void		 Seans::set_ilosc_miejsc()				{ ilosc_miejsc = sala->get_wielkosc(); }
