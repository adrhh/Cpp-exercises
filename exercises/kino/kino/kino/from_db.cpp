#include "from_db.h"
#include "data.h"
#include <iostream>
#include <string>

using std::endl;
using std::cerr;
using std::to_string;

const str Film_from_DB::COLUMN_NAME_FILM	= "film";
const str Sala_from_DB::COLUMN_NAME_SALA	= "sala";
const str Seans_from_DB::COLUMN_NAME_SEANS  = "seans";


Seans Seans_from_DB::get_seans_from_db(unsigned int key)
{
	str sql_str = "select * from ";
	sql_str += COLUMN_NAME_SEANS + " where AA_ID == " + to_string(key) + ";";
	map<str, str> seans_map = db->select_record_from_table(sql_str);

	Seans new_seans = Seans();
	dddata dt;

	dt.from_64(stoull(seans_map["Data"]));
	new_seans.set_data(dt);
	new_seans.set_id(stoi(seans_map["AA_ID"]));
	new_seans.set_film_id(stoi(seans_map["Film"]));
	new_seans.set_sala_id(stoi(seans_map["Sala"]));
	new_seans.set_zajete(stoi(seans_map["Zajete"]));
	

	return new_seans;
}


vector<unsigned int> Seans_from_DB::get_seans_ids_from_db()
{
	str sql_str = "select AA_ID from ";
	sql_str += COLUMN_NAME_SEANS + ";";

	return get_ids_from_db(sql_str);
}


vector<unsigned int> From_DB::get_ids_from_db(const str& sql_ss)
{
	vector<str> id_str_arr = db->select_column_from_table(sql_ss);
	vector<unsigned int> id_arr;
	for (auto p : id_str_arr)
		id_arr.push_back(stoi(p));

	return id_arr;
}

Sala Sala_from_DB::get_sala_from_db(unsigned int key)
{
	str sql_str = "select * from ";
	sql_str += COLUMN_NAME_SALA+ " where AA_ID == " + to_string(key) + ";";
	map<str, str> sala_map = db->select_record_from_table(sql_str);

	Sala new_sala = Sala();

	new_sala.set_wielkosc(stoi(sala_map["Wielkosc"]));
	new_sala.set_id(stoi(sala_map["AA_ID"]));

	return new_sala;
}
vector<unsigned int> Sala_from_DB::get_sala_ids_from_db()
{
	str sql_str = "select AA_ID from ";
	sql_str += COLUMN_NAME_SALA + ";";

	return get_ids_from_db(sql_str);
}

vector<unsigned int> Film_from_DB::get_film_ids_from_db()
{
	str sql_str = "select AA_ID from ";
	sql_str += COLUMN_NAME_FILM + ";";

	return get_ids_from_db(sql_str);
}

Film Film_from_DB::get_film_from_db(unsigned int key)
{
	str sql_str = "select * from ";
	sql_str += COLUMN_NAME_FILM + " where AA_ID == " + to_string(key) + ";";
	map<str, str> film_map = db->select_record_from_table(sql_str);
	
	Film new_film = Film(); //default constructor without observ and counter update

	new_film.set_tytu(film_map["Tytul"]);
	new_film.set_dlugosc(stoi(film_map["Dlugosc"]));
	new_film.set_id(stoi(film_map["AA_ID"]));
	
	str str_gatunek(film_map["Gatunek"]);
	Film::Gatunki gatunek = Film::Gatunki::NIEZNANY;
	if      (str_gatunek == "fantasy")		gatunek = Film::Gatunki::FATNASY;
	else if (str_gatunek == "komedia")		gatunek = Film::Gatunki::KOMEDIA;
	else if (str_gatunek == "SF")			gatunek = Film::Gatunki::SF;
	else if (str_gatunek == "dramat")		gatunek = Film::Gatunki::DRAMAT;
	else if (str_gatunek == "historyczny")	gatunek = Film::Gatunki::HISTORYCZNY;
	new_film.set_gatunek(gatunek);

	return new_film;
}