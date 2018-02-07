#include <string>
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::string;
using std::vector;

void print_until_s(const vector<string> v, const string quit);
void print_until_ss(const vector<string> v, const string quit);

int main()
{
	vector<string> test = { "raz", "dwa", "raz", "trzy", "cztery", "dwa", "trzy" };
	const string q = test[1];

	print_until_s(test, q);
	print_until_ss(test, q);

	return 0;
}

void print_until_s(const vector<string> v, const string quit)
{
	for (auto i : v)
	{
		if (i == quit)
			break;
		else
			cout << i << endl;
	}
}

void print_until_ss(const vector<string> v, const string quit)
{
	const int max = 2;
	int ic = 0;
	for (auto i : v)
	{
		if (i == quit)
			ic++;
		if (ic == max)
			break;
		cout << i << endl;
	}
}