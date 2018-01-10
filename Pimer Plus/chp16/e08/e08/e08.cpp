#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::set_union;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;


int main()
{
	string temp;
	vector<string> Bolek;
	vector<string> Lolek;

	cout << "Podaj gosci Bolka (q-zakoncz)" << endl;
	while (cin >> temp && temp != "q")
		Bolek.push_back(temp);

	sort(Bolek.begin(), Bolek.end());

	cout << "Podaj gosci Lolka (q-zakoncz)" << endl;
	while (cin >> temp && temp != "q")
		Lolek.push_back(temp);

	sort(Lolek.begin(), Lolek.end());

	vector<string> bil(Bolek.size() + Lolek.size());
	auto it = set_union(Bolek.begin(), Bolek.end(), Lolek.begin(), Lolek.end(), bil.begin());
	bil.resize(it - bil.begin());
	
	for (auto i : bil)
		cout << i << ' ';

	return 0;
}