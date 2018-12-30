#ifndef SEANS_H_
#define SEANS_H_

#include "film.h"
#include "sala.h"
#include "data.h"
#include <ctime>

class Seans
{
private:
	const Film* film;
	const Sala* sala;
	dddata data_seansu;
	unsigned int film_id;
	unsigned int sala_id;
	unsigned int ilosc_miejsc;
	unsigned int zajete_miejsca;
	unsigned int seans_id;
	static unsigned int counter;
public:
	Seans() = default;
	Seans(Film* f, Sala* s, dddata dt);
	uint64_t     get_data()			 const;
	const Film*	 get_film()			 const;
	const Sala*	 get_sala()			 const;
	unsigned int get_sala_id()		 const;
	unsigned int get_film_id()		 const;
	unsigned int get_id()			 const;
	unsigned int get_ilosc_miejsc()  const;
	unsigned int get_zajete()		 const;
	unsigned int get_wolne_miejsca() const;
	void		 set_zajete(unsigned int i);
	void		 set_sala_id(unsigned int id);
	void		 set_film_id(unsigned int id);
	void		 set_data(dddata dt);
	void		 set_ilosc_miejsc();
	void		 set_id(unsigned int id);
	void		 set_film(const Film* f);
	void		 set_sala(const Sala* s);
	static void  set_counter(unsigned int count);
};

#endif // !SEANS_H_
