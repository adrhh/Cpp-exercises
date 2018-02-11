#include "Librar.h"
#include <cctype>
#include <iostream>

using std::endl;
using std::ios_base;
using std::cout;

static const string Generes[5] = { "fiction", "fact", "magazine", "biography", "kids" };

namespace Chrono
{
	const Date& default_date()
	{
		static Date dd(2001, Date::jan, 1);
		return dd;
	}

	Date::Date() :
		y(default_date().year()),
		m(default_date().month()),
		d(default_date().day())
	{

	}

	Date::Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd)
	{
		if (!is_date(yy, mm, dd))
			throw Invalid();
	}

	void Date::add_day(int n)
	{

	}

	void Date::add_month(int m)
	{

	}

	void Date::add_year(int n)
	{
		if (m == feb && d == 29 && !leapyear(y + n))
		{
			m = mar;
			d = 1;
		}
		y += n;
	}

	bool leapyear(int y)
	{
		//t
		return true;
	}

	bool is_date(int y, Date::Month m, int d)
	{
		if (d <= 0)
			return false;
		if (m < Date::jan || m > Date::dec)
			return false;
		int days_in_month = 31;
		switch (m)
		{
		case Date::feb:
			days_in_month = leapyear(y) ? 29 : 28;
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			days_in_month = 30;
			break;
		}
		if (d > days_in_month)
			return false;

		return true;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year() &&
			a.month() == b.month() &&
			a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year() << ','
			<< d.month() << ',' << d.day() << ')';
	}

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is)
			return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(ios_base::failbit);
			return is;
		}
		return is;
	}

	enum Day {sunday, monday, tuesday, wednesday, thrusday, friday, satu};
}

bool check_debt(const Patron& p)
{
	return p.get_is_debt();
}

bool is_isbn(int a, int b, int c, char d)
{
	bool answ = true;
	if (a < 0 || b < 0 || c < 0)
		answ = false;
	if (!isalnum(d))
		answ = false;
	return answ;
}

bool is_valid(int g, int a, int b, int c, char d)
{
	bool answ = true;
	if (!is_isbn(a, b, c, d))
		answ = false;
	if (g < Book::fiction || g > Book::kids)
		answ = false;

	return answ;
}

bool operator==(const ISBN& i1, const ISBN& i2)
{
	bool answ = true;
	if (i1.ia != i2.ia ||
		i1.ib != i2.ib ||
		i1.ic != i2.ic ||
		i1.id != i2.id)
		answ = false;
	return answ;
}


bool operator==(const Book& b1, const Book& b2)
{
	return b1.isbn == b2.isbn;
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1.isbn == b2.isbn);
}

ostream& operator<<(ostream& os, const Book& b)
{
	os << b.author << endl;
	os << b.title << endl;
	os << Generes[b.genere] << endl;
	os << b.isbn.ia << '-' << b.isbn.ib << '-'
		<< b.isbn.ic << '-' << b.isbn.id;

	return os;
}


bool operator==(const Patron& p1, const Patron& p2)
{
	return (p1.name == p2.name &&
		p1.id == p2.id);
}

Book::Book(int a, int b, int c, char d, const string& tit, const string& aut, Book::Genere g)
	: isbn(ISBN(a, b, c, d)), author(aut), title(tit), genere(g), is_brred(false)
{
	if (!is_valid(g, a, b, c, d))
		throw Invalid();
}

void Library::add_book(const Book& b)
{
	books.push_back(b);
}
void Library::add_patron(const Patron& p)
{
	patrons.push_back(p);
}
void Library::make_trans(const Book& b,const Patron& p, const Date& d)
{
	bool is_ok = false;
	for (auto it : books)
	{
		if (it == b)
		{ 
			is_ok = true;
			break;
		}
	}
	if (is_ok)
	{
		is_ok = false;
		for (auto it : patrons)
		{
			if (it == p)
			{
				is_ok = true;
				break;
			}
		}
	}

	if (is_ok)
	{
		Transacion temp(b, p, d);
		trans.push_back(temp);
	}
	else
		cout << "err";
		//throw Invalid();
}

vector<Patron> Library::debt_pats() const
{
	vector<Patron> temp;
	for (auto it : patrons)
		if (it.get_is_debt())
			temp.push_back(it);

	return temp;
}