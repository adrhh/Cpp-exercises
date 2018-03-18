#ifndef STUDENT_H_
#define STUDENT_H_

#include <QString>

class Student
{
private:
	QString name;
	QString major;
	long id;
protected:
	int year;
	QString yearStr() const { return QString("%1").arg(year); }
public:
	Student(QString nm, long i, QString maj, int y = 1) 
		: name(nm), id(i), major(maj), year(y) {}
	~Student() {};
	QString getClassName() const { return QString("Student"); }
	QString toString() const;
};

class Undergrad : public Student
{
private:
	int SAT;
public:
	Undergrad(QString nm, long i, QString maj, int y, int sat) 
		: Student(nm, i, maj, y), SAT(sat) {}
	QString getClassName() const { return QString("Undergrad"); }
	QString toString() const;
};

class GradStudent : public Student
{
public:
	enum Support{ta, ra, fellowship, other};
	GradStudent(QString nm, long i, QString maj, int y, Support sup)
		: Student(nm, i, maj, y), support(sup) {}
	QString getClassName() const { return QString("GradStudent"); }
	QString toString() const;
private:
	Support support;
protected:
	static QString supportStr(Support sup);
};



#endif // !STUDENT_H_