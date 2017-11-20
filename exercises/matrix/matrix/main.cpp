#include "matrix.h"

using namespace std;

double** make2darr(int n, int m);

int main()
{

	double** test2, ** test3;
	test2 = make2darr(3, 3);
	test3 = make2darr(3, 3);

	Matrix t1(test2, 3, 3);
	Matrix t2(test3, 3, 3);
	Matrix t3 = t1 * t2;
	t3.test_show();
	cout << t1.det_sarrus() << endl;


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