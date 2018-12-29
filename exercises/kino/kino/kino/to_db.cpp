#include "to_db.h"
#include <iostream>

using std::pair;
using std::to_string;
using std::cerr;
using std::endl;

unsigned int To_DB::error_nr = 0;
const str Film_to_DB::COLUMN_NAME_FILM = "film";
const str Sala_to_DB::COLUMN_NAME_SALA = "sala";
const str Seans_to_DB::COLUMN_NAME_SEANS = "seans";

const vector<str> Seans_to_DB::column_names
{
	"AA_ID",
	"Data",
	"Sala",
	"Film"
};

const vector<str> Seans_to_DB::column_atributes
{
	"INT PRIMARY KEY NOT NULL",
	"INT NOT NULL",
	"INT NOT NULL",
	"INT NOT NULL"
};

const vector<str> Sala_to_DB::column_names
{
	"AA_ID",
	"Wielkosc"
};

const vector<str> Sala_to_DB::column_atributes
{
	"INT PRIMARY KEY NOT NULL",			//ID	
	"INT NOT NULL",						//Wielskosc
};


const vector<str> Film_to_DB::column_names
{
	"AA_ID",
	"Tytul",
	"Dlugosc",
	"Gatunek"
};

const vector<str> Film_to_DB::column_atributes
{
	"INT PRIMARY KEY NOT NULL",			//ID
	"CHAR(64) NOT NULL",				//Tytul
	"INT NOT NULL",						//Dlugosc
	"CHAR(32)",							//Gatunek
};

void Seans_to_DB::set_seans(Seans* seans_ptr)
{
	ptr_to_seans = seans_ptr;
}

void Film_to_DB::set_film(const Film* film_ptr)
{
	ptr_to_film = film_ptr;
}

void Sala_to_DB::set_sala(const Sala* sala_ptr)
{
	ptr_to_sala = sala_ptr;
}

map<str, str> Seans_to_DB::create_table_map() const
{
	map<str, str> new_table_map;
	auto it = new_table_map.begin();
	auto cn = column_names.begin();
	auto ca = column_atributes.begin();
	for (; cn != column_names.end(); ++cn, ++ca)
		new_table_map.insert(it, pair<str, str>(*cn, *ca));

	return new_table_map;
}

map<str, str> Seans_to_DB::add_record_map() const
{
	map<str, str> new_record_map;
	auto it = new_record_map.begin();
	new_record_map.insert(it, pair<str, str>(column_names[_ID],  to_string(ptr_to_seans->get_id())));
	new_record_map.insert(it, pair<str, str>(column_names[Data], to_string(ptr_to_seans->get_data())));
	new_record_map.insert(it, pair<str, str>(column_names[Sala], to_string(ptr_to_seans->get_sala()->get_id())));
	new_record_map.insert(it, pair<str, str>(column_names[Film], to_string(ptr_to_seans->get_film()->get_id())));

	return new_record_map;
}

map<str, str> Sala_to_DB::create_table_map() const
{
	map<str, str> new_table_map;
	auto it = new_table_map.begin();
	auto cn = column_names.begin();
	auto ca = column_atributes.begin();
	for (; cn != column_names.end(); ++cn, ++ca)
		new_table_map.insert(it, pair<str, str>(*cn, *ca));

	return new_table_map;
}

map<str, str> Sala_to_DB::add_record_map() const
{
	map<str, str> new_record_map;
	auto it = new_record_map.begin();
	new_record_map.insert(it, pair<str, str>(column_names[_ID], to_string(ptr_to_sala->get_id())));
	new_record_map.insert(it, pair<str, str>(column_names[Wielkoscs], to_string(ptr_to_sala->get_wielkosc())));
	return new_record_map;
}


map<str, str> Film_to_DB::create_table_map() const
{
	map<str, str> new_table_map;
	auto it = new_table_map.begin();
	auto cn = column_names.begin();
	auto ca = column_atributes.begin();
	for(;	cn != column_names.end(); ++cn, ++ca)
		new_table_map.insert(it, pair<str, str>(*cn, *ca));

return new_table_map;
}

map<str, str> Film_to_DB::add_record_map() const
{
	map<str, str> new_record_map;
	auto it = new_record_map.begin();
	new_record_map.insert(it, pair<str,str> (column_names[_ID],		to_string(ptr_to_film->get_id())			));
	new_record_map.insert(it, pair<str,str> (column_names[Dlugosc], to_string(ptr_to_film->get_dlugosc())		));
	new_record_map.insert(it, pair<str,str> (column_names[Tytul],   str("'" + ptr_to_film->get_tytul() + "'")   ));
	new_record_map.insert(it, pair<str,str> (column_names[Gatunek], str("'" + ptr_to_film->get_gatunek() + "'")	));
	return new_record_map;
}

map<str, str> Film_to_DB::up_record_map(unsigned int kolumna) const
{
	map<str, str> update_map;
	if (kolumna > NUMBER_OF_COLUMS)
	{
		cerr << "kolumna poza zakresem";
		To_DB::error_nr = 1;
		return update_map;
	}
	auto it = update_map.begin();
	update_map.insert(it, pair<str, str>(column_names[_ID], to_string(ptr_to_film->get_id())));
	switch (kolumna)
	{
	case Dlugosc:
		update_map.insert(it, pair<str, str>(column_names[Dlugosc], to_string(ptr_to_film->get_dlugosc())));
		break;
	case Tytul:
		update_map.insert(it, pair<str, str>(column_names[Tytul], str("'" + ptr_to_film->get_tytul() + "'")));
		break;
	case Gatunek:
		update_map.insert(it, pair<str, str>(column_names[Gatunek], str("'" + ptr_to_film->get_gatunek() + "'")));
		break;
	};

	return update_map;
}