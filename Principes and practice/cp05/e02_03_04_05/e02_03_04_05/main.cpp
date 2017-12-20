#include <iostream>
#include <exception>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

double ctok(double c);
void error(const string& s);
const double Min_celc = -273.15;

int main()
{
	double c = 0, k =0;
	cout << "Podaj temperature w Celcjuszach: " << endl;
	cin >> c;
	while (cin.get() != '\n')
		continue;
	try
	{
		k = ctok(c);
		cout << c << "C = " << k << "K" << endl;
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
	}

}

double ctok(double c)
{
	if (c < Min_celc)
	{
		string emsg = "Tmepratura nie moze byc mniejsza niz: " + std::to_string(Min_celc);
		error(emsg);
	}
	return c + 273.15;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}