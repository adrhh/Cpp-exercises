#include "matrix.h"

using namespace std;

int** make2darr(int n, int m);

int main()
{
	int** test;
	test = make2darr(2, 2);

	Matrix t1(test, 2, 2);
	t1.test_show();

	return 0;
}

int** make2darr(int n, int m)
{
	int** temp = new int*[n];
	for (int i = 0; i < n; ++i)
		temp[i] = new int[m];

	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<m; j++) 
		{
			cin >> temp[i][j];
		}
	}

	return temp;
}