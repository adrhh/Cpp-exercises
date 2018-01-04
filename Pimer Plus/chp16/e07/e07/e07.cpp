#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::for_each;
using std::random_shuffle;

vector<int> draw(int max_size, int n);

int main()
{
	int i, j;
	cout << "Podaj liczbe wszytkich numerow i liczbe numerow na kuponie" << endl;
	cin >> i >> j;
	auto test = draw(i, j);
	cout << "wynik losowania:" << endl;
	for (auto i : test)
		cout << i << ' ';
	cout << endl;

	return 0;
}

vector<int> draw(int max_size, int n)
{
	vector<int> winners(n);
	vector<int> all;
	for (int i = 0; i < max_size; i++)
		all.push_back(i + 1);

	random_shuffle(all.begin(), all.end());
	
	auto it = all.begin();
	for (int i = 0; i < winners.size(); i++)
		winners[i] = *(it++);

	/*for_each(all.begin(), all.end(), [](int v) {cout << v << ' '; });
	for_each(winners.begin(), winners.end(), [](int v) {cout << v << ' '; });*/
	
	return winners;
}