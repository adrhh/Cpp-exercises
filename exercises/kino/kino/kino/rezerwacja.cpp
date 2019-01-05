#include "rezerwacja.h"

unsigned int Rezerwacja::counter = 0;

Rezerwacja::Rezerwacja(unsigned int sid, bool op) :  seans_id(sid), oplacona(op), rezerwacja_id(++counter) {}
void				Rezerwacja::set_id(unsigned int id)					   { rezerwacja_id = id; }
void				Rezerwacja::set_seans_id(unsigned int id)			   { seans_id	   = id; }
void				Rezerwacja::set_seans(const Seans* se)				   { seans_ptr	   = se; }
void				Rezerwacja::set_counter(unsigned int count)			   { counter	   = count; }
void				Rezerwacja::set_oplacona(bool czy_oplacona)			   { oplacona	   = czy_oplacona; }
const Seans*		Rezerwacja::get_seans()				const			   { return seans_ptr; }
unsigned int		Rezerwacja::get_seans_id()			const			   { return seans_id; }
unsigned int		Rezerwacja::get_id()				const			   { return rezerwacja_id; }
bool				Rezerwacja::get_oplacona()			const			   { return oplacona; }

unsigned int Rezerwacje::counter = 0;

Rezerwacje::Rezerwacje(const Klient* kl_ptr, const Rezerwacja* rz_ptr) : ptr_to_klient(kl_ptr), 
										 ptr_to_rezerwacja(rz_ptr), aa_rezerwacje_id(++counter) {}
void				Rezerwacje::set_rezerwacja_id(unsigned int id)			{ rezerwacja_id		= id;}
void				Rezerwacje::set_klient_id(unsigned int id)				{ klient_id			= id; }
void				Rezerwacje::set_id(unsigned int id)						{ aa_rezerwacje_id	= id; }
void				Rezerwacje::set_klient(const Klient* kl_ptr)			{ ptr_to_klient		= kl_ptr; }
void				Rezerwacje::set_rezerwacja(const Rezerwacja* rz_ptr)	{ ptr_to_rezerwacja = rz_ptr; }
void				Rezerwacje::set_counter(unsigned int count)				{ counter = count; }
unsigned int		Rezerwacje::get_id()				const				{ return aa_rezerwacje_id; }
unsigned int		Rezerwacje::get_klient_id()			const				{ return klient_id; }
unsigned int		Rezerwacje::get_rezerwacja_id()		const				{ return rezerwacja_id;  }
const Klient*		Rezerwacje::get_klient()			const				{ return ptr_to_klient; }
const Rezerwacja*	Rezerwacje::get_rezerwacja()		const				{ return ptr_to_rezerwacja; }