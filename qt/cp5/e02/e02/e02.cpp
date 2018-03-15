#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;



int randInt(int min, int max);

int main()
{
	srand(time(0));

	for (int i = 0; i < 10; i++)
		cout << randInt(5, 10) << endl;

	return 0;
}

int randInt(int min, int max)
{
	return min + rand() % (max - min);
}