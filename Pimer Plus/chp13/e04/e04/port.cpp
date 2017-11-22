#include "port.h"
#include <cstring>

using std::endl;
using std::cout;

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}
Port::Port(const Port &p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;

	return *this;
}
Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}
Port& Port::operator-=(int a)
{
	bottles -= a;
	return *this;
}
void Port::show() const
{
	cout << "Marka: " << brand << endl;
	cout << "Styl: " << style << endl;
	cout << "Liczba butelek: " << bottles << endl;
}
ostream& operator<<(ostream& os, const Port& b)
{
	os << "Marka: " << b.brand << endl;
	os << "Styl: " << b.style << endl;
	os<< "Liczba butelek: " << b.bottles << endl;

	return os;
}

VintagePort::VintagePort(const char* br, const char* st, int b, const char* nn, int y):Port(br, st, b)
{
	nickname= new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
void VintagePort::show() const
{
	Port::show();
	cout << "Nazwa: " << nickname << endl;
	cout << "Rocznik: " << year << endl;
}
ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&) vp;
	os << "Nazwa: " << vp.nickname << endl;
	os << "Rocznik: " << vp.year << endl;
	return os;
}