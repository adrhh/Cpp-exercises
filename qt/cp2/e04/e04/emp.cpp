#include "emp.h"


Position::Position(const std::string& str, const std::string desc)
	: name(str), descirption(desc), employer(nullptr)
{}

std::string Position::toString() const
{
	return std::string(name + ", " + descirption);
}

Employer* Position::getEmployer() const
{
	return employer;
}

void Position::setEmployer(Employer& emp)
{
	employer = &emp;
}

bool Employer::hire(Person& per, Position& pos)
{
	bool ishired = false;
	if (!per.isEmployed())
	{
		employees.push_back(&per);
		pos.setEmployer(*this);
		per.setPosition(*this, pos);
		ishired = true;
	}
	return ishired;
}

std::string Employer::toString() const
{
	return std::string(name + ", " + market);
}


Employer::Employer(const std::string& str, const std::string& mark)
	: name(str), market(mark)
{}

std::string Employer::employeesToString() const
{
	std::string emp_str(name + ", " + market + '\n');
	for (auto emp : employees)
		emp_str += emp->toString() + '\n';

	return emp_str;
}

Person::Person(const std::string& str) : name(str), is_employed(false)
{}

void Person::setPosition(Employer& emp, Position& pos)
{
	employer = &emp;
	position = &pos;
	position->toString();
	is_employed = true;
}

std::string Person::toString() const
{
	std::string str(name);
	if(position)
		str += ", " + position->toString();
	return str;
}

