#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <cstring>

using std::ostream;

class Card
{
public:
	enum {kier, pik, karo, trefl};
	enum {Colors = 4};
	enum {Maxvalue = 52};
private:
	int value;
	int color;
	static const char* cv[Colors];
public:
	Card(int v=0, int c=0) : value(v), color(c) {};
	~Card() {};
	const char* get_color() { return cv[color]; };
	int get_value() { return value; };
	friend ostream& operator<<(ostream& os, const Card& cd);
};

class Person
{
private:
	char* name;
	char* sname;
public:
	Person(const char* n = "brak", const char* s = "brak");
	~Person() { delete name; delete sname; };

};



#endif // !PERSON_H_
