#ifndef STUDENT_H_
#define STUDENT_H_

#include <QString>

class Student
{
public:
	Student(QString nm, long id, QString major, int year = 1);
	~Student() = default;
	QString getClassName() const;
	QString toString() const;
	int yearInt() const;
private:
	QString m_name;
	QString m_major;
	long m_studentId;
protected:
	int m_year;
	QString yearStr() const;
	
};

class Undergrad : public Student
{
public:
	Undergrad(QString nm, long id, QString major, int yr, int sat);
	QString getClassName() const;
	QString toString() const;
private:
	int m_SAT;
};

class GradStudent :public Student
{
public:
	enum Support {ta, ra, fellowship, other};
	GradStudent(QString nm, long id, QString major, int yr, Support sup);
	QString getClassName() const;
	QString toString() const;
protected:
	static QString supportStr(Support sup);
private:
	Support m_support;
};

#endif // !STUDENT_H_
