#include <iostream>
#include <vector>
#include <string>
#include <exception>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Name_value
{
public:
	string str;
	int val;
	Name_value(const string& s = "brak", const int x = 0) : str(s), val(x) {};
};


void error(const string& s)
{
	throw std::runtime_error(s);
}


int main()
{
	vector<Name_value> n_arr;
	string s_temp= " ";
	Name_value temp;
	int i_temp = 0;

	cout << "Podawaj pary, nazwa i liczba q(zakoncz):" << endl;
	try
	{
		while (cin >> s_temp && s_temp != "q" )
		{
			while (!(cin >> i_temp))
			{ 
					cout << "Podaj porawna liczbe"<<endl;
					cin.clear();
					cin.ignore(999, '\n');
			}

			n_arr.push_back(Name_value(s_temp, i_temp));
			for (int i = 0; i < n_arr.size() - 1; i++)
				if (n_arr[i].str == s_temp)
					error("Wartosci nie moga sie powtzrac");
			cout << "Podawaj pary, nazwa i liczba:" << endl;
		}
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
	}

	for (auto x : n_arr)
		cout << x.str << " : " << x.val << endl;

	return 0;
}