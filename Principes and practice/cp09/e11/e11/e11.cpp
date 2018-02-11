#include <iostream>
#include "Librar.h"

using std::cout;
using std::endl;

int main()
{
	Book b1(2034, 11451, 30324, 'z', "Pole", "Mikolaj", Book::kids);
	Library lib;
	lib.add_book(b1);
	cout << lib.get_book(0);

	Patron pat("Janusz", 2030);
	lib.add_patron(pat);
	Date d1(2017, Date::mar, 25);

	lib.make_trans(b1, pat, d1);
	cout << endl;

	d1.show();
	d1.add_month(10);
	d1.show();
	d1.add_day(20);
	d1.show();
	Date d2 = next_workday(d1);
	d2.show();

	return 0;
}

