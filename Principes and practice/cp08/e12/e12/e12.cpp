#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::exception;
using std::sort;

struct vecinfo
{
	double avrg;
	double med;
	double max;
	double min;
};

vecinfo* vifo(vector<double> v);
void show(const vecinfo& v);

void error(const string& s)
{
	throw std::runtime_error(s);
}


int main()
{
	try
	{
		vector<double> test = { 9.0, 1.0, 4.0, 14.0, 9.0 };
		vecinfo* testi = vifo(test);
		show(*testi);
		delete testi;
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}

vecinfo* vifo(vector<double> v)
{
	if (v.size())
	{
		double max = v[0];
		double min = v[0];
		double total = 0;
		double med = 0;
		vector<double> tempv = v;
		sort(tempv.begin(), tempv.end());

		if (v.size() % 2)
			med = tempv[tempv.size() / 2];
		else
			med = (tempv[tempv.size() / 2] + tempv[tempv.size() / 2 - 1]) / 2;

		for (auto i : v)
		{ 
			if (i > max)
				max = i;
			if (i < min)
				min = i;
			total += i;
		}
		vecinfo* answ = new vecinfo;
		answ->avrg = total / v.size();
		answ->max = max;
		answ->min = min;
		answ->med = med;
		return answ;
	}
	else
		error("wketor jest pusty");

}

void show(const vecinfo& v)
{
	cout << "max: " << v.max << endl;
	cout << "min: " << v.min << endl;
	cout << "med: " << v.med << endl;
	cout << "avrg: " << v.avrg << endl;
}
