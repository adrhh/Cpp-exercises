#include "emp.h"

Position::Position(const string& n, const string& d) : name(n), description(d)
{

}

string Position::toString() const
{
	string temp;
	temp = name + " : " + description;

	return temp;
}

Employer::Employer(const string& n, const string& m) : name(n), market(m)
{

}

bool Employer::hire(Person& per, const Position& pos)
{
	if (!per.isEmployed())
	{
		per.setPosition(*this, pos);
		return true;
	}
	else
		return false;
}

string Employer::toString() const
{
	string temp;
	temp = name + " : " + market;

	return temp;
}

void Person::setPosition(const Employer& emp, const Position& p)
{
	position = p;
	employer = emp;
}

Person::Person(const string& n) : name(name), employed(false)
{
	Employer eempty;
	Position pempty;
	employer = eempty;
	position = pempty;
}

bool Person::isEmployed() const
{
	return employed;
}