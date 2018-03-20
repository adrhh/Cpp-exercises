#ifndef BIRTHDAYS_H_
#define BIRTHDAYS_H_

#include <QDate>
#include <QList>
#include <QString>
#include <QPair>
#include <istream>
#include <ostream>

using std::istream;
using std::ostream;

class Birthdays
{
public:
	friend istream& operator>>(istream& is, Birthdays& b);
	friend ostream& operator<<(ostream& os, const Birthdays& b);
private:
	QList<QPair<QString, QDate>> blist;
};

#endif // !BIRTHDAYS_H_
