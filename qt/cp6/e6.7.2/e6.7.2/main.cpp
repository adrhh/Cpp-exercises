#include <fstream>
#include <iostream>
#include <string>
#include <QDebug>
#include "arglist.h"
#include "birthdays.h"

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;

bool validDate(const QString& str);
QDate QstringToDate(const QString& str);

int main(int argc, char *argv[])
{
	Arglist arg(argc, argv);
	//arg.testShow();

	bool validN;
	QString nStr = arg.getSwitchArg("-n", "30");
	int n = nStr.toInt(&validN);
	if (&validN)
	{
		Birthdays b;
		ifstream inf;
		inf.open("test.txt");

		while (inf.good())
		{
			inf >> b;
		}
		QList<QString> upList = b.upToX(n);
		inf.close();

		for (auto i : upList)
			qDebug() << i << endl;
	}

	QString tempName = arg.getSwitchArg("-a", "empty");
	//arg.testShow();
	if (tempName != "empty")
	{
		//get next argument
		QString tempDateStr = arg[1];
		arg.removeAt(1);
		//check is valid date
		if (validDate(tempDateStr))
		{

			ofstream onf;
			onf.open("test.txt");

			QDate tempDate = QstringToDate(tempDateStr);
			QString tempNewB = QString("( %1 : %2 )")
				.arg(tempName)
				.arg(tempDate.toString("d - M - yyyy"));
			qDebug() << tempNewB << endl;
			onf << tempNewB.toStdString();

			onf.close();
		}
		else
			qDebug() << "nie porawna data" << endl;
	}
	return 0;
}

bool validDate(const QString& str)
{
	int y, m, d;

	//format d-m-y
	QString da, mo, ye;
	int it = 0;
	while (str[it] != '-')
	{
		da += str[it];
		it++;
		d = stoi(da.toStdString());
	}
	while (str[it] != '-')
	{
		mo += str[it];
		it++;
		m = stoi(da.toStdString());
	}
	while (str[it] != '\0')
	{
		ye += str[it];
		it++;
		y = stoi(da.toStdString());
	}

	QDate temp(y, m, d);
	return temp.isValid();
}

QDate QstringToDate(const QString& str)
{
	int y, m, d;
	//format d-m-y
	QString da, mo, ye;
	int it = 0;
	while (str[it] != '-')
	{
		da += str[it];
		it++;
		d = stoi(da.toStdString());
	}
	while (str[it] != '-')
	{
		mo += str[it];
		it++;
		m = stoi(da.toStdString());
	}
	while (str[it] != '\0')
	{
		ye += str[it];
		it++;
		y = stoi(da.toStdString());
	}

	return QDate(y, m, d);
}