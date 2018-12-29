#include "db.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::pair;

const str DB::DB_NAME = "test1.db";
const str DB::K_CT = "CREATE TABLE";
const str DB::K_II = "INSERT INTO";
const str DB::K_VL = "VALUES";
const str DB::K_UP = "UPDATE";

map<str, str> DB::map_buffer = map<str, str>();
vector<str>   DB::vec_buffer = vector<str>();

DB::DB() : db_name(DB_NAME), error_code(0)
{
	if (!db)
	{
		sqlite3_open(db_name.c_str(), &db);
		cerr << "baza otworzona: " << db_name << endl;
	}
	else
		cerr << "baza juz otwarta" << endl;
}

DB::~DB() { sqlite3_close(db); }

int DB::db_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	printf("\n");
	return 0;
}

int DB::db_from(void *NotUsed, int argc, char **argv, char **azColName)
{
	auto it = DB::map_buffer.begin();
	for (int i = 0; i < argc; i++)
		map_buffer.insert(it, pair<str, str>(azColName[i], argv[i]));

	return 0;
}

int DB::db_column_from(void *NotUsed, int argc, char **argv, char **azColName)
{
	vec_buffer.push_back(*argv);
	return 0; 
}

DB& DB::get_db()
{
	static DB base = DB();
	return base;
}

void DB::create_table(const str& table_name, const map<str, str>& key_vals)
{
	str sql_ss;
	sql_ss = K_CT + ' ' + table_name + '(';
	for (auto& p = key_vals.begin(); p != key_vals.end(); ++p)
		sql_ss += (*p).first + ' ' + (*p).second + ", ";
	sql_ss.pop_back(); sql_ss.pop_back();
	sql_ss += ");";

	int d = sqlite3_exec(db, sql_ss.c_str(), db_callback, 0, &error_code);
	if (d)
		cerr << "error: " << error_code << endl;

	//debug info
	cerr << "debug: " << sql_ss << endl;
}

void DB::insert_to_table(const str& table_name, const map<str, str>& key_vals)
{
	str sql_ss;

	sql_ss = K_II + ' ' + table_name + '(';
	for (auto& p = key_vals.begin(); p != key_vals.end(); ++p)
		sql_ss += (*p).first + ", ";
	sql_ss.pop_back(); sql_ss.pop_back(); //remove last ','
	sql_ss += ") " + K_VL + "(";
	for (auto& p = key_vals.begin(); p != key_vals.end(); ++p)
		sql_ss += (*p).second + ", ";
	sql_ss.pop_back(); sql_ss.pop_back();
	sql_ss += ");";

	int d = sqlite3_exec(db, sql_ss.c_str(), db_callback, 0, &error_code);
	if (d)
		cerr << "error: " << error_code << endl;
	//debug info
	cerr << "debug: " << sql_ss << endl;
}

void DB::update_record(const str& table_name, const map<str, str>& key_vals)
{
	str sql_ss;
	sql_ss = "UPDATE " + table_name + "  set ";
	auto it = key_vals.begin();  
	str sql_ss2 = (*it).first + " = " + (*it).second;
	++it;
	sql_ss += (*it).first + " = " + (*it).second + " where ";
	sql_ss += sql_ss2 + ';';


	int d = sqlite3_exec(db, sql_ss.c_str(), db_callback, 0, &error_code);
	if (d)
		cerr << "error: " << error_code << endl;
	//debug info
	cerr << "debug: " << sql_ss << endl;
	
	return;
}

map<str, str> DB::select_record_from_table(const str& sql_ss)
{
	
	int d = sqlite3_exec(db, sql_ss.c_str(), db_from, 0, &error_code);
	map<str, str> ret_val = map<str, str>(map_buffer);
	DB::map_buffer.clear();
	
	if (d)
		cerr << "error: " << error_code << endl;
	//debug info
	cerr << "debug: " << sql_ss << endl;

	return ret_val;
}

vector<str> DB::select_column_from_table(const str& sql_ss)
{
	int d = sqlite3_exec(db, sql_ss.c_str(), db_column_from, 0, &error_code);

	vector<str> ret_val = vector<str>(vec_buffer);
	DB::vec_buffer.clear();

	if (d)
		cerr << "error: " << error_code << endl;
	//debug info
	cerr << "debug: " << sql_ss << endl;

	return ret_val;

}