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
	Obser_film film_obser;
	vector<Film> filmy;
	vector<Sala> sale;
	vector<Seans> seanse;

	bool is_sala_table;
	bool is_filmy_table;
	bool is_seans_table;

	void get_sale_from_db();
	void get_films_from_db();
public:
	Kino() : film_obser(&film_to_db), is_sala_table(false), is_filmy_table(false), is_seans_table(false)
			{ 
			  db = &DB::get_db(); 
			  get_films_from_db();
			  get_sale_from_db();
			}
	void dodaj_sale();
	void pokaz_sale();
	void dodaj_film();
	void pokaz_filmy();
	void dodaj_seans();
	void pokaz_seanse();
};

class Menu
{

public:
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
				pokaz_seanse
	};
	Node nl[100] = 
	{
		{nullptr,		{&nl[filmy], &nl[sale], &nl[seans]},				nullptr,					   "glowne"},
		{&nl[glowne],	{&nl[dodaj_film], &nl[pokaz_filmy]},			nullptr,					    "filmy"},
		{&nl[filmy],	{},												&Kino::dodaj_film,		   "dodaj film"},
		{&nl[filmy],	{},												&Kino::pokaz_filmy,		   "pokaz filmy"},
		{&nl[glowne],	{&nl[dodaj_sale], &nl[pokaz_sale]},			    nullptr,				   "sale"},
		{&nl[sale],	    {},												&Kino::dodaj_sale,		   "dodaj sale"},
		{&nl[sale],	    {},												&Kino::pokaz_sale,		   "pokaz sale"},
		{&nl[glowne],	{&nl[dodaj_seans], &nl[pokaz_seanse]},			nullptr,					    "seanse"},
		{&nl[seans],	{},												&Kino::dodaj_seans,		   "dodaj seans"},
		{&nl[seans],	{},												&Kino::pokaz_seanse,		"pokaz seanse"},
	};
private:
	Kino kino;
	Node* actual_node;

public:
	void show_menu();
	void menu_loop();
	int pick(bool top);
};


#endif // !MENU_H_
