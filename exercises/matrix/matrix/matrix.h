#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using std::ostream;

class Matrix
{
private:
	double rows;
	double columns;
	double** value;
public:
	void test_show();
	int get_max_dig();
	double get_max();
	double get_min();
	Matrix(double** t, int n, int m);
};

#endif // !MATRIX_H_
