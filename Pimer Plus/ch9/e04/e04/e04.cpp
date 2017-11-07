/* Write a three-file program based on the following namespace:
namespace SALES
{
const int QUARTERS = 4;
struct Sales
{
double sales[QUARTERS];
double average;
double max;
double min;
};
// copies the lesser of 4 or n items from the array ar
// to the sales member of s and computes and stores the
// average, maximum, and minimum values of the entered items;
// remaining elements of sales, if any, set to 0
void setSales(Sales & s, const double ar[], int n);
// gathers sales for 4 quarters interactively, stores them
// in the sales member of s and computes and stores the
// average, maximum, and minimum values
void setSales(Sales & s);
// display all information in structure s
void showSales(const Sales & s);
}
The first file should be a header file that contains the namespace.The second file
should be a source code file that extends the namespace to provide definitions for
the three prototyped functions.The third file should declare two  Sales objects. It
should use the interactive version of  setSales() to provide values for one struc-
ture and the non-interactive version of  setSales() to provide values for the sec-
ond structure. It should display the contents of both structures by using
showSales() .*/

#include <iostream>
#include "sal.h"

using namespace SALES;

int main()
{
	Sales s1, s2;
	const int a = 3;
	double temp[a] = { 23.4, 3.4, 101.0 };
	
	setSales(s1, temp, a);
	setSales(s2);
	showSales(s1);
	showSales(s2);

	return 0;
}