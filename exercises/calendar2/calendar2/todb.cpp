#include "todb.h"

//defualt colmuns for person class
namespace default_tables
{
	vector<string> id_p = { "id", "INTEGER", "PRIMARY KEY" };
	vector<string> fname = { "fname", "VARCHAR(30)", "NOT NULL" };
	vector<string> sname = { "sname", "VARCHAR(30)", "NOT NULL" };
	vector<vector<string> >person_columnns = { id_p, fname, sname };

	vector<string> id_e = { "id", "INTEGER", "PRIMARY KEY" };
	vector<string> person_id = { "person_id", "INTEGER", "NOT NULL" };
	vector<string> type = { "type", "VARCHAR(30)", "NOT NULL" };
	vector<string> date = { "date", "VARCHAR(30)", "NOT NULL" };
	vector<vector<string> >event_colums = { id_e, person_id, type, date };

	vector<string> id_s = { "id", "INTEGER", "PRIMARY KEY" };
	vector<string> event_id = { "event_id", "INTEGER", "NOT NULL" };
	vector<string> item = { "item", "VARCHAR(30)", "NOT NULL" };
	vector<string> quant = { "quant", "INTEGER", "NOT NULL" };
	vector<string> price = { "price", "INTEGER", "NOT NULL" };
	vector<vector<string> >shop_list = { id_s, event_id, item, quant, price };
};

class open_err : public Todb::db_err
{
private:
	string localization;
public:
	open_err(const Todb& t, const string& msg = "can't open file")
		: db_err(msg), localization(t.get_file()) {}
	virtual ~open_err() throw() {}
	virtual string info() { return localization; }
};

class table_err : public Todb::db_err
{
private:
	string table;
public:
	table_err(const Todb& t, const string& msg = "can't add table", int i = 0)
		: db_err(msg), table(t.get_table_name(i)) {}
	virtual ~table_err() throw() {}
	virtual string info() { return table; }
};

Todb::Todb() //default constructor with tables for person class
{
	using namespace default_tables;
	is_open = false;

	table p_col;
	p_col.columns = person_columnns;
	p_col.t_name = "person";

	table e_col;
	e_col.columns = event_colums;
	e_col.t_name = "event";

	table s_col;
	s_col.columns = shop_list;
	s_col.t_name = "shopping";

	tables.push_back(p_col);
	tables.push_back(e_col);
	tables.push_back(s_col);
}

int Todb::callback(void* data, int columns, char **col_val, char **col_name)
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

void Todb::make_columns()
{
	// first statement
	const string Crt = "CREATE TABLE ";

	bool is_ok;

	for (auto t : tables)
	{
		string to_do = Crt;
		char* cerr_msg = "error";

		//table name
		to_do += t.t_name;
		//add columns
		to_do += " ( ";

		int size = t.columns.size(); //deal with ','
		int i = 0;

		for (auto words : t.columns)
		{
			for (auto word : words)
			{
				to_do += word + ' ';
			}
			i++;
			if (i < size)
				to_do += ", ";     // skip last ','
		}
		to_do += " );";

		//cout << to_do;

		is_ok = sqlite3_exec(db, to_do.c_str(), callback, 0, &cerr_msg);
		if (is_ok != SQLITE_OK)
			throw table_err(*this);
	}
}

void Todb::open_db(const string& s)
{
	bool isnt_open = sqlite3_open(s.c_str(), &db);
	if (isnt_open)
		throw open_err(*this);
	is_open = true;
}

void Todb::add(const Person& p, int i)
{
	bool is_ok;
	char* cerr_msg = "error";

	// first statement
	const string Crt = "INSERT INTO ";
	string to_do = Crt;
	to_do += get_table_name(i) + " VALUES (";
	to_do += to_string(p.person_id) + ", ";
	to_do += '\'' + p.fname + '\'' + ", ";
	to_do += '\'' + p.sname + '\'';
	to_do += ");";

	//cout << to_do;

	is_ok = sqlite3_exec(db, to_do.c_str(), callback, 0, &cerr_msg);

}