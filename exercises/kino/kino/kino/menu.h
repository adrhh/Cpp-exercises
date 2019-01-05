#ifndef MENU_H_
#define MENU_H_

#include "heads.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::string str;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

class Kino
{
private:
	DB* db;
	To_DB* to_db;

	Film_to_DB film_to_db;
	Sala_to_DB sala_to_db;
	Seans_to_DB seans_to_db;
	Klient_to_DB klient_to_db;
	Rezerwacja_to_DB rezerwacja_to_db;
	Rezerwacje_to_DB rezerwacje_to_db;
	Obser_film film_obser;
	vector<Film> filmy;
	vector<Sala> sale;
	vector<Seans> seanse;
	vector<Klient> klienci;
	vector<Rezerwacja> rezerwacja_lista;
	vector<Rezerwacje> rezerwacje_lista;

	bool is_sala_table;
	bool is_filmy_table;
	bool is_seans_table;
	bool is_klient_table;
	bool is_rezerwacja_lista;
	bool is_rezrewacje_lista;

	void get_seanse_from_db();
	void get_sale_from_db();
	void get_films_from_db();
	void get_klienci_from_db();
	void get_rezerwacja_from_db();
	void get_rezerwacje_from_db();
public:
	Kino() : film_obser(&film_to_db), is_sala_table(false),		 is_filmy_table(false), 
									  is_seans_table(false),	 is_klient_table(false),
									  is_rezerwacja_lista(false), is_rezrewacje_lista(false)
			{ 
			  db = &DB::get_db(); 
			  get_films_from_db();
			  get_sale_from_db();
			  get_seanse_from_db();
			  get_klienci_from_db();
			  get_rezerwacja_from_db();
			  get_rezerwacje_from_db();
			}
	void dodaj_sale();
	void pokaz_sale();
	void dodaj_film();
	void pokaz_film(const Film& f);
	void pokaz_filmy();
	void dodaj_seans();
	void pokaz_seans(const Seans& s);
	void pokaz_seanse();
	void dodaj_klienta();
	void pokaz_klienta(const Klient& k);
	void pokaz_klientow();
	void pokaz_rez_szczeg();
	void rezerwuj();

};

class Menu
{

private:
	static const short NOT_IN_RANGE = -1;
	struct Node
	{
		Node* up;
		vector<Node*> nodes;
		void (Kino::*f)(void);
		str node_name;
	};
	enum lm
	{
		glowne,
			filmy,
				dodaj_film,
				pokaz_filmy,
			sale,
				dodaj_sale,
				pokaz_sale,
			seans,
				dodaj_seans,
				pokaz_seanse,
			klient,
				dodaj_klienta,
				pokaz_klientow,
			rezerwacje,
				rezerwuj,
				pokaz_r_szegulowo,
	};
	Node nl[100] = 
	{
		{nullptr,		{&nl[filmy], &nl[sale], &nl[seans], &nl[klient], &nl[rezerwacje]},			
																		nullptr,				   "glowne"			}, //0
		{&nl[glowne],	{&nl[dodaj_film], &nl[pokaz_filmy]},			nullptr,				   "filmy"			}, //1
		{&nl[filmy],	{},												&Kino::dodaj_film,		   "dodaj film"		}, //2
		{&nl[filmy],	{},												&Kino::pokaz_filmy,		   "pokaz filmy"	}, //3
		{&nl[glowne],	{&nl[dodaj_sale], &nl[pokaz_sale]},			    nullptr,				   "sale"			}, //4
		{&nl[sale],	    {},												&Kino::dodaj_sale,		   "dodaj sale"		}, //5
		{&nl[sale],	    {},												&Kino::pokaz_sale,		   "pokaz sale"		}, //6
		{&nl[glowne],	{&nl[dodaj_seans], &nl[pokaz_seanse]},			nullptr,				   "seanse"			}, //7
		{&nl[seans],	{},												&Kino::dodaj_seans,		   "dodaj seans"	}, //8
		{&nl[seans],	{},												&Kino::pokaz_seanse,	   "pokaz seanse"	}, //9
		{&nl[glowne],	{&nl[dodaj_klienta], &nl[pokaz_klientow]},		nullptr,				   "klient"			}, //10
		{&nl[klient],	{},												&Kino::dodaj_klienta,	   "dodaj klienta"	}, //11
		{&nl[klient],	{},												&Kino::pokaz_klientow,	   "pokaz klientow"	}, //12
		{&nl[glowne],	{&nl[rezerwuj], &nl[pokaz_r_szegulowo] },		nullptr,					"rezerwacje"	}, //13
		{&nl[klient],	{},												&Kino::rezerwuj,		   "rezerwuj"		}, //14
		{&nl[klient],	{},												&Kino::pokaz_rez_szczeg,	"pokaz wszytkie szczegulwo"	}, //15
	};

	Kino kino;
	Node* actual_node;

public:
	void show_menu();
	void menu_loop();
	int pick(bool top);
};


#endif // !MENU_H_
