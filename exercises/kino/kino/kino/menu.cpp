#include "menu.h"
#include <errno.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Kino::pokaz_rez_szczeg()
{
	for (auto& r : rezerwacje_lista)
	{
		cout << "----------------------------------------------" << endl;
		const Rezerwacja* rez_ptr = r.get_rezerwacja();
		const Klient* kl_ptr = r.get_klient();
		const Seans* sn_ptr = rez_ptr->get_seans();
		cout << "nr rezerwacji: " << rez_ptr->get_id() << endl;
		pokaz_klienta(*kl_ptr);
		pokaz_seans(*sn_ptr);
	}
}

void Kino::pokaz_film(const Film& f)
{
	cout << "Id:"		<< f.get_id()			<< endl;
	cout << "Tytol: "	<< f.get_tytul()		<< endl;
	cout << "Dlugosc: " << f.get_dlugosc_str()  << endl;
	cout << "Gatunek: " << f.get_gatunek()		<< endl;
	cout << endl;
}

void Kino::pokaz_filmy()
{
	for (auto& p : filmy)
		pokaz_film(p);
}

void Kino::pokaz_sale()
{
	for (auto& p : sale)
	{
		cout << "nr sali: "		 << p.get_id()		 << endl;
		cout << "ilosc mijesc: " << p.get_wielkosc() << endl;
		cout										 << endl;
	}
}

void Kino::pokaz_klienta(const Klient& k)
{
	cout << "Imie: " << k.get_imie() << endl;
	cout << "Nazwisko: " << k.get_nazwisko() << endl;
	cout << endl;
}

void Kino::pokaz_klientow()
{
	for (auto& k : klienci)
		pokaz_klienta(k);
}

void Kino::pokaz_seans(const Seans& s)
{
	dddata dt;
	dt.from_64(s.get_data());

	cout << "ID seanse: " << s.get_id() << endl;
	cout << "Data seansu: " << dt.year << '/' << (short)dt.month << '/' << (short)dt.day << endl;
	cout << "Sala nr: " << s.get_sala()->get_id() << endl;
	cout << "Wielkosc sali: " << s.get_sala()->get_wielkosc() << endl;
	cout << "Film:" << s.get_film()->get_tytul() << endl;

}

void Kino::pokaz_seanse()
{
	for (auto& s : seanse)
		pokaz_seans(s);
}


void Kino::rezerwuj()
{
	Klient* kl_ptr;
	Seans*	se_ptr;

	bool is_correct_kl_id = false;
	unsigned int kl_id;
	while (!is_correct_kl_id)
	{
		cout << "Podaj nr klienta: " << endl;
		cin >> kl_id;
		cin.clear(); cin.ignore(INT_MAX, '\n');
		for (auto& k : klienci)
		{
			if (k.get_id() == kl_id)
			{
				kl_ptr = &k;
				is_correct_kl_id = true;
				break;
			}
		}
	}

	bool is_correct_se_id = false;
	unsigned int se_id;
	while (!is_correct_se_id)
	{
		cout << "Podaj nr seanse: " << endl;
		cin >> se_id;
		cin.clear(); cin.ignore(INT_MAX, '\n');
		for (auto& s : seanse)
		{
			if (s.get_id() == se_id)
			{
				s.set_ilosc_miejsc();
				if (!s.get_wolne_miejsca())
				{
					cout << s.get_ilosc_miejsc() << ':' << s.get_wolne_miejsca() << ':' << s.get_zajete() << endl;
					cout << "brak wolnych miejsc w tym seansie" << endl;
				}
				else
				{
					se_ptr = &s;
					is_correct_se_id = true;
					break;
				}
			}
		}
	}

	
	Rezerwacja nowa_rezerwacja(se_id);
	nowa_rezerwacja.set_seans(se_ptr);
	to_db = &rezerwacja_to_db;
	if (!is_rezerwacja_lista)
	{
		db->create_table(Rezerwacja_to_DB::COLUMN_NAME_REZERWACJA, to_db->create_table_map());
		is_rezerwacja_lista = true;
	}
	rezerwacja_to_db.set_rezerwacja(&nowa_rezerwacja);
	db->insert_to_table(Rezerwacja_to_DB::COLUMN_NAME_REZERWACJA, to_db->add_record_map());
	rezerwacja_lista.push_back(nowa_rezerwacja);

	// TO DO
	// UPDATE SEANS ILOSC MIEJSC

	Rezerwacje nowe_rezerwacje(kl_ptr, &rezerwacja_lista.back());

	// do konstrutora przeniesc
	nowe_rezerwacje.set_rezerwacja_id(rezerwacja_lista.back().get_id());
	nowe_rezerwacje.set_klient_id(kl_ptr->get_id());

	to_db = &rezerwacje_to_db;
	if (!is_rezrewacje_lista)
	{
		db->create_table(Rezerwacje_to_DB::COLUMN_NAME_REZERWACJE, to_db->create_table_map());
		is_rezrewacje_lista = true;
	}
	rezerwacje_to_db.set_rezerwacje(&nowe_rezerwacje);
	db->insert_to_table(Rezerwacje_to_DB::COLUMN_NAME_REZERWACJE, to_db->add_record_map());
	rezerwacje_lista.push_back(nowe_rezerwacje);
}

