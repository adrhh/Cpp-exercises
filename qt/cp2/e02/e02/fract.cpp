#include "fract.h"
#include <iostream>

using std::cerr;

int nwd(int a, int b)
{
	int n;
	if (b == 0)
		n = a;
	else
		n = nwd(b, a%b);
	return n;
}

int nww(int a, int b)
{
	return a*b / nwd(a, b);
}

void Fraction::set(int n, int m)
{
	numer = n;
	if (m != 0)
		deno = m;
	else
	{	
		cerr << "Error div by 0";
		m = -1;
	}
		
}

double Fraction::toDouble() const
{
	if (deno != 0)
		return (numer * 1.0) / deno;
	else
	{
		cerr << "Error div by 0";
		return -1;
	}
}

QString Fraction::toString() const
{
	return QString("%1 / %2").arg(numer).arg(deno);
}

Fraction Fraction::add(const Fraction& fr)
{
	int den = nww(deno, fr.deno);
	int a = numer * den / deno;
	int b = fr.numer * den / fr.deno;

	return Fraction(a + b, den);
}
Fraction Fraction::sub(const Fraction& fr)
{
	int den = nww(deno, fr.deno);
	int a = numer * den / deno;
	int b = fr.numer * den / fr.deno;

	return Fraction(a - b, den);
}
Fraction Fraction::mult(const Fraction& fr)
{
	int a = numer * fr.numer;
	int b = deno * fr.deno;

	return Fraction(a, b);
}
Fraction Fraction::div(const Fraction& fr)
{
	int a = numer * fr.deno;
	int b = deno * fr.numer;

	return Fraction(a, b);
}