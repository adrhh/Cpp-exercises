#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

long long seed;

int LCG()
{
	const long long a = (2<<10)+1111; 
	const long long b = 11112213333;
	const long long m = (2<<30);
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