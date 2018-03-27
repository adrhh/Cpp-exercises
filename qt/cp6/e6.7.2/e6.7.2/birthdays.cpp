#include "birthdays.h"
#include <string>
#include <QDebug>

using std::string;

QList<QString> Birthdays::upToX(int x) const
{
	QList<QString> uX;
	QDate qr = QDate::currentDate();
	QDate temp;
	int d = qr.day();
	int m = qr.month();
	int y;
	for (auto i : blist)
	{
		y = i.second.year();
		temp.setDate(y, m, d);
		if (temp.daysTo(i.second) < x || temp.daysTo(i.second) > 0)
			uX << i.first + " : " + i.second.toString();
	}
	return uX;
}


istream& operator>>(istream& is, Birthdays& b)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4, ch5;
	string name;
	is >> ch1 >> name >> ch2 >> y >> ch3 >> m >> ch4 >> d >> ch5;
	if (!is)
		return is;

	
	//format (name:d-m-y)
	if (ch1 != '(' || ch2 != ':' || ch3 != '-' || ch4 != '-' || ch5 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}
	QString qname = QString::fromStdString(name);
	QDate qdate = QDate(y, m, d);
	QPair<QString, QDate> qpair = QPair<QString, QDate>(qname, qdate);

	b.blist << qpair;

	return is;
}

ostream& operator<<(ostream& os, const Birthdays& b)
{
	QString sdate;
	for (int i = 0; i < b.blist.size(); i++)
	{
		sdate = b.blist[i].second.toString("d - M - yyyy");
		os << b.blist[i].first.toStdString() << ' ';
		os << sdate.toStdString() << '\n';
	}
	return os;
}