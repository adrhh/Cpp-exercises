#include <iostream>
#include <stdlib.h>
#include "sqlite3.h"

using std::wcerr;
using std::endl;
using std::cout;

/*
typedef int (*sqlite3_callback)(
void*,     Data provided in the 4th argument of sqlite3_exec() 
int,	   The number of columns in row 
char**,    An array of strings representing fields in the row
char**     An array of strings representing column names 
); */

static int callback(void* data, int columns, char **col_val, char **col_name)
{
	for (int i = 0; i < columns; i++)
	{ 
		cout << col_name[i] << " : " << col_val[i] ? col_val[i] : "NULL";
		cout << endl;
	}
	cout << data;
	cout << endl;
	return 0;
}

int main()
{
	sqlite3  *db;
	bool sqlb;
	char *err_msg = "blad bazy danych";
	const char* data = "Callback function called\n";

	sqlb = sqlite3_open("test.db", &db);
	if (sqlb)
		wcerr << "Blad otwarcia bazy danych" << endl;
	else
		cout << "Baza otwarta" << endl;

	//creat table
	char *sql;
	sql =
		"CREATE TABLE empls"\
		"("\
		"id INTEGER PRIMARY KEY,"
		"name VARCHAR(20) NOT NULL,"
		"sname VARCHAR(30) NOT NULL,"
		"salary DECIMAL(7, 2) NOT NULL,"
		"position VARCHAR(20),"
		"pesel CHAR(6)"
		");";

	sqlb = sqlite3_exec(db, sql, callback, 0, &err_msg );

	if (sqlb != SQLITE_OK)
	{
		wcerr << err_msg;
		sqlite3_free(err_msg);
	}
	else
		cout << "tabela utworzona" << endl;

	sql =
		"INSERT INTO empls VALUES (1, 'Wilhelm', 'August', 2500.50, 'ksiaze', '543789');"\
		"INSERT INTO empls VALUES (2, 'Pawel', 'Wirtemberski', 1624.30, 'ksiaze', '340914');";

	sqlb = sqlite3_exec(db, sql, callback, 0, &err_msg);
	if (sqlb != SQLITE_OK)
	{
		wcerr << err_msg;
		sqlite3_free(err_msg);
	}
	else
		cout << "rekordy dodane" << endl;


	sql = 
		"SELECT * FROM empls";

	sqlb = sqlite3_exec(db, sql, callback, (void*)data, &err_msg);


	sqlite3_close(db);

	return 0;
}