#include <iostream>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;



int main()
{
	srand(time(0));
	int rolls = 0;
	int roll = 0;
	while (true)
	{
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		roll = die1 + die2;
		rolls++;
		if (roll == 2)
		{
			cout << "Przegrales" << endl;
			break;
		}
		if (roll == 7 || roll == 11)
		{
			cout << "Wygrales" << endl;
			break;
		}
		
	}
	cout << "Gra zakonczona po: " << rolls << " ruchach" << endl;

	return 0;
}