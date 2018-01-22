#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::for_each;
using std::endl;

vector<string> reverse(const vector<string>& v);
void reverse_r(vector<string>& v);
void print(const vector<string>&, const char*);

int main()
{
	vector<string> test = { "asd", "badad", "kaka", "oobba", "zuua" };
	vector<string> test_r = reverse(test);
	print(test, "");
	cout << endl;
	print(test_r, "");
	cout << endl;
	reverse_r(test);
	cout << endl;
	print(test, "");

	return 0;
}

vector<string> reverse(const vector<string>& v)
{
		vector<string> r;
		for_each(v.rbegin(), v.rend(), [&r](string str) {r.push_back(str); });
		return r;
}

void print(const vector<string>& v, const char* str)
{
	for (auto i : v)
		cout << str << i << endl;
}

void reverse_r(vector<string>& v)
{
	int j = v.size() - 1;
	int half_s = v.size() / 2;

	for (int i = 0; i < half_s; i++, j--)
	{
		string temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
}