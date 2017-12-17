
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

int main()
{
	int n;
	cout << "Podaj n: " << endl;
	cin >> n;
	bool isprime = false;
	vector<int>primes(3);
	primes[0] = 2;
	primes[1] = 3;
	primes[2] = 5;

	int i = 5;
	while (primes.size() < n)
	{
		isprime = true;
		for (int j = 0; j < primes.size(); j++)
			if (i % primes[j] == 0)
			{
				isprime = false;
				break;
			}
		if (isprime)
			primes.push_back(i);
		i++;
	}

	for (int i = 0; i < primes.size(); i++)
		cout << primes[i] << endl;


	return 0;
}