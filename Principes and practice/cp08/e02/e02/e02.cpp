#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print(const vector<int>&, const char*);

int main()
{
	vector<int> test = { 1,3,4,8,9,0,1,3 };
	print(test, "> ");

	return 0;
}

void print(const vector<int>& v, const char* str)
{
	for (auto i : v)
		cout << str << i << endl;
}