/*The  CandyBar structure contains three members, as described in Programming
Exercise 5.Write a program that creates an array of three  CandyBar structures, ini-
tializes them to values of your choice, and then displays the contents of each struc-
ture.*/

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
	CandyBar snacks[MAX] =
	{
	 {"Mocha Munch", 2.3, 350},
	 {"Placki", 3.2, 600 },
	 {"Sernik", 1.5, 420}	
	};

	for (int i = 0; i < MAX; i++)
		cout << "Brand: " << snacks[i].brand << endl
		<< "Weight: " << snacks[i].weight << endl
		<< "Calories: " << snacks[i].calories << endl
		<<  endl;

	return 0;
}