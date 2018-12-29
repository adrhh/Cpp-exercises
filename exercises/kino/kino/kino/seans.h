#ifndef SEANS_H_
#define SEANS_H_

#include "film.h"
#include "sala.h"
#include <ctime>

class Seans
{
private:
	Film* film;
	Sala* sala;
	tm data_seansu;
	unsigned int ilosc_miejsc;
	unsigned int zajete_miejsca;
	unsigned int seans_id;
	static unsigned int counter;
public:
	Seans() = default;
	Seans(Film* f, Sala* s);
	unsigned int get_data();
	Film*		 get_film() const;
	Sala*		 get_sala() const;
	unsigned int get_id()	const;
	unsigned int get_ilosc_miejsc()  const;
	unsigned int get_wolne_miejsca() const;
	void		 set_data(unsigned int data);
	void		 set_ilosc_miejsc();
	void		 set_id(unsigned int id);
	static void  set_counter(unsigned int count);
};

#endif // !SEANS_H_
