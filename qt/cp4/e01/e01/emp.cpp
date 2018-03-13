#include "emp.h"
#include <QTextStream>

QTextStream cout(stdout);

Employer::Employer() : m_Name("empty")
{
}

Employer::Employer(QString n) : m_Name(n)
{
}

bool Employer::hire(Person& per, const Position pos)
{
	if (!per.isEmployed())
	{
		per.setPosition(pos);
		per.setEmployer(this);
		m_EmployeeList.push_back(&per);
		if (m_OpenPositions.indexOf(pos) != -1)
			m_OpenPositions.removeAt(m_OpenPositions.indexOf(pos));
		return true;
	}
	else
		return false;
}

void Employer::addPosition(Position pos)
{
	m_OpenPositions.push_back(pos);
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

bool Position::operator==(const Position& pos)
{
	if (m_Name == pos.m_Name &&
		m_Description == pos.m_Description)
		return true;
	else
		return false;
}

void show_plist(const QList<Position>& pl)
{
	for (int i = 0; i < pl.size(); i++)
		cout << pl[i].toString() << endl;
}

Person::Person() : m_Name("empty")
{
	Position p_empty;
	m_Position = p_empty;
	m_Employer = nullptr;
	m_Employed = false;
}

Person::Person(QString n) : m_Name(n)
{
	Position p_empty;
	m_Position = p_empty;
	m_Employer = nullptr;
	m_Employed = false;
}