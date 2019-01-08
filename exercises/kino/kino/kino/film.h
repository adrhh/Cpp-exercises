#ifndef FILM_H_
#define FILM_H_

#include <string>

class Obser_film;

typedef std::string str;

class Film 
{
public:
	enum Gatunki { KOMEDIA, SF, FATNASY, DRAMAT, SENACYJNY, HISTORYCZNY, NIEZNANY };
	enum { ID, Tytul, Dlugosc, Gatunek };

	Film() : obserwator_filmu(nullptr) {}
	Film(const str& tytul_filmu, unsigned int dlugosc_filmu, Gatunki gatunek_filmu) :
		film_tytul(tytul_filmu),
		film_dlugosc(dlugosc_filmu),
		film_gatunek(gatunek_filmu),
		film_id(++film_counter)
		{}

	str get_tytul()				const;
	str get_gatunek()		    const;
	str get_dlugosc_str()		const;
	unsigned int get_dlugosc()  const;
	unsigned int get_id()		const;
	void set_obserwator(Obser_film* obs_ptr);
	void set_tytu(const str& nowy_tytul);
	void set_gatunek(Gatunki gatune);
	void set_dlugosc(unsigned int nowa_dlugosc);
	void set_id(unsigned int nowe_id);
	static void set_counter(unsigned int nowy_licznik);
private:
	Obser_film* obserwator_filmu;
	str film_tytul;
	static unsigned int film_counter;
	unsigned int film_id;
	unsigned int film_dlugosc;
	Gatunki film_gatunek;
};

#endif // !FILM_H_
