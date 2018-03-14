#include "contact.h"
#include <QTextStream>

int main(int argc, char *argv[])
{
	QTextStream cout(stdout);

	Contact c1(1, "Jan", "Z Dukli", "3453"),
		c2(1, "Marcin", "Piwko", "45322"),
		c3(1, "Ruffin", "Janusz", "0614467"),
		c4(1, "Szymon", "Z Lipnicy", "48561654");

	ContactList l1;
	l1.add(c1);
	l1.add(c2);
	l1.add(c3);
	l1.add(c4);

	QStringList pl1 = l1.getPhoneList(1);
	for (auto i: pl1 )
		cout << i << endl;

	return 0;
}
