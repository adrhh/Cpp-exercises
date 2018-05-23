#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "pch.h"

class Employee
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
};

class Tester : public Employee
{
public:
	Tester(const PersonData& pd, double salary) : Employee(pd, salary) {}
	double getSalary() const { return salary; }
};

class Manager : public Employee
{
public:
	Manager(const PersonData& pd, double salary) : Employee(pd, salary) {}
	double getSalary() const { return salary; }
};


#endif 