#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	vector<string> test;

	cout << "Podawaj slowa (ctrl + z  by zakonczyc):" << endl;
	string temp;
	while (cin >> temp)
		test.push_back(temp);

	sort(test.begin(), test.end());

	string dominata;
	int max_c = 0;

	for (int i = 0; i<test.size() - 1; i++)
	{
		int count = 0;
		temp = test[i];
		while (test[i] == test[i + 1])
		{
			count++;
			i++;
		}
		if (max_c < count)
		{
			max_c = count;
			dominata = temp;
		}
	}

	cout << "dominata zbioru jest: " << dominata << endl;
	cout << "pierwysz wyraz: " << test.front() << " ostani wyraz: " << test.back() << endl;
}