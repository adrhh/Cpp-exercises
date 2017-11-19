#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using std::ostream;

class Matrix
{
private:
	int rows;
	int columns;
	int** value;
public:
	void test_show();
	int get_max_dig();
	int get_max();
	int get_min();
	Matrix(int** t, int n, int m);
};

#endif // !MATRIX_H_
