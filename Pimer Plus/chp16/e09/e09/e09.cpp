#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using std::list;
using std::sort;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	srand(time(0));

	int size;
	cout << "podaj wielkosc tablicy:" << endl;
	cin >> size;

	vector<int> vi0;
	for (int i = 0; i < size; i++)
		vi0.push_back(rand() % 1000);


	vector<int> vi;
	list<int> li;

	for (int i = 0; i < vi0.size(); i++)
	{
		vi.push_back(vi0[i]);
		li.push_back(vi0[i]);
	}

	//vi sort time
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	double tvi = (double)(end - start) / CLOCKS_PER_SEC;

	//li sort time
	start = clock();
	li.sort();
	end = clock();
	double tli = (double)(end - start) / CLOCKS_PER_SEC;

	cout << "vi: " << tvi << " li: " << tli << endl;

}