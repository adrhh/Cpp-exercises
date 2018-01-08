#ifndef TODB_H_
#define TODB_H_

#include <stdexcept>
#include <string>
#include <vector>
#include "person.h"
#include "sqlite3.h"

using std::string;
using std::vector;
using std::to_string;



struct table
{
	string t_name; //table name
	vector<vector<string> > columns;
	//vector of columns, each column have id and atributes
};

class Todb
{
private:
	
	sqlite3* db;
	string file;
	vector<table> tables;
	bool columns_done;
	bool is_open;
public:
	Todb();
	string get_file() const { return file; }
	string get_table_name(int i) const { return tables[i].t_name;  }
	void open_db(const string& s);
	void make_columns();
	//add person
	void add(const Person& p, int i = 0);
	static int callback(void* data, int columns, char **col_val, char **col_name);

	class db_err : public std::runtime_error
	{
	public:
		db_err(const string& s = "uknown error") : std::runtime_error(s) {}
		virtual ~db_err() throw() {}
		virtual string info() = 0;
	};
};



#endif // !TODB_H_