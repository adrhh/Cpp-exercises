#include "film.h"
#include "obserwator.h"

unsigned int Film::film_counter = 0;

unsigned int Film::get_id()		 const { return film_id; }
unsigned int Film::get_dlugosc() const { return film_dlugosc; }
str Film::get_tytul()			 const { return film_tytul; }
str Film::get_dlugosc_str()		 const { return std::to_string(film_dlugosc); }
str Film::get_gatunek()			 const
{
	switch (film_gatunek)
	{
	case KOMEDIA:		return "komedia";
	case SF:			return "SF";
	case FATNASY:		return "fanatsy";
	case DRAMAT:		return "dramat";
	case HISTORYCZNY:	return "historyczny";
	//
	default: return "Nieznany";
	};
}
void Film::set_obserwator(Obser_film* obs_ptr)
{
	obserwator_filmu = obs_ptr;
}

void Film::set_tytu(const str& nowy_tytul)
{
	film_tytul = nowy_tytul;
	if (obserwator_filmu)
		obserwator_filmu->update(Tytul);
}
void Film::set_gatunek(Gatunki gatunek)
{
	film_gatunek = gatunek;
	if (obserwator_filmu)
		obserwator_filmu->update(Gatunek);
}
void Film::set_dlugosc(unsigned int nowa_dlugosc)
{
	film_dlugosc = nowa_dlugosc;
	if (obserwator_filmu)
		obserwator_filmu->update(Dlugosc);
}
