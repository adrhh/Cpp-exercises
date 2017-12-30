#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::cerr;

void error(const string& s);
string decomposition(const string& s);

vector<string> Digs =
{ "zero", "jeden" , "dwa", "trzy", "cztery",
"piec", "szesc", "siedem", "osiem", "dziewiec" };

int main()
{

	cout << "Podaj liczbe calkowta" << endl;
	string ins;
	try
	{
		while (cin >> ins)
			cout << decomposition(ins) << endl;
	}
	catch (std::exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}

string decomposition(const string& s)
{
	int multiper = pow(10, s.length() - 1);
	int dig;
	string answ;
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			error(s + " nie jest poprawna liczba");
		dig = s[i] - '0';
		answ += Digs[dig] + " * " + to_string(multiper) + ',';
		multiper /= 10;
	}
	return answ;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}