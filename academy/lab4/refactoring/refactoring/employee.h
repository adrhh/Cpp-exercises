#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "pch.h"

class DbObserver
{
public:
	virtual void actualization() = 0;
};

class Employee : public DbObserver
{
protected:
	PersonData personData;
	double salary;
public:
	Employee(const PersonData& pd, double salary) : personData(pd), salary(salary) {};
	virtual double getSalary() const = 0;
};

class Developer : public Employee
{
public:
	Developer(const PersonData& pd, double salary) : Employee(pd, salary) {}
	double getSalary() const { return salary; }
	void actualization() {}
};

class Tester : public Employee
{
public:
	Tester(const PersonData& pd, double salary) : Employee(pd, salary) {}
	double getSalary() const { return salary; }
	void actualization() {}
};

class Manager : public Employee
{
private:
	int hrMessages;
public:
	Manager(const PersonData& pd, double salary) : Employee(pd, salary), hrMessages(0) {}
	double getSalary() const { return salary; }
	void actualization() { hrMessages++; }
};

class CEO : public Employee, public DbObserver
{
private:
	int hrMessages;
public:
	CEO(const PersonData& pd, double salary) : Employee(pd, salary), hrMessages(0) {}
	double getSalary() const { return salary; }
	void actualization() { hrMessages++; }
};

#endif 