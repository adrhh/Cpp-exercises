#ifndef COMPLEX0_H_
#define COMPLEX0_J

#include <iostream>
using std::istream;
using std::ostream;

class complex
{
private:
	double real;
	double imag;
public:
	complex();
	complex(double a, double b);
	complex operator-(complex &i) const;
	complex operator+(complex &i) const;
	complex operator*(complex &i) const;
	complex operator~();
	friend complex operator*(int n, complex &i);
	friend complex operator*(complex &i, int n)
	{
		return n*i;
	}
	friend istream & operator>>(istream &is, complex &i);
	friend ostream & operator<<(ostream &os, const complex &i);
};


#endif // !COMPLEX0_H_
