#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>

using std::endl;
using std::cout;

class Rational
{
private:
	int numerator;
	int denominator;
public:
	class Invalid
	{};
	Rational(int a = 0, int b = 1);
	double get_d() const;
	void show() const;
	Rational operator+(const Rational& r);
};

Rational::Rational(int a, int b) : numerator(a), denominator(b)
{
	if (b == 0)
		throw Invalid();
}

double Rational::get_d() const
{
	return static_cast<double>(numerator) / static_cast<double>(denominator);
}

Rational Rational::operator+(const Rational& r)
{
	int den_temp1 = denominator;
	int num_temp1 = numerator;
	int den_temp2 = r.denominator;
	int num_temp2 = r.numerator;
	if (den_temp1 != den_temp2)
	{
		num_temp2 *= den_temp1;
		num_temp1 *= den_temp2;
		den_temp1 *= den_temp2;
	}
	return Rational(num_temp1 + num_temp2, den_temp1);
}

void Rational::show() const
{
	cout << numerator << endl;
	cout << denominator << endl;
}

#endif // !RATIONAL_H_
