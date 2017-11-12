#include "complex0.h"

complex::complex()
{
	real = 0.0;
	imag = 0.0;
}
complex::complex(double a, double b)
{
	real = a;
	imag = b;
}

complex complex::operator~()
{
	return complex(real, -imag);
}

complex complex::operator-(complex &i) const
{
	return complex(real - i.real, imag - i.imag);
}
complex complex::operator+(complex &i) const
{
	return complex(real + i.real, imag + i.imag);
}
complex complex::operator*(complex &i) const
{
	double re = real * i.real - imag * i.imag;
	double im = real * i.imag + imag * i.real;
	return complex(re, im);
}
complex operator*(int n, complex &i)
{
	return complex(n*i.real, n*i.imag);
}
istream & operator>>(istream &is, complex &i)
{
	double re;
	double im;
	is >> re >> im;
	i.real = re;
	i.imag = im;
	return is;
}
ostream & operator<<(ostream &os, const complex &i)
{
	os << "(" << i.real << "," << i.imag << "i)";
	return os;
}