#include "person.h"
#include <iostream>

using namespace std;

int main()
{
	const int AMAX = 3;
	Person* test[AMAX];
	
	

	test[0] = new Gunslinger("Adam", "Szybki", 0.44, 2);
	test[1] = new PokerPlayer("Janusz", "Sprytny");
	test[2] = new BadDude("Zbych", "Stary", 0.2, 201);

	for (int i = 0; i < AMAX; i++)
		test[i]->Show();


	return 0;
}