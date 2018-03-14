#include "constoverload.h"

Point3::Point3(double x = 0, double y = 0, double z = 0)
{}
double& Point3::operator[](int i)
{}
const double& operator[](int i)  const
{}
Point3 Point3::operator+(const Point3& p) const
{}
Point3 Point3::operator-(const Point3& p) const
{}
Point3 Point3::operator*(double n) const
{}
ostream& operator<<(ostream& os, const Point3 p)
{}