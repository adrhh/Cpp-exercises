/* Do Programming Exercise 6, but instead of declaring an array of three  CandyBar
structures, use  new to allocate the array dynamically.*/

#include <iostream>

using namespace std;

struct CandyBar
{
	char brand[40];
	float weight;
	int calories;
};

int main()
{
	const int MAX = 3;
	CandyBar* snacks = new CandyBar[3];
	
	snacks[0] = { "Mocha Munch", 2.3f, 350 };
	snacks[1] = { "Placki", 3.2f, 600 };
	snacks[2] = { "Sernik", 1.5f, 420 };

	for (int i = 0; i < MAX; i++)
		cout << "Brand: " << snacks[i].brand << endl
		<< "Weight: " << snacks[i].weight << endl
		<< "Calories: " << snacks[i].calories << endl
		<< endl;

	delete[] snacks;

	return 0;
}