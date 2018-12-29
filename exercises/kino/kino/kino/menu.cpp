#include "menu.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void Kino::pokaz_filmy()
{
	for (auto& p : filmy)
	{
		cout << "Id:"		<< p.get_id() << endl;
		cout << "Tytol: "   << p.get_tytul() << endl;
		cout << "Dlugosc: " << p.get_dlugosc_str() << endl;
		cout << "Gatunek: " << p.get_gatunek() << endl;
		cout << endl;
	}
}

void Kino::pokaz_sale()
{
	for (auto& p : sale)
	{
		cout << "nr sali: "		 << p.get_id() << endl;
		cout << "ilosc mijesc: " << p.get_wielkosc() << endl;
		cout << endl;
	}
}

void Kino::dodaj_film()
{
	to_db = &film_to_db;
	if (!is_filmy_table)
	{
		db->create_table(Film_to_DB::COLUMN_NAME_FILM, to_db->create_table_map());
		is_filmy_table = true;
	}

	//utworz film, zrobic osobna funkcja
	str tytul_filmu;
	unsigned int gatunek;
	unsigned int dlugosc;

	cout << "Podaj nazwe filmu" << endl;
	cin >> tytul_filmu;
	cout << "Podaj nr gatunku" << endl;
	cin >> gatunek;
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "Podaj dlugosc [min]" << endl;
	cin >> dlugosc;
	cin.clear(); cin.ignore(INT_MAX, '\n');

	Film nowy_film(tytul_filmu, dlugosc, (Film::Gatunki)gatunek);
	nowy_film.set_obserwator(&film_obser);

	film_to_db.set_film(&nowy_film);
	db->insert_to_table(Film_to_DB::COLUMN_NAME_FILM, to_db->add_record_map());

	filmy.push_back(nowy_film);
}

void Kino::dodaj_seans()
{
	to_db = &seans_to_db;
	if (!is_seans_table)
	{
		db->create_table(Seans_to_DB::COLUMN_NAME_SEANS, to_db->create_table_map());
		is_seans_table = true;
	}

	const unsigned int rok = 2019 - 1900;
	const unsigned int miesiac = 0; // 0 = styczen
	unsigned int dzien;
	unsigned int godzina;

	tm data_seansu;
	cout << "Podaj dzien: " << endl;
	cin >> dzien;
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "Podaj godzine: " << endl;
	cin.clear(); cin.ignore(INT_MAX, '\n');

	data_seansu.tm_hour = godzina;
	data_seansu.tm_mday = dzien;
	data_seansu.tm_mon = miesiac;
	data_seansu.tm_year = rok;

	Film* film_ptr = nullptr;
	unsigned int film_id = UINT_MAX;
	bool is_correct_film_id = false;
	while (!is_correct_film_id)
	{
		cout << "Podaj id filmu: " << endl;
		cin >> film_id;
		cin.clear(); cin.ignore(INT_MAX, '\n');
		for (auto& f : filmy)
		{
			if (f.get_id() == film_id)
			{
				film_ptr = &f;
				is_correct_film_id = true;
				break;
			}
		}
	}

	Sala* sala_ptr;
	unsigned int sala_id = UINT_MAX;
	bool is_correct_sala_id = false;
	while (!is_correct_sala_id)
	{
		cout << "Podaj id sali: " << endl;
		cin >> sala_id;
		cin.clear(); cin.ignore(INT_MAX, '\n');
		for (auto& s : sale)
		{
			if (s.get_id() == sala_id)
			{
				sala_ptr = &s;
				is_correct_sala_id = true;
				break;
			}
		}
	}
	Seans nowy_seans(film_ptr, sala_ptr);

	seans_to_db.set_seans(&nowy_seans);
	db->insert_to_table(Seans_to_DB::COLUMN_NAME_SEANS, to_db->add_record_map());
	seanse.push_back(nowy_seans);

}

void Kino::dodaj_sale()
{
	to_db = &sala_to_db;
	if (!is_sala_table)
	{
		db->create_table(Sala_to_DB::COLUMN_NAME_SALA, to_db->create_table_map());
		is_sala_table = true;
	}
	unsigned int wielkosc_sali;
	cout << "Podaj wielkosc sali: " << endl;
	cin >> wielkosc_sali;
	cin.clear(); cin.ignore(INT_MAX, '\n');

	Sala nowa_sala(wielkosc_sali);
	sala_to_db.set_sala(&nowa_sala);
	db->insert_to_table(Sala_to_DB::COLUMN_NAME_SALA, to_db->add_record_map());
	sale.push_back(nowa_sala);
}

void Kino::get_films_from_db()
{
	Film_from_DB from_db;
	from_db.db = &DB::get_db();
	vector<unsigned int> film_ids = from_db.get_film_ids_from_db();

	if (film_ids.size())
	{
		is_filmy_table = true;
		unsigned int max_id = *std::max_element(film_ids.begin(), film_ids.end());
		for (auto id : film_ids)
			filmy.push_back(from_db.get_film_from_db(id));
		Film::set_counter(max_id);
	}
}

void Kino::get_sale_from_db()
{
	Sala_from_DB from_db;
	from_db.db = &DB::get_db();
	vector<unsigned int> sale_ids = from_db.get_sala_ids_from_db();

	if (sale_ids.size())
	{
		is_sala_table = true;
		unsigned int max_id = *std::max_element(sale_ids.begin(), sale_ids.end());
		for (auto id : sale_ids)
			sale.push_back(from_db.get_sala_from_db(id));
		Sala::set_counter(max_id);
	}
}

void Kino::pokaz_seanse()
{

	for (auto& s : seanse)
	{
		cout << "ID seanse: " << s.get_id() << endl;
		cout << "Data seansu: " << s.get_data() << endl;
		cout << "Sala nr: "		<< s.get_sala()->get_id() << endl;
		cout << "Wielkosc sali: " << s.get_sala()->get_wielkosc() << endl;
		cout << "Film:" <<	s.get_film()->get_tytul() << endl;

	}
}

void Menu::show_menu()
{
	unsigned int i = 0;
	bool is_top =		actual_node == &nl[glowne];

	if (!is_top)
		cout << i++ << ". " << "Powrot wyzej" << endl;


	for (auto p : actual_node->nodes)
		cout << i++ << ". " << p->node_name << endl;


	int user_pick = pick(is_top);
	while (user_pick == NOT_IN_RANGE)
	{
		cout << "Zly wybor" << endl;
		user_pick = pick(is_top);
	}
	
	Node* next_node;
	if (!user_pick && !is_top) actual_node = actual_node->up;
	else
	{
		if (!is_top)		   next_node = actual_node->nodes[--user_pick];
		else				   next_node = actual_node->nodes[user_pick];

		if (next_node->f == nullptr)
			actual_node = next_node;
		else
			(kino.*next_node->f)();
	}
}

int Menu::pick(bool top)
{
	unsigned int max = actual_node->nodes.size();
	if (!top)	 max++;
	int pick;
	cin >> pick;
	cin.clear(); cin.ignore(INT_MAX, '\n');
	if (pick >= 0 && pick < max)
		return pick;
	else
		return NOT_IN_RANGE;
}

void Menu::menu_loop()
{
	actual_node = &nl[glowne];
	while (true)
	{
		show_menu();
	}
}