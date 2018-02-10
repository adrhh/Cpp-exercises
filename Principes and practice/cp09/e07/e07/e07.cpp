#include <iostream>
#include <string>
#include <cctype>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

struct ISBN
{
	int ia;
	int ib;
	int ic;
	char id;
	ISBN(int a = 0, int b = 0, int c = 0, char d = '0') : ia(a), ib(b), ic(c), id(d) {}
	friend bool operator==(const ISBN& i1, const ISBN& i2);
};

//for input check
bool is_isbn(int a, int b, int c, char d);

static const string Generes[5] = { "fiction", "fact", "magazine", "biography", "kids" };

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

bool is_valid(int g, int a, int b, int c, char d);

int main()
{
	Book test(2034, 11451, 30324, 'z', "Pole", "Mikolaj", Book::kids);
	cout << test;

	return 0;
}

Book::Book(int a, int b, int c, char d, const string& tit, const string& aut, Book::Genere g)
	 : isbn(ISBN(a, b, c, d)), author(aut), title(tit), genere(g), is_brred(false)
{
	if (!is_valid(g, a, b, c, d))
		throw Invalid();
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