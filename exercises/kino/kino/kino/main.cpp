#include "heads.h"
#include "menu.h"

int main()
{
	DB test = DB::get_db();
	Film film("DUpa", 30, Film::FATNASY);
	Film_to_DB fm(&film);
	To_DB* to = &fm;
	map<str, str> m = to->create_table_map();
	test.create_table("film", m);
	map<str, str> mr = to->add_record_map();
	test.insert_to_table("film", mr);

	Obser_film obs(&fm);
	film.set_obserwator(&obs);
	film.set_tytu("WIelka fupa");
	film.set_dlugosc(1);

	Film_from_DB frd;
	frd.db = &DB::get_db();

	frd.get_film_from_db(1);

	Menu menu;
	menu.menu_loop();

	return EXIT_SUCCESS;
}