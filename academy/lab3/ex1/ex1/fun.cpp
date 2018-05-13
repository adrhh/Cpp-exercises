#include "pch.h"
#include <cmath>

Solution roots(double a, double b, double c)
{
	//return {} tworzy zwracany obiekt zainiclajizowany zerami

	double delta = b*b - 4.0 * a * c;
	if (delta > 0)
	{
		double delataRoot = sqrt(delta);
		double x1 = (-b + delataRoot) / 2.0 * a;
		double x2 = (-b - delataRoot) / 2.0 * a;
		return { x1, x2, 2, false };
	}
	else if (delta == 0)
	{
		double x = -b / 2.0 *a;
		return { x, x, 1, true };
	}

	return {};
}