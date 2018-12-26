#ifndef FROM_DB_H_
#define FROM_DB_H_


#include "db.h"
#include "film.h"

typedef std::string str;


class From_DB
{
private:
	
public:
	DB* db;
};

class Film_from_DB : public From_DB
{
private:
	const static str COLUMN_NAME_FILM;
public:
	Film get_film_from_db(unsigned int key);
};


#endif // !FROM_DB_H_