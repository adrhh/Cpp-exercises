#ifndef BIRTHDAYS_H_
#define BIRTHDAYS_H_

#include <QDate>
#include <QList>
#include <QString>
#include <QPair>
#include <istream>

using std::istream;

class Birthdays
{
public:
	istream& operator(istream& is, Birthdays& b);
private:
	QList<QPair<QString, QDate>> blist;
};

#endif // !BIRTHDAYS_H_
