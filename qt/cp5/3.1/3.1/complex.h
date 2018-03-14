#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

using std::ostream;

class  Complex
{
public:
	Complex(double re = 0.0, double im = 0.0) : Re(re), Im(im)
	{}
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend Complex operator+(const Complex& a, const Complex& b);
	friend Complex operator-(const Complex& a, const Complex& b);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend Complex operator/(const Complex& a, const Complex& b);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	bool operator==(const Complex& c);
private:
	double Re;
	double Im;
};

#endif // !COMPLEX_H_
