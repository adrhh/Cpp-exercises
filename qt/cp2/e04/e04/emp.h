#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <vector>

class Employer;
class Person;

class Position
{
private:
	std::string name;
	std::string descirption;
	Employer* employer;
public:
	Position(const std::string& str, const std::string desc);
	std::string toString() const;
	Employer* getEmployer() const;
	void setEmployer(Employer& emp);
};

class Employer
{
private:
	std::string name;
	std::string market;
	std::vector<Person*> employees;
public:
	bool hire(Person& per, Position& pos);
	Employer(const std::string& str, const std::string& mark);
	std::string toString() const;
	std::string employeesToString() const;
};

class Person
{
private:
	std::string name;
	bool is_employed;
	Position* position;
	Employer* employer;
public:
	Person(const std::string& str);
	void setPosition(Employer& emp, Position& pos);
	std::string toString() const;
	bool isEmployed() const { return is_employed; }
};


#endif