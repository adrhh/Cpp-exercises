#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int reduce(long arr[], int n);
void poka(long arr[], int n);

int main()
{
	long test[8] = { 10,9,5,2,5,5,2,1, };
	poka(test, 8);
	int size = reduce(test, 8);
	poka(test, size);

	return 0;
}

int reduce(long arr[], int n)
{
	vector<long> temp (arr, arr + n);
	sort(temp.begin(), temp.end());

	auto end = std::unique(temp.begin(), temp.end());
	auto start = temp.begin();

	int i = 0;
	while (start != end)
	{
		arr[i] = temp[i];
		start++;
		i++;
	}
	return i;
}

void poka(long arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}