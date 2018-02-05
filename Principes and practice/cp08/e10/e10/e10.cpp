#include <exception>
#include <iostream>
#include <string>
#include <vector>

using std::runtime_error;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::exception;

void error(const string& s)
{
	throw std::runtime_error(s);
}

double mult(vector<double> p, vector<double> w)
{
	double answ = 0;
	if (w.size() <= p.size())
		for (int i = 0; i < w.size(); i++)
			answ += w[i] * p[i];
	else
		error("zbyt mala tablica w");
	return answ;
}

int main()
{
	try
	{ 
	vector<double> test = { 1, 2, 6 };
	cout << mult(test, test);
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	return 0;
}