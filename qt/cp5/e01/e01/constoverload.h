#ifndef CONSTOVERLOAD_H_
#define CONSTOVERLOAD_H_

#include <iostream>

using std::ostream;

class Point3
{
private:
	static const int Dim = 3;
	double cord[Dim];
public:
	Point3(double x = 0, double y = 0, double z = 0);
	double& operator[](int i);
	const double& operator[](int i)  const;
	Point3 operator+(const Point3& p) const;
	Point3 operator-(const Point3& p) const;
	Point3 operator*(double n) const;
	friend ostream& operator<<(ostream& os, const Point3 p);
};

#endif // !CONSTOVERLOAD_H_
