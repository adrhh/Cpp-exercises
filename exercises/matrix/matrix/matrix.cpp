#include "matrix.h"
#include <iomanip>
#include <cfloat>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::setprecision;


int Matrix::counter = 0;

Matrix::Matrix()
{
	rows = 1;
	columns = 1;
	value = new double*[1];
	value[0] = new double[1];
	value[0][0] = 0;
}


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

	counter++;
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
	double max = DBL_MIN;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (max < value[i][j])
				max = value[i][j];

	return max;
}

double Matrix::get_min()
{
	double min = DBL_MAX;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (min > value[i][j])
				min = value[i][j];

	return min;
}

bool Matrix::is_size_eq(const Matrix& m) const
{
	return (columns == m.columns && rows == m.rows) ? true : false;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	if (!m1.is_size_eq(m2))
	{
		cout << "Error, not equal sizes" << endl;
		Matrix empty;

		return empty;
	}
	else
	{
		double** temp_arr = new double*[m1.rows];
		for (int i = 0; i < m1.rows; i++)
			temp_arr[i] = new double[m1.columns];

		for (int i = 0; i < m1.rows; i++)
			for (int j = 0; j < m1.columns; j++)
				temp_arr[i][j] = m1.value[i][j] + m2.value[i][j];

		Matrix matrix(temp_arr, m1.rows, m1.columns);

		for (int i = 0; i < m1.rows; i++)
			delete[] temp_arr[i];

		return matrix;
	}
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	if (!m1.is_size_eq(m2))
	{
		cout << "Error, not equal sizes" << endl;
		Matrix empty;

		return empty;
	}
	else
	{
		double** temp_arr = new double*[m1.rows];
		for (int i = 0; i < m1.rows; i++)
			temp_arr[i] = new double[m1.columns];

		for (int i = 0; i < m1.rows; i++)
			for (int j = 0; j < m1.columns; j++)
				temp_arr[i][j] = m1.value[i][j] - m2.value[i][j];

		Matrix matrix(temp_arr, m1.rows, m1.columns);

		for (int i = 0; i < m1.rows; i++)
			delete[] temp_arr[i];

		return matrix;
	}
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
			cout << setfill(' ') << setw(prec) << left << setprecision(PREC)
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
