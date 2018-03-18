#include "student.h"
#include <QTextStream>

QString Student::toString() const
{
	QString ret;
	QTextStream os(&ret);
	os << '[' << getClassName() << ']'
		<< " nazwisko: " << name
		<< " id:" << id
		<< " rok:" << year
		<< " kierunek: " << major;
	return ret;
}

QString Undergrad::toString() const
{
	QString ret;
	QTextStream os(&ret);
	os << Student::toString()
		<< " SAT: " << SAT;
	return ret;
}

QString GradStudent::toString() const
{
	QString ret;
	QTextStream os(&ret);
	os << Student::toString()
		<< ' ' << supportStr(support);
	return ret;
}

QString GradStudent::supportStr(Support sup)
{
	QString ret;
	QTextStream os(&ret);

	switch (sup)
	{
	case GradStudent::ta:
		os << "ta";
		break;
	case GradStudent::ra:
		os << "ra";
		break;
	case GradStudent::fellowship:
		os << "fellowship";
		break;
	case GradStudent::other:
	default:
		os << "other";
		break;
	}

	return ret;
}