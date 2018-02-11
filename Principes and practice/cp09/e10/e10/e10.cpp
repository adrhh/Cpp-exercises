#include <iostream>
#include "Librar.h"
using std::cout;

int main()
{
	Book b1(2034, 11451, 30324, 'z', "Pole", "Mikolaj", Book::kids);
	Library lib;
	lib.add_book(b1);
	cout << lib.get_book(0);

	Patron pat("Janusz", 2030);
	lib.add_patron(pat);
	Date d1(2017, Date::mar, 23);

	lib.make_trans(b1, pat, d1);

	return 0;
}

