#ifndef CONTACT_H_
#define CONTACT_H_

#include <qstring.h>
#include <qlist.h>

class Contact
{
private:
	int category;
	QString firstName;
	QString lastName;
	QString city;
	QString streetAdress;
	QString phoneNumber;
public:
	QString toString() const;
	QString getFname() const { return firstName; }
	QString getPhone() const { return phoneNumber; }
	int getCategory() const { return category; }
	bool operator==(const Contact& c);
};

class ContactList
{
private:
	QList<Contact> clist;
public:
	void add(Contact c);
	void remove(Contact c);
	QStringList getPhoneList(int category);
};

#endif // !CONTACT_H_
