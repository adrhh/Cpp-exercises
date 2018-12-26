#include "from_db.h"
#include <iostream>
#include <string>

using std::endl;
using std::cerr;
using std::to_string;

const str Film_from_DB::COLUMN_NAME_FILM = "Film";

Film Film_from_DB::get_film_from_db(unsigned int key)
{
	str sql_str = "select * from ";
	sql_str += COLUMN_NAME_FILM + " where AA_ID == " + to_string(key);
	cerr << sql_str << endl;
	db->select_from_table(sql_str);

	return Film();
}