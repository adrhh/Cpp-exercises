#ifndef EMP_H_
#define EMP_H_

#include <qlist.h>
#include <qstring.h>

class Person;
class Position;

void show_plist(const QList<Position>& pl);

class Employer
{
private:
	QString m_Name;
	QList<Person*> m_EmployeeList;
	QList<Position> m_OpenPositions;
public:
	Employer();
	Employer(QString n);
	bool hire(Person& per, const Position pos);
	void addPosition(Position pos);
	QList<Position> findJobs() const;
};

class Position
{
private:
	QString m_Name;
	QString m_Description;
public:
	Position() : m_Name("empty"), m_Description("empty") {}
	Position(QString n, QString d) : m_Name(n), m_Description(d) {}
	QString toString() const;
	bool operator==(const Position& pos);
};

class Person
{
private:
	QString m_Name;
	Position m_Position;
	Employer* m_Employer;
	bool m_Employed;
public:

	Person();
	Person(QString n);
	QString getName() { return m_Name; }
	void setPosition(const Position pos) { m_Position = pos; }
	void setEmployer(Employer* emp) { m_Employer = emp; }
	bool isEmployed() const { return m_Employed; }
};



#endif // !EMP_H_
