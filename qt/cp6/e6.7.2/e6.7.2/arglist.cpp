#include "arglist.h"
#include <QDebug>
#include <QCoreApplication>

Arglist::Arglist()
{
	if (qApp != NULL)
		*this = qApp->arguments();
}

bool Arglist::getSwitch(QString option)
{
	QMutableStringListIterator itr(*this);
	while (itr.hasNext())
	{
		if (option == itr.next())
		{
			itr.remove();
			return true;
		}
	}
	return false;
}

QString Arglist::getSwitchArg(QString option, QString defVal)
{
	if (isEmpty())
		return defVal;
	QMutableStringListIterator itr(*this);
	while (itr.hasNext())
	{
		if (option == itr.next())
		{
			itr.remove();
			if (itr.hasNext())
			{
				QString retval = itr.next();
				itr.remove();
				return retval;
			}
			else
			{
				qDebug() << "brak parametru dla " << option;
				return QString();
			}		
		}
	}
	return defVal;
}

void Arglist::agrsToList(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
		*this += argv[i];
}

void Arglist::testShow() const
{
	for (auto i : *this)
		qDebug() << i << endl;
}