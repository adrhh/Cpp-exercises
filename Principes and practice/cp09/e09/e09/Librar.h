#ifndef LIBRAR_H_
#define LIBRAR_H_

#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::istream;
using std::string;
using std::vector;

namespace Chrono
{
	class Date
	{
	public:
		enum Month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
		class Invalid {};
		Date(int y, Month m, int d);
		Date();

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_day(int n);
		void add_month(int m);
		void add_year(int y);

	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Date::Month m, int d);
	bool leapyear(int y);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& d);
}

struct ISBN
{
	int ia;
	int ib;
	int ic;
	char id;

	ISBN(int a = 0, int b = 0, int c = 0, char d = '0') : ia(a), ib(b), ic(c), id(d) {}
	friend bool operator==(const ISBN& i1, const ISBN& i2);
};

class Book
{
private:
	ISBN isbn;
	string title;
	string author;
	int genere;
	bool is_brred;
public:
	enum Genere { fiction, fact, magazine, biography, kids };
	Book(int a, int b, int c, char d, const string& tit, const string& aut, Book::Genere g);
	Book() : isbn(ISBN()), title("empty"), author("empty"), genere(Genere::fiction), is_brred(false) {}
	bool get_brred() const { return is_brred; }

	void change_brrd() { is_brred = !is_brred; }
	class Invalid
	{};
	friend bool operator==(const Book& b1, const Book& b2);
	friend bool operator!=(const Book& b1, const Book& b2);
	friend ostream& operator<<(ostream& os, const Book& b);
};

class Patron
{
private:
	string name;
	int id;
	double debt;
	bool is_debt;
public:
	Patron(const string& n = "no name", int i = 0) : name(n), id(i), debt(0), is_debt(false) {}
	bool get_is_debt() const { return is_debt; }
	bool change_debt() { debt = !debt; }
	double get_debt() const { return debt; }
	void set_debt(double x) { debt = x; }
	int get_id() { return id; }
	friend bool operator==(const Patron& p1, const Patron& p2);
};

using namespace Chrono;

class Library
{
private:
	struct Transacion
	{
		Book book;
		Patron patr;
		Date date;
		Transacion(const Book& b, const Patron& p, const Date& d) :
			book(b), patr(p), date(d) {}
	};
	class Invalid
	{};
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transacion> trans;
public:
	void add_book(const Book& b);
	void add_patron(const Patron& p);
	void make_trans(const Book& b, const Patron& p, const Date& d);
	vector<Patron> debt_pats() const;
};

bool is_isbn(int a, int b, int c, char d);
bool is_valid(int g, int a, int b, int c, char d);
bool check_debt(const Patron& p);

#endif // !LIBRAR_H_
