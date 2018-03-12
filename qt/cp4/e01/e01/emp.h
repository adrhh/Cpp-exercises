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
	bool hire(Person& per, const Position pos);
	QList<Position> findJobs() const;
};

class Position
{
private:
	QString m_Name;
	QString m_Description;
public:
	Position();
	QString toString() const;
};

class Person
{
private:
	QString m_Name;
	Position m_Position;
	Employer& m_Employer;
	bool m_Employed;
public:
	Position& getPosition();
	Employer& getEmployer();
	QString getName() { return m_Name; }
	void setPosition(const Position pos);
	void setEmployer(const Employer& emp);
	bool isEmployed() const { return m_Employed; }
};



#endif // !EMP_H_
