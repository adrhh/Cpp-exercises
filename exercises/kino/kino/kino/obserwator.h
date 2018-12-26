#ifndef OBSERWATOR_H_
#define OBSERWATOR_H_
#include "film.h"
#include "to_db.h"
#include "db.h"

#include <iostream>
using namespace std;

class Obserwowany
{
protected:
	To_DB* to_db_ptr;
	DB*       db_ptr;
public:
	virtual void update(unsigned int) = 0;
};

class Obser_film : public Obserwowany
{
public:
	Obser_film(Film_to_DB* film_to_db_ptr)
	{
		to_db_ptr = film_to_db_ptr;
		db_ptr = &(DB::get_db());
	}
	virtual void update(unsigned int col) override
	{
		switch (col)
		{
		case Film::Tytul:
			db_ptr->update_record(Film_to_DB::COLUMN_NAME_FILM, to_db_ptr->up_record_map(Film::Tytul));
			break;
		case Film::Dlugosc:
			db_ptr->update_record(Film_to_DB::COLUMN_NAME_FILM, to_db_ptr->up_record_map(Film::Dlugosc));
			break;
		};
	}
};


#endif