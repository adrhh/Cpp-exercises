#ifndef TODB_H_
#define TODB_H_

#include <stdexcept>
#include <string>
#include <vector>
#include "sqlite3.h"


using std::string;
using std::vector;

//defualt colmuns for person class
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
	string to_do;
	vector<table> tables;
	bool columns_done;
public:
	class db_err : public std::runtime_error
	{
	public:
		db_err(const string& s = "uknown error") : std::runtime_error(s) {}
		virtual ~db_err() throw() {}
	};

	Todb() {};
	string get_file() const { return file; }
	void open(const string& s);
	void make_columns();
};

class open_err : public Todb::db_err
{
private:
	string localization;
public:
	open_err(const Todb& t, const string& msg = "can't open file") 
			: db_err(msg), localization(t.get_file()) {}
};

void Todb::open(const string& s)
{
	bool isnt_open = sqlite3_open(s.c_str(), &db);
	if (isnt_open)
		throw open_err(*this);
}

#endif // !TODB_H_
