#include "emp.h"
#include <QTextStream>

bool Employer::hire(Person& per, const Position pos)
{
	if (!per.isEmployed())
	{
		per.setPosition(pos);
		per.setEmployer(*this);
		m_EmployeeList.push_back(&per);
		return true;
	}
	else
		return false;
}

QList<Position> Employer::findJobs() const
{
	QList<Position> open_pos;
	for (int i = 0; i < m_OpenPositions.size(); i++)
		open_pos.push_back(m_OpenPositions[i]);

	return open_pos;
}

QString Position::toString() const
{
	QString answ = QString("%1 : %2").arg(m_Name).arg(m_Description);
	return answ;
}

void show_plist(const QList<Position>& pl)
{
	for (int i = 0; i < pl.size(); i++)
		qDebug() << pl[i].toString() << endl;
}