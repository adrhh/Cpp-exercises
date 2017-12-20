#include <iostream>
#include <exception>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const double Min_celc = -273.15;
const double Min_far = -459.67;
double ctof(double c);
double ftoc(double f);
void error(const string& s);


int main()
{
	char ch =' ';
	double t;
	double answ;

	while (ch != 'q')
	{
		cout << "przeliczanie temperatur c->f lub f->c" << endl;
		cout << "wpisz f,c lub q-by zakonczyc" << endl;
		cin.get(ch);
		while (cin.get() != '\n')
			continue;

		switch (ch)
		{
		case 'c':
			cout << "podaj temp w Celcjuszach" << endl;
			cin >> t;
			while (cin.get() != '\n')
				continue;
			try
			{
				answ = ctof(t);
				cout << t << "C = " << answ << "F" << endl;
			}
			catch (std::runtime_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		case 'f':
			cout << "podaj temp w Fahrenheitach" << endl;
			cin >> t;
			while (cin.get() != '\n')
				continue;
			try
			{
				answ = ftoc(t);
				cout << t << "F = " << answ << "C" << endl;
			}
			catch (std::runtime_error& e)
			{
				cout << e.what() << endl;
			}
			break;

		default:
			cout << "wpisz f,k lub q-by zakonczyc" << endl;
		}
	}

	return 0;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}

double ctof(double c)
{
	if (c < Min_celc)
	{
		string emsg = "Tmepratura nie moze byc mniejsza niz: " + std::to_string(Min_celc);
		error(emsg);
	}
	return ( 9.0 / 5.0 ) * c + 32;
}

double ftoc(double f)
{
	if (f < Min_far)
	{
		string emsg = "Tmepratura nie moze byc mniejsza niz: " + std::to_string(Min_far);
		error(emsg);
	}
	return 5.0 / 9.0  * (f - 32);
}
