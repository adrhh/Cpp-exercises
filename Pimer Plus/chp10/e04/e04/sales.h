#ifndef SALES_H_
#define SALES_H_

namespace SALES
{
	class Sales
	{
	private:
		static const int QART = 4;
		double sales[QART];
		double avrg;
		double min;
		double max;
	public:
		Sales();
		Sales(const double ar[], int n);
		void showSales();
	};
}

#endif // !SALES_H
