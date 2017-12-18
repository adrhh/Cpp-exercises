#include <iostream>
#include <cmath>
#include "e_mean.h"

using std::cin;
using std::cout;
using std::endl;

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Podaj dwie liczby:" << endl;
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "srednia harmoniczna wynosi: " << z << endl;
			z = gmean(x, y);
			cout << "srednia geometryczna wynosi: " << z << endl;
		}
		catch (bad_hmean& e)
		{
			cout << e.what() << endl;;
		}
		catch (bad_gmean& e)
		{
			cout << e.what() << endl;
		}
		cout << "Podaj kolejne liczby: " << endl;
	}
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean();
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean();
	return std::sqrt(a * b);
}