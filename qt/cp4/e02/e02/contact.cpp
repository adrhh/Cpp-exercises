#include "contact.h"
#include <QTextStream>

QTextStream cout(stdout);

bool Contact::operator==(const Contact& c)
{
	if (category == c.category &&
		firstName == c.firstName &&
		lastName == c.lastName &&
		city == c.city &&
		streetAdress == c.streetAdress &&
		phoneNumber == c.phoneNumber)
		return true;
	else
		return false;
}

QString Contact::toString() const
{
	return QString("%1 %2 \t adres: %3 4")
		.arg(firstName)
		.arg(lastName)
		.arg(streetAdress)
		.arg(city);
}

void ContactList::add(Contact c)
{
	clist << c;
}

void ContactList::remove(Contact c)
{
	clist.removeAll(c);
}

QStringList ContactList::getPhoneList(int category)
{
	QStringList phoneList;
	foreach(const Contact& c, clist)
	{
		if (c.getCategory() == category);
		QString temp = QString("%1 \t %2")
			.arg(c.getFname())
			.arg(c.getPhone());
		phoneList << temp;
	}
	return phoneList;
}