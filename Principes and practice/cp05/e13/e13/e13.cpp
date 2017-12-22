#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;

string to_lower(const string& s);

int main()
{
	vector<string> Week_day
	{
		"Poniedzialek", "Wtorek", "Sroda",
		"Czwartek", "Piatek", "Sobota",
		"Niedziela"
	};

	vector<string> days_input;
	vector<int> values;
	const int Week_max = 7;
	int i = Week_max;
	while (i--)
	{
		cout << "Podaj dzien tygodnia" << endl;
		string temp_s;
		while (cin >> temp_s)
		{
			bool isok = false;
			for (int i = 0; i < Week_day.size(); i++)
			{
				if (to_lower(temp_s) == to_lower(Week_day[i]) )
				{				
					isok = true;
					break;
				}
				//check first 3;
				int k = 0;
				for (int j = 0; j < temp_s.size(); j++)
				{
					if (k == 2)
					{
						isok = true;
						break;
					}
					else if (k > 2)
						break;
					if (tolower(temp_s[j]) == tolower(Week_day[i][j]))
						k++;
				}
			}

			if(isok)
			{ 
				days_input.push_back(temp_s);
				isok = false;
				break;
			}
			cout << temp_s << endl;
			cout << "Podaj poprawny dzien tygodnia" << endl;
		}

		cout << "Podaj wartosc: " << endl;

		int n;
		cin.clear();
		while (!(cin >> n)) 
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Podaj liczbe calkowita." << endl;
		}
		values.push_back(n);
	}

	for (int i = 0; i < values.size(); i++)
		cout << days_input[i] << " : " << values[i] << endl;

	return 0;
}

string to_lower(const string& s)
{
	string temp;
	for (int i = 0; i < s.size(); i++)
		temp.push_back(tolower(s[i]));
	return temp;
}