#ifndef FROM_DB_H_
#define FROM_DB_H_

#include "db.h"
#include "film.h"
#include "sala.h"
#include <vector>

typedef std::string str;
using std::vector;


class From_DB
{
private:
	
public:
	DB* db;
	vector<unsigned int> get_ids_from_db(const str& sql_ss);
};

class Sala_from_DB : public From_DB
{
private:
	const static str COLUMN_NAME_SALA;
public:
	Sala get_sala_from_db(unsigned int key);
	vector<unsigned int> get_sala_ids_from_db();
};

class Film_from_DB : public From_DB
{
private:
	const static str COLUMN_NAME_FILM;
public:
	Film get_film_from_db(unsigned int key);
	vector<unsigned int> get_film_ids_from_db();
};


#endif // !FROM_DB_H_