#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

template <class T>
int reduce(T ar[], int n);

template <class T>
void poka(T ar[], int n);

int main()
{
	long test1[8] = { 10,9,5,2,5,5,2,1, };
	poka(test1, 8);
	int size1 = reduce(test1, 8);
	poka(test1, size1);

	string test2[8] = {"baca", "ala", "aga", "ala", "baba", "baca", "baba", "kaka" };
	poka(test2, 7);
	int size2 = reduce(test2, 8);
	poka(test2, size2);

	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	vector<T> temp(ar, ar + n);
	sort(temp.begin(), temp.end());

	auto end = std::unique(temp.begin(), temp.end());
	auto start = temp.begin();

	int i = 0;
	while (start != end)
	{
		ar[i] = temp[i];
		start++;
		i++;
	}
	return i;
}

template <class T>
void poka(T ar[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ar[i] << ' ';
	cout << endl;
}