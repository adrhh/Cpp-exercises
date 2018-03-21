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

QList<QString> Arglist::getSwitch2Arg(QString option, QString defVal1, QString defVal2)
{
	QList<QString> retList;
	if (isEmpty())
		return retList << defVal1 << defVal2;

	QMutableStringListIterator itr(*this);
	while (itr.hasNext())
	{
		if (option == itr.next())
		{
			itr.remove();
			const int Arg2 = 2;
			for (int i = 0; i < Arg2; i++)
			{
				if (itr.hasNext())
				{
					QString retval = itr.next();
					itr.remove();
					retList << retval;
				}
				else
				{
					qDebug() << "brak parametru dla " << option;
					QList<QString> emptyL;
					return emptyL;
				}
			}
		}
	}
	return retList;
}

void Arglist::agrsToList(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
		*this += argv[i];
}