#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::cin;

void sort_sd(vector<string>& s, vector<double>& d);
void print(const vector<string>&, const vector<double>& d);

int main()
{
	const int MAX_I = 5;
	vector<string> vs;
	vector<double> vd;
	string temps;
	double tempd;
	int i = 0;
	while (i++ < MAX_I)
	{
		cout << "podaj imie:" << endl;
		cin >> temps;
		vs.push_back(temps);
	}

	i = 0;
	while (i++ < MAX_I)
	{
		cout << "podaj ocene:" << endl;
		cin >> tempd;
		vd.push_back(tempd);
	}

	print(vs, vd);
	sort_sd(vs, vd);
	print(vs, vd);

	return 0;
}

void sort_sd(vector<string>& s, vector<double>& d)
{
	vector<string> temp_s;
	for (int i = 0; i < s.size(); i++)
		temp_s.push_back(s[i]);

	vector<double> temp_d;
	for (int i = 0; i < d.size(); i++)
		temp_d.push_back(d[i]);

	sort(s.begin(), s.end());

	for(int i = 0; i < s.size(); i++)
		for (int j = 0; j < temp_s.size(); j++)
		{
			if (s[i] == temp_s[j])
			{
				d[i] = temp_d[j];
				break;
			}
		}
}

void print(const vector<string>& s, const vector<double>& d)
{
	if (s.size() != d.size())
		return;

	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " : " << d[i] << endl;
}