#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::sort;

vector<int> letters_count(const vector<string> v );
string longest_s(const vector<string> v);
string shortest_s(const vector<string> v);
string min(const vector<string> v);
string max(const vector<string> v);

int main()
{
	vector<string> test = { "raz", "dwa", "raz", "trzy", "cztery", "dwa", "trzy" };
	vector<int> ctest = letters_count(test);

	for (auto i : ctest)
		cout << i << " ";
	cout << endl;

	cout << longest_s(test) << endl;
	cout << shortest_s(test) << endl;
	cout << min(test) << endl;
	cout << max(test) << endl;

	return 0;
}

vector<int> letters_count(const vector<string> v)
{
	vector<int> counter;
	for (auto i : v)
		counter.push_back(i.size());

	return counter;
}

string longest_s(const vector<string> v)
{
	string l = "";

	for (auto i : v)
		if (i.length() > l.length())
			l = i;

	return l;
}

string shortest_s(const vector<string> v)
{
	string s = "";
	int min = s.max_size();

	for (auto i : v)
		if (i.length() < min)
		{
			min = i.length();
			s = i;
		}
			
	return s;
}

string min(const vector<string> v)
{
	vector<string> temp = v;
	sort(temp.begin(), temp.end());

	return temp[0];

}

string max(const vector<string> v)
{
	string max;
	vector<string> temp = v;
	sort(temp.rbegin(), temp.rend());

	return temp[0];
}