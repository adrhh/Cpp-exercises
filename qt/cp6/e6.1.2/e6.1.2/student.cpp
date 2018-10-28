#include "student.h"
#include <QTextStream>

Student::Student(QString nm, long id, QString major, int year)
	: m_name(nm), m_studentId(id), m_major(major), m_year(year) {}

QString Student::getClassName() const
{
	return "Student";
}

QString Student::toString() const
{
	QString retval;
	QTextStream os(&retval);
	os << "[" << getClassName() << "]"
		<< "naziwsko: " << m_name
		<< ", id: " << m_studentId
		<< ", rok: " << m_year
		<< ", kierunek: " << m_major;
	return retval;
}
QString Student::yearStr() const
{
	QString retval;
	switch (m_year)
	{
	case 1 :
		retval = "1";
		break;
	case 2 :
		retval = "2";
		break;
	case 3 :
		retval = "3";
		break;
	case 4 :
		retval = "4";
		break;
	case 5 :
		retval = "5";
		break;
	default:
		retval = "nieznany";
		break;
	}
	return retval;
}

int Student::yearInt() const
{
	return m_year;
}

Undergrad::Undergrad(QString nm, long id, QString major, int yr, int sat) : 
	Student(nm, id, major, yr), m_SAT(sat) {}

QString Undergrad::getClassName() const
{
	return "Licencjat";
}

QString Undergrad::toString() const
{
	QString retval;
	QTextStream os(&retval);
	os << Student::toString()
		<< ", [SAT: " << m_SAT << "]";
	return retval;
}

GradStudent::GradStudent(QString nm, long id, QString major, int yr, Support sup) 
	: Student(nm, id, major, yr), m_support(sup) {}

QString GradStudent::supportStr(Support sup) 
{
	switch (sup) 
	{                             
	case ta:
		return "ta";
	case ra:
		return "ra";
	case fellowship:
		return "druzyna";
	case other:
		return "inne";
	}
	return "nieznane";
}

QString GradStudent::getClassName() const
{
	return "Magister";
}

QString GradStudent::toString() const
{
	return QString("%1%2%3 ]")
		.arg(Student::toString())
		.arg(" [Stypendium: ")
		.arg(supportStr(m_support));
}