#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	cout << "Podaj ziarno" << endl;
	unsigned int seed;
	cin >> seed;
	srand(seed);
	for (int i = 0; i < 10; i++)
		cout << rand() % 10 << endl;

	return 0;
}