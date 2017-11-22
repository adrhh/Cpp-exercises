#ifndef PORT_H_
#define PORT_H_

#include <iostream>

using std::ostream;

class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "brak", const char* st = "brak", int b = 0);
	Port(const Port &p);
	virtual ~Port() { delete[] brand };
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int a);
	int bcount() const { return bottles };
	virtual void show() const;
	friend ostream& operator<<(ostream& os, const Port& b);
};

class VintagePort : public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort(const char* br, const char* st, int b, const char* nn, int y);
	VintagePort(const VintagePort &vp);
	~VintagePort() { delete[] nickname };
	void show() const;
	friend ostream& operator<<(ostream& os, const VintagePort& vp);
};


#endif // !PORT_H_
