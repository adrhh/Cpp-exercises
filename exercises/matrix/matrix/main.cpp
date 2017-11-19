#include "matrix.h"

using namespace std;

double** make2darr(int n, int m);

int main()
{
	double** test;
	test = make2darr(2, 2);

	Matrix t1(test, 2, 2);
	Matrix t2(test, 2, 2);
	Matrix t3 = t1 + t2;
	t3.test_show();

	return 0;
}

double** make2darr(int n, int m)
{
	double** temp = new double*[n];
	for (int i = 0; i < n; ++i)
		temp[i] = new double[m];

	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<m; j++) 
		{
			cin >> temp[i][j];
		}
	}

	return temp;
}