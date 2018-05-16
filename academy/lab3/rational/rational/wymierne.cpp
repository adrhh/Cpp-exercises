#include "wymierne.h"
#include <cassert>
#include "pch.h"

int gcd(int a, int b)
{
	while (b != 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

Rational::Rational(int nom, int den)
{
	assert(den != 0);
	int d = gcd(nom, den);
	nominator = nom / d;
	denominator = den / d;
}

Rational& Rational::operator+=(const Rational& r)
{
	return *this;
}

Rational& Rational::operator-=(const Rational& r)
{
	return *this;
}

std::ostream& operator<<(std::ostream& os, Rational a)
{
	return os << a.getNominator() << '/' << a.getDenomiator();
}