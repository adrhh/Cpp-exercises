#ifndef PERSON_H_
#define PERSON_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using std::ostream;

class Card
{
public:
	enum {kier, pik, karo, trefl};
	enum {Colors = 4};
	enum {Maxvalue = 13};
private:
	int value;
	int color;
	static const char* cv[Colors];
public:
	Card(int v=0, int c=0) : value(v), color(c) {}
	~Card() {};
	const char* get_color() { return cv[color]; }
	int get_value() { return value; }
	friend ostream& operator<<(ostream& os, const Card& cd);
};

class Deck
{
private:
	enum {Maxsize = 52};
	Card deck[Maxsize];
public:
	Deck();
	Card operator[](const int n) const { return deck[n]; }
};

class Person
{
private:
	char* name;
	char* sname;
public:
	Person(const char* n = "brak", const char* s = "brak");
	Person(const Person& p);
	virtual ~Person() { delete[] name; delete[] sname; }
	virtual void Show() const;
	virtual void Set() = 0;
};

class Gunslinger : virtual public Person
{
protected:
	double rtime;
	int marks;
public:
	Gunslinger(const char* n = "brak", const char* s = "brak", double rt = 0, int m = 0) : Person(n, s), rtime(rt), marks(m) {}
	Gunslinger(const Person& p, double rt = 0, int m = 0) : Person(p), rtime(rt), marks(m) {}
	~Gunslinger() {}
	double get_rt() const { return rtime; };
	void Show() const;
	void Data() const;
};

class PokerPlayer : virtual public Person
{
protected:
	Deck talia;
public:
	PokerPlayer(const char* n = "brak", const char* s = "brak") : Person(n,s), talia() {}
	PokerPlayer(const Person& p) : Person(p), talia() {}
	~PokerPlayer() {}
	Card& draw() const;
	void Data() const;
	void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
private:

public:
	BadDude(const char* n = "brak", const char* s = "brak", double rt = 0, int m = 0) : Person(n, s), Gunslinger(n, s, rt, m), PokerPlayer(n, s) {}
	BadDude(const Person& p, double rt = 0, int m = 0) : Person(p), Gunslinger(p, rt, m), PokerPlayer(p) {}
	BadDude(const Gunslinger& g) : Person(g), Gunslinger(g), PokerPlayer(g) {}
	void Show() const;
};

#endif // !PERSON_H_
