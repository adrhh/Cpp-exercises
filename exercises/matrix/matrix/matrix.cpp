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

bool Matrix::is_mult(const Matrix& m) const
{
	return (columns == m.rows) ? true : false;
}

bool Matrix::is_square() const
{
	return (columns == rows) ? true : false;
}


double Matrix::det_sarrus()
{
	double det;
	if (!is_square())
	{
		cout << "Macierz nie jest kwadratowa" << endl;
		det = 0;
	}
	else
	{
		switch(rows)
		{ 
			case 1:
				det = value[0][0];
				break;
			case 2:
				det = value[0][0] * value[1][1] - value[0][1] * value[1][0];
				break;
			case 3: 
				det = value[0][0] * value[1][1] * value[2][2]
					+ value[0][1] * value[1][2] * value[2][0]
					+ value[0][2] * value[1][0] * value[2][1]
					- value[0][2] * value[1][1] * value[2][0]
					- value[0][1] * value[1][0] * value[2][2]
					- value[0][0] * value[1][2] * value[2][1];
		}
	}
	return det;
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

 Matrix operator*(const Matrix& m1, double x)
{
	double** temp_arr = new double*[m1.rows];
	for (int i = 0; i < m1.rows; i++)
		temp_arr[i] = new double[m1.columns];

	for (int i = 0; i < m1.rows; i++)
		for (int j = 0; j < m1.columns; j++)
			temp_arr[i][j] = m1.value[i][j] * x;

	Matrix matrix(temp_arr, m1.rows, m1.columns);

	for (int i = 0; i < m1.rows; i++)
		delete[] temp_arr[i];

	return matrix;
}

 Matrix operator*(double x, const Matrix& m1)
{
	 return m1 * x;
}

 Matrix operator*(const Matrix& m1, const Matrix& m2)
 {
	 if (!m1.is_mult(m2))
	 {
		 cout << "Error, not equal sizes" << endl;
		 Matrix empty;

		 return empty;
	 }
	 else
	 {
		 int n_rows = m1.rows;
		 int n_columns = m2.columns;
		 double val;
		 double** temp_arr = new double*[n_rows];
		 for (int i = 0; i < n_rows; i++)
			 temp_arr[i] = new double[n_columns];

		 for (int i = 0; i < n_rows; i++)
			 for (int j = 0; j < n_columns; j++)
			 {
				 val = m1.value[i][0] * m2.value[0][j];
				 for (int k = 1; k < m1.columns; k++)
					 val += m1.value[i][k] * m2.value[k][j];

				 temp_arr[i][j] = val;
			 }

		 Matrix matrix(temp_arr, n_rows, n_columns);

		 for (int i = 0; i < n_rows; i++)
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


Matrix Matrix::get_minor(int n, int m)
{
	if (!is_square())
	{
		cout << "Nie mozna utworzyc minoru" << endl;
		Matrix temp;
		return temp;
	}
	else
	{
		if (n > rows || m > columns)
		{
			cout << "Nie mozna utworzyc minoru" << endl;
			Matrix temp;
			return temp;
		}
		else
		{
			double** temp_arr = new double*[rows - 1];
			for (int i = 0; i < rows - 1; i++)
				temp_arr[i] = new double[columns - 1];

			for(int i = 0; i < rows -1; i++)
				for (int j = 0; j < columns - 1; j++)
				{
					int k = i;
					int l = j;
					if (k >= n) k++;
					if (l >= m) l++;

					temp_arr[i][j] = value[k][l];
				}

			Matrix temp(temp_arr, rows - 1, columns - 1);

			delete[] temp_arr;
			return temp;
		}
	}
}


double Matrix::get_det()
{
	if (!is_square())
	{
		cout << "Nie mozna obliczyc wyznacznika" << endl;
		return 0;
	}
	double det;
	int m = rows;
	if (m <= 3)
		return det_sarrus();
	else
	{
		det = 0;
		int multi = 1;
		Matrix* minor_arr = new Matrix[m];
		for (int i = 0; i < m; i++)
			minor_arr[i] = get_minor(0, i);

		for (int i = 0; i < m; i++)
		{ 
			det += multi * value[0][i] * minor_arr[i].get_det();
			multi *= -1;
		}
		for (int i = 0; i < m; i++)
		{ 
			for (int j = 0; j < minor_arr->rows; j++)
				delete[] minor_arr[i].value[j];
			delete[] minor_arr[i].value;
		}

		delete[] minor_arr;
	}
	return det;
}
