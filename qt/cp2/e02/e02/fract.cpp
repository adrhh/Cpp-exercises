#include "fract.h"

double Fraction::toDouble() const
{
	if (deno != 0)
		return (numer * 1.0) / deno;
	else
		return -1;
}

QString Fraction::toString() const
{
	return QString("%1 / %2").arg(numer).arg(deno);
}