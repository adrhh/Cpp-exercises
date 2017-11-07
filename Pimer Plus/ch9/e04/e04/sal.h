#ifndef SAL_H_
#define SAL_H_

namespace SALES
{
	const int QART = 4;

	struct Sales
	{
		double sales[QART];
		double avrg;
		double min;
		double max;
	};
};

void setSales(SALES::Sales & s, const double ar[], int n);
void setSales(SALES::Sales & s);
void showSales(const SALES::Sales & s);

#endif // !SAL_H_
