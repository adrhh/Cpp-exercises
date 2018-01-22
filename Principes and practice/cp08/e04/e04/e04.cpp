#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print(const vector<int>&, const char*);
void fib(int, int, vector<int>&, int);
int max_int_fib(int, int, vector<int>&);

int main()
{
	vector<int> ftest;
	int n = max_int_fib(1, 1, ftest);
	print(ftest, "");
	cout << "max fib = " << ftest[n] << endl;
}

void print(const vector<int>& v, const char* str)
{
	for (auto i : v)
		cout << str << i << endl;
}

void fib(int x, int y, vector<int>& v, int n)
{
	//error
	if (y > x || n < 2)
		return;

	v.push_back(x);
	v.push_back(y);
	for (int i = 2; i < n; i++)
		v.push_back(v[i - 1] + v[i - 2]);
}

int max_int_fib(int x, int y, vector<int>& v)
{
	//error
	if (y > x )
		return -1;

	v.push_back(x);
	v.push_back(y);
	int i=2;
	for (i = 2; ; i++)
	{ 
		v.push_back(v[i - 1] + v[i - 2]);
		if (v[i] < 0)
			break;
	}
	return i - 1;
}