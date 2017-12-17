#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

int main()
{
	vector<int> test;
	
	cout << "Podawaj liczby (| zakoncz):" << endl;
	int temp;
	while (cin >> temp)
		test.push_back(temp);

	sort(test.begin(), test.end());

	int dominata=0;

	for(int i=0; i<test.size() - 1; i++)
	{
		int count = 0;
		temp = test[i];
		while (test[i] == test[i + 1])
		{
			count++;
			i++;
		}
		dominata = (dominata < count) ? count : dominata;
	}

	cout << "dominata zbioru jest: " << dominata << endl;
}