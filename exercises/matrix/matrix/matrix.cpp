#include "matrix.h"
#include <iomanip>;

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::left;


Matrix::Matrix(int** t, int n, int m)
{
	value  = new int*[n];
	for (int i = 0; i < n; ++i)
		value[i] = new int[m];

	rows = n;
	columns = m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			value[i][j] =  t[i][j];
}

int  Matrix::get_max_dig()
{
	int max = get_max();
	int min = get_min();
	int abs_max, digs = 0;

	if (min < 0)
		min *= -1;

	abs_max = (max > min) ? max : min;
	while (abs_max /= 10)
		digs++;

	return digs;
}

int Matrix::get_max()
{
	int max = INT_MIN;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (max < value[i][j])
				max = value[i][j];

	return max;
}

int Matrix::get_min()
{
	int min = INT_MAX;

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
			cout << setfill(' ') << setw(prec) << left
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
