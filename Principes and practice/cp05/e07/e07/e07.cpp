#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;

vector<double> pier(int a, int b, int c);
void error(const string& s);

int main()
{
	int a, b, c;
	vector<double> x;

	cout << "Podaj wspolczynniki rownania kwadratowego:" << endl;
	while (cin >> a >> b >> c)
	{
		try 
		{
			x = pier(a, b, c);
		}
		catch (std::runtime_error& e)
		{
			cout << e.what() << endl;
			continue;
		}
		cout << "Rozwiazanie rownania: "
			<< a << "*x^2 + " << b << "*x + " << c << endl;
		for (unsigned int i = 0; i < x.size(); i++)
			cout << "x" << i << " = " << x[i] << ' ';
		cout << endl;
		while (x.size())
			x.pop_back();
	}

	return 0;
}

vector<double> pier(int a, int b, int c)
{
	double delta;
	delta = b*b - 4 * a*c;

	if (delta < 0)
	{
		string msg = "\nDelta mniejsza od zera, brak rozwiazan w zbiorze liczb rzeczywistych.\n";
		error(msg);
	}
	
	vector<double> temp;
	if (!delta)
		temp.push_back(delta / 2 * a);
	else
	{
		double x1 = (-b - delta) / 2 * a;
		double x2 = (-b + delta) / 2 * a;
		temp.push_back(x1);
		temp.push_back(x2);
	}
	return temp;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}