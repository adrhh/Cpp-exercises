#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using std::ostream;

class Matrix
{
private:
	enum { PREC = 0 };
	int rows;
	int columns;
	double** value;
	static int counter;
	bool is_size_eq(const Matrix& m) const;
public:
	void test_show();
	int get_max_dig();
	double get_max();
	double get_min();
	friend Matrix operator-(const Matrix& m1, const Matrix& m2);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
	Matrix(double** t, int n, int m);
	Matrix();
};

#endif // !MATRIX_H_
