#include "complex.h"


ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.Re << ' ' << c.Im << 'i';
	return out;
}
Complex operator+(const Complex& a, const Complex& b)
{
	return Complex(a.Re + b.Re, a.Im + b.Im);
}
Complex operator-(const Complex& a, const Complex& b)
{
	return Complex(a.Re - b.Re, a.Im - b.Im);
}
Complex operator*(const Complex& a, const Complex& b)
{
	double re, im;
	re = a.Re * b.Re - a.Im * b.Im;
	im = a.Re * b.Im + b.Re * a.Im;
	return Complex(re, im);
}
Complex operator/(const Complex& a, const Complex& b)
{
	double re, im;
	re = a.Re * b.Re + a.Im * b.Im;
	re /= b.Re * b.Re + b.Im * b.Im;
	im =  b.Re * a.Im - a.Re * b.Im;
	im /= b.Re * b.Re + b.Im * b.Im;
	return Complex(re, im);
}
Complex& Complex::operator+=(const Complex& c)
{
	Re += c.Re;
	Im += c.Im;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	Re -= c.Re;
	Im -= c.Im;
	return *this;
}

Complex& Complex::operator*=(double n)
{
	Re *= n;
	Im *= n;
	return *this;
}


bool Complex::operator==(const Complex& c)
{
	if (Re == c.Re && Im == c.Im)
		return true;
	else
		return false;
}
