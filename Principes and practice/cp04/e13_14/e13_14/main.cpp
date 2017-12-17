#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	int n;
	cout << "Podaj n:" << endl;
	cin >> n;
	int limit = sqrt(n);

	vector<bool> all_to_n;
	for (int i = 0; i < n; i++)
		all_to_n.push_back(true);

	for (int i = 2; i < limit; i++)
	{
		if (all_to_n[i])
			for (int j = i+1; j < n; j++)
				if (j % i == 0)
					all_to_n[j] = false;
	}

	vector<int> primes;
	for (int i = 0; i < n; i++)
		if (all_to_n[i])
			primes.push_back(i);

	for (unsigned int i = 0; i < primes.size(); i++)
		cout << primes[i] << ' ';
	cout << endl;

	return 0;
}