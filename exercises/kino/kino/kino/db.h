#ifndef DB_H_
#define DB_H_

#include <string>
#include <map>
#include <vector>
#include "sqlite3.h"
typedef std::string str;
using std::map;
using std::vector;

class DB
{
private:
	static const str DB_NAME;

	sqlite3* db;
	char* error_code;
	std::string db_name;
	DB();
	
	static int db_from(void *NotUsed, int argc, char **argv, char **azColName);
	static int db_callback(void *NotUsed, int argc, char **argv, char **azColName);
	static int db_column_from(void *NotUsed, int argc, char **argv, char **azColName);
	static map<str, str> map_buffer;		//must be clear after use
	static vector<str>   vec_buffer;
public:
	static const std::string K_CT;
	static const std::string K_II;
	static const std::string K_VL;
	static const std::string K_UP;

	~DB();
	static DB& get_db();
	void create_table(const str& table_name, const map<str, str>& key_vals);
	void insert_to_table(const str& table_name, const map<str, str>& key_vals);
	void update_record(const str& table_name, const map<str, str>& key_vals);
	map<str, str> select_record_from_table(const str&);
	vector<str> select_column_from_table(const str&);
};

#endif // !DEB_H
