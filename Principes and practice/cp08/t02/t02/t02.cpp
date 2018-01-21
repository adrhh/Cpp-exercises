#include <iostream>

using std::cout;
using std::endl;

void swap_v(int, int);
void swap_r(int&, int&);
void swap_cr(const int&, const int&);

int main()
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	cout << x << ", " << y << endl;
	swap_r(x, y);
	cout << x << ", " << y << endl;

	const int cx = x;
	const int cy = y;
	swap_v(cx, cy);
	cout << cx << ", " << cy << endl;
	//swap_r(cx, cy);
	//cout << cx << ", " << cy << endl;

	return 0;
}

void swap_v(int a , int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_cr(const int& a, const int& b)
{
	//cant change const varible
	//int temp = a;
	//a = b;
	//b = temp;
}