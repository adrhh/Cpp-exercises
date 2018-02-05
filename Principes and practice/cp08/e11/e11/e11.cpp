#include <iostream>
#include <vector>
#include <exception>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::exception;

int maxw(vector<int> v);

void error(const string& s)
{
	throw std::runtime_error(s);
}


int main()
{
	try
	{ 
		vector<int> test = { 9,1,4,14,9 };
		cout << maxw(test) << endl;
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}

int maxw(vector<int> v)
{
	if (v.size())
	{
		int max = v[0];
		for (auto i : v)
			if (i > max)
				max = i;
		return max;
	}
	else
		error("wketor jest pusty");

}