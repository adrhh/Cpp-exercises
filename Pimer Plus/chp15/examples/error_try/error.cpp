#include <iostream>

using namespace std;

double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "Podaj dwie liczby" << endl;
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "Podaj kolejna pare liczb" << endl;
			continue;
		}
		cout << "Srenia harmoniczna wynosi " << hmean(x, y) << endl;
		cout << "Podaj kolejna pare liczb" << endl;
	}

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "Nie poprawny argument, a = -b powdoje dzielenie przez zero";
	return 2.0 * a*b / (a + b);
}
 