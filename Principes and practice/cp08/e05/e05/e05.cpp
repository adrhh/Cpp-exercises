#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::for_each;

void swap_r(int& a, int& b);
vector<int> reverse(const vector<int>& v);
void reverse_r(vector<int>& v);
void print(const vector<int>&, const char*);

int main()
{
	vector<int> test = { 1,2,3,4,5,6,7,8,9 };
	vector<int> rtest = reverse(test);
	print(test, "");
	cout << '\n';
	print(rtest, "");
	cout << '\n';
	reverse_r(test);
	print(test, "");

	return 0;
}

void swap_r(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

vector<int> reverse(const vector<int>& v)
{
	vector<int> r;
	for_each(v.rbegin(), v.rend(), [&r](int i) {r.push_back(i); });
	return r;
}

void print(const vector<int>& v, const char* str)
{
	for (auto i : v)
		cout << str << i << endl;
}

void reverse_r(vector<int>& v)
{
	int j = v.size() - 1;
	int half_s = v.size() / 2;
	for (int i = 0; i < half_s; i++, j--)
		swap_r(v[i], v[j]);
}