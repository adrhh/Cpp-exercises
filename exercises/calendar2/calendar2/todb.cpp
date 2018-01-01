#include "todb.h"

vector<vector<string> >person_columnns;
vector<string> id_p = { "id", "INTEGER", "PRIMARY KEY" };
vector<string> fname = { "fname", "VARCHAR(30)", "NOT NULL" };
vector<string> sname = { "sname", "VARCHAR(30)", "NOT NULL" };
vector<string> date = { "date", "VARCHAR(30)", "NOT NULL" };

vector<vector<string> >event_colums;
vector<string> id_e = { "id", "INTEGER", "PRIMARY KEY" };
vector<string> person_id = { "person_id", "INTEGER", "NOT NULL" };
vector<string> type = { "type", "VARCHAR(30)", "NOT NULL" };

vector<vector<string> >shop_list;
vector<string> id_s = { "id", "INTEGER", "PRIMARY KEY" };
vector<string> event_id = { "event_id", "INTEGER", "NOT NULL" };
vector<string> item = { "item", "VARCHAR(30)", "NOT NULL" };
vector<string> quant = { "quant", "INTEGER", "NOT NULL" };
vector<string> price = { "price", "INTEGER", "NOT NULL" };

vector<table> tables;

