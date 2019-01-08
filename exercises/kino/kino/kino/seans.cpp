#include "seans.h"
#include "to_db.h"
#include "obserwator.h"

unsigned int Seans::counter = 0;
Seans::Seans(Film* f, Sala* s, dddata dt) : film(f), sala(s), zajete_miejsca(0), 
											data_seansu(dt), seans_id(++counter),
											obserwator_seansu(nullptr)
											{}

uint64_t	 Seans::get_data()			const		{ return data_seansu.to_64(); }
const Film*	 Seans::get_film()			const		{ return film; }
const Sala*	 Seans::get_sala()			const		{ return sala; }
unsigned int Seans::get_id()			const		{ return seans_id; }
unsigned int Seans::get_ilosc_miejsc()  const		{ return ilosc_miejsc; }
unsigned int Seans::get_wolne_miejsca() const		{ return ilosc_miejsc - zajete_miejsca; }
unsigned int Seans::get_zajete()		const		{ return zajete_miejsca;}
unsigned int Seans::get_sala_id()		const		{ return sala_id;  }
unsigned int Seans::get_film_id()		const		{ return film_id; }

void		 Seans::set_data(dddata dt)				{ data_seansu = dt; }
void		 Seans::set_zajete(unsigned int i)		{ zajete_miejsca = i; if (obserwator_seansu) obserwator_seansu->update(Seans_to_DB::Zajete);}
void		 Seans::set_id(unsigned int id)			{ seans_id = id; }
void		 Seans::set_counter(unsigned int count) { counter = count; }
void		 Seans::set_sala_id(unsigned int id)	{ sala_id = id; }
void		 Seans::set_film_id(unsigned int id)	{ film_id = id; }
void		 Seans::set_ilosc_miejsc()				{ ilosc_miejsc = sala->get_wielkosc(); }
void		 Seans::set_film(const Film* f)			{ film = f; }
void		 Seans::set_sala(const Sala* s)			{ sala = s; }
void		 Seans::set_obserwator(Obser_seans* os) { obserwator_seansu = os; }
