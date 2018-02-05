#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

long long seed;

int LCG()
{
	const long long a = 48271;
	const long long b = 1;
	const long long m = (2 << 30) - 1;
	seed = (a*seed + b) % m;
	return (int)seed;
}

int main()
{

	seed = time(0);

	for (int i = 0; i < 100; i++)
		cout << LCG() << endl;

	return 0;
}
