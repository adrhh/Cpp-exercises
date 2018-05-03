#ifndef KACZKA_H_
#define KACZKA_H_

#include <iostream>

using namespace std;

class Latanie
{
public:
	virtual void lec() = 0;
};

class UmiemLatac : public Latanie
{
	void lec();
};

class NieUmiemLatac : public Latanie
{
	void lec();
};

class LatnieZRakieta : public Latanie
{
	void lec();
};

class Kwakanie
{
public:
	virtual void kwacz() = 0;
};

class Kwacz : public Kwakanie
{
	void kwacz();
};

class NieKwacz : public Kwakanie
{
	void kwacz();
};

class Piszcz : public Kwakanie
{
	void kwacz();
};

class Kaczka
{
protected:
	Latanie* ptrLatanie;
	Kwakanie* ptrKwakanie;
public:
	~Kaczka()
	{
		delete ptrKwakanie;
		delete ptrLatanie;
	}
	virtual void pokazKaczke() = 0;
	void wykonajLec();
	void wykonajKwacz();
	void wykonajPlywaj();
	void ustawLatanie(Latanie* lt);
	void ustawKwakanie(Kwakanie* kw);
};


class DzikaKaczka : public Kaczka
{
public:
	DzikaKaczka();
	~DzikaKaczka() {}
	void pokazKaczke();
};

class ModelKaczki : public Kaczka
{
public:
	ModelKaczki();
	~ModelKaczki() {}
	void pokazKaczke();
};

#endif // !KACZKA_H_
