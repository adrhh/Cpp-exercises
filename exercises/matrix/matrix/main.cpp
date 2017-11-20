#include "matrix.h"

using namespace std;

double** make2darr(int n, int m);

int main()
{
	/*
	double** test2;
	test2 = make2darr(3, 3);

	Matrix t1(test2, 3, 3);
	Matrix t3 = t1 * t1;
	t3.test_show();
	cout << t1.det_sarrus() << endl;
	Matrix t4 = t3.get_minor(0, 1);
	t4.test_show(); */

	double** test3;
	test3 = make2darr(4, 4);
	Matrix t5(test3, 4, 4);
	t5.test_show();
	cout << t5.get_det() << endl;


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
			cout << "t[" << i << "][" << j << "]=";
			cin >> temp[i][j];
		}
	}

	return temp;
}