void Kino::dodaj_klienta()
{
	to_db = &klient_to_db;
	if (!is_klient_table)
	{
		db->create_table(Klient_to_DB::COLUMN_NAME_KLIENT, to_db->create_table_map());
		is_klient_table = true;
	}
	
	str imie;
	cout << "Podaj imie: " << endl;
	cin >> imie;

	str nazwisko;
	cout << "Podaj nazwisko: " << endl;
	cin >> nazwisko;

	Klient nowy_klient(imie, nazwisko);

	klient_to_db.set_klient(&nowy_klient);
	db->insert_to_table(Klient_to_DB::COLUMN_NAME_KLIENT, to_db->add_record_map());
	klienci.push_back(nowy_klient);
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

	const unsigned int rok = 2019;
	const unsigned int miesiac = 1;
	unsigned int dzien;
	unsigned int godzina;

	cout << "Podaj dzien: " << endl;
	cin >> dzien;
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "Podaj godzine: " << endl;
	cin >> godzina;
	cin.clear(); cin.ignore(INT_MAX, '\n');

	dddata dt(rok, miesiac, dzien, godzina);
	

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

	Seans nowy_seans(film_ptr, sala_ptr, dt);
	seans_to_db.set_seans(&nowy_seans);
	nowy_seans.set_ilosc_miejsc();
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

void Kino::get_klienci_from_db()
{
	Klient_from_DB from_db;
	from_db.db = &DB::get_db();

	vector<unsigned int> klient_ids = from_db.get_klient_ids_from_db();
	if (klient_ids.size())
	{
		is_klient_table = true;
		unsigned max_id = *std::max_element(klient_ids.begin(), klient_ids.end());
		Klient::set_counter(max_id);
		for (auto id : klient_ids)
		{
			Klient nowy_klient = from_db.get_klient_from_db(id);
			klienci.push_back(nowy_klient);
		}
	}
}

void Kino::get_rezerwacja_from_db()
{
	Rezerwacja_from_DB from_db;
	from_db.db = &DB::get_db();
	vector<unsigned int> rezerwacja_ids = from_db.get_rezerwacja_ids_from_db();

	if (rezerwacja_ids.size())
	{
		is_rezerwacja_lista = true;
		unsigned int max_id = *std::max_element(rezerwacja_ids.begin(), rezerwacja_ids.end());
		Rezerwacja::set_counter(max_id);
		for (auto id : rezerwacja_ids)
		{
			Rezerwacja nowa_rezerwacja = from_db.get_rezerwacja_from_db(id);
			unsigned int seans_id = nowa_rezerwacja.get_seans_id();
			for (auto& s : seanse)
			{
				if (s.get_id() == seans_id)
				{
					nowa_rezerwacja.set_seans(&s);
					break;
				}
			}
			rezerwacja_lista.push_back(nowa_rezerwacja);
		}
	}
}

void Kino::get_rezerwacje_from_db()
{
	Rezerwacje_from_DB from_db;
	from_db.db = &DB::get_db();
	vector<unsigned int> rezerwacje_ids = from_db.get_rezerwacje_ids_from_db();

	if (rezerwacje_ids.size())
	{
		is_rezrewacje_lista = true;
		unsigned int max_id = *std::max_element(rezerwacje_ids.begin(), rezerwacje_ids.end());
		Rezerwacje::set_counter(max_id);
		for (auto id : rezerwacje_ids)
		{
			Rezerwacje nowe_rezerwacje = from_db.get_rezerwacje_from_db(id);
			unsigned int rezerwacja_id = nowe_rezerwacje.get_rezerwacja_id();
			for (auto& r : rezerwacja_lista)
			{
				if (r.get_id() == rezerwacja_id)
				{
					nowe_rezerwacje.set_rezerwacja(&r);
					break;
				}
			}
			unsigned int klient_id = nowe_rezerwacje.get_klient_id();
			for (auto& k : klienci)
			{
				if (k.get_id() == klient_id)
				{
					nowe_rezerwacje.set_klient(&k);
					break;
				}
			}
			rezerwacje_lista.push_back(nowe_rezerwacje);
		}
	}

}

void Kino::get_seanse_from_db()
{
	Seans_from_DB from_db;
	from_db.db = &DB::get_db();
	vector<unsigned int> seans_ids = from_db.get_seans_ids_from_db();

	if (seans_ids.size())
	{
		is_seans_table = true;
		unsigned int max_id = *std::max_element(seans_ids.begin(), seans_ids.end());
		Seans::set_counter(max_id);
		for (auto id : seans_ids)
		{
			Seans nowy_seans = from_db.get_seans_from_db(id);
			unsigned int film_id = nowy_seans.get_film_id();
			for (auto& f : filmy)
			{
				if (f.get_id() == film_id)
				{
					nowy_seans.set_film(&f);
					break;
				}
			}
			unsigned int sala_id = nowy_seans.get_sala_id();
			for (auto& s : sale)
			{
				if (s.get_id() == sala_id)
				{
					nowy_seans.set_sala(&s);
					break;
				}
			}
			seanse.push_back(nowy_seans);
		}
	}
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
		if (!is_top)		   next_node   = actual_node->nodes[--user_pick];
		else				   next_node   = actual_node->nodes[user_pick];

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