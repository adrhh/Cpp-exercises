#ifndef POINT_H_
#define POINT_H_

#include <iostream>

using std::istream;

class Point
{
private:
	int x, y, z;
public:
	Point(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c)
	{}
	friend istream& operator>>(istream& is, const Point& p);
	Point& operator=(const Point& p);
};

istream& operator>>(istream& is, Point& p)
{
	//format (x,y,z)
	int tx, ty, tz;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> tx >> ch2 >> ty >> ch3 >> tz >> ch4;

	if (!is)
		return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}
	p = Point(tx, ty, tz);
}

Point& Point::operator=(const Point& p)
{
	if (&p == this)
		return *this;
	x = p.x;
	y = p.y;
	z = p.z;

	return *this;
}

#endif // !POINT_H
