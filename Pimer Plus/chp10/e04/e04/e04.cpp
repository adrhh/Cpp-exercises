#include "sales.h"

int main()
{
	using namespace SALES;

	const int a = 3;
	double temp[a] = { 23.4, 3.4, 101.5 };

	Sales t1(temp, a);
	Sales t2;
	t1.showSales();
	t2.showSales();

	return 0;
}