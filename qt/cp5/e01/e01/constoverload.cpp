#include "constoverload.h"

static double zero = 0.0;


double& Point3::operator[](int i)
{
	if (i >= 0 && i < Dim)
		return cord[i];
	else
	{
		zero = i;
		return zero;
	}
}
const double& Point3::operator[](int i) const
{
	if (i >= 0 && i < Dim)
		return cord[i];
	else
	{
		zero = i;
		return zero;
	}
}

Point3::Point3(double x, double y, double z)
{
	cord[0] = x;
	cord[1] = y;
	cord[2] = z;
}

Point3 Point3::operator+(const Point3& p) const
{
	Point3 temp;
	for (int i = 0; i < Dim; i++)
		temp.cord[i] = p.cord[i] + cord[i];

	return temp;
}

Point3 Point3::operator-(const Point3& p) const
{
	Point3 temp;
	for (int i = 0; i < Dim; i++)
		temp.cord[i] = p.cord[i] + cord[i];

	return temp;
}


Point3 Point3::operator*(double n) const
{
	Point3 temp;
	for (int i = 0; i < Dim; i++)
		temp.cord[i] = cord[i] * n;

	return temp;
}

ostream& operator<<(ostream& os, const Point3 p)
{
	os << '(' << p.cord[0] << ", " << p.cord[1] << ", " << p.cord[2] << ')';
	return os;
}