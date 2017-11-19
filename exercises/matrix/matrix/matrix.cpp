#include "matrix.h"
#include <iomanip>;

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::setprecision;


Matrix::Matrix(double** t, int n, int m)
{
	value  = new double*[n];
	for (int i = 0; i < n; ++i)
		value[i] = new double[m];

	rows = n;
	columns = m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			value[i][j] =  t[i][j];
}

int Matrix::get_max_dig()
{
	double max = get_max();
	double min = get_min();
	double abs_max;
	int digs = 0;

	if (min < 0)
		min *= -1;

	abs_max = (max > min) ? max : min;
	while (abs_max > 1)
	{ 
		digs++;
		abs_max /= 10;
	}
		

	return digs;
}

double Matrix::get_max()
{
	double max = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (max < value[i][j])
				max = value[i][j];

	return max;
}

double Matrix::get_min()
{
	double min = 99999;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (min > value[i][j])
				min = value[i][j];

	return min;
}

void Matrix::test_show()
{
	int prec = get_max_dig() + 1;

	for (int i = 0; i  <rows; i++)
	{
		if(!i)
		{
			cout << ' ';
			for (int j = 0; j < columns*prec + 1; j++)
				cout << '-';
			cout << ' ';
			cout << endl;
		}

		for (int j = 0; j < columns; j++)
		{
			char space;
			if (!j)
				cout << '|';
			cout << setfill(' ') << setw(prec) << left << setprecision(prec)
				<< value[i][j];
			space = (j != columns - 1) ? ' ' : '|';
			cout << space;
		}
		cout << endl;
		if (i == rows-1)
		{ 
			cout << ' ';
			for (int j = 0; j < columns*prec + 1; j++)
				cout << '-';
			cout << ' ';
			cout << endl;
		}
	}
}
