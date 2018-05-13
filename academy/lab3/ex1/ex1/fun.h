#include "pch.h"

#ifndef FUN_H_
#define FUN_H_

struct Solution
{
	double x1;
	double x2;
	int count;
	bool identity; //rownanie tozszamosiowe
	//bool operator==(const Solution& s);
};

Solution roots(double a, double b, double c);

#endif // !FUN_H_
