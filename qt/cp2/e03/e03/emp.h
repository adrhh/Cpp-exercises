#ifndef EMP_H_
#define EMP_H_

#include <string>

using std::string;

class Person;
class Position;

class Employer
{
private:
	string name;
	string market;
public:
	Employer(const string& n = "empty", const string& m = "empty");
	bool hire(Person& per, const Position& pos);
	string toString() const;
};

class Position
{
private:
	string name;
	string description;
public:
	Position(const string& n = "empty", const string& d = "empty");
	string toString() const;
};

class Person
{
private:
	string name;
	bool employed;
	Position position;
	Employer employer;
public:
	Person(const string& n = "empty");
	string toString() const;
	bool isEmployed() const;
	void setPosition(const Employer& emp, const Position& p);
};

#endif // !EMP_H_