#ifndef DB_H_
#define DB_H_

#include <string>
#include <map>
#include "sqlite3.h"
typedef std::string str;
using std::map;

class DB
{
private:
	static const str DB_NAME;

	sqlite3* db;
	char* error_code;
	std::string db_name;
	DB();
	
	static int db_callback(void *NotUsed, int argc, char **argv, char **azColName);
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
	str select_from_table(const str&);
};





#endif // !DEB_H
