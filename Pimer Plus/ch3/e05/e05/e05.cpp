/* Write a program that requests the user to enter the current world population and
the current population of the U.S. (or of some other nation of your choice). Store
the information in variables of type  long long . Have the program display the per-
cent that the U.S. (or other nation’s) population is of the world’s population.The
output should look something like this:
Enter the world's population: 6898758899
Enter the population of the US: 310783781
The population of the US is 4.50492% of the world population.
You can use the Internet to get more recent figures.*/

#include <iostream>

using namespace std;

int main()
{
	long long world_popul, pol_popul;

	cout << "Podaj liczbe ludnosci swiata: ";
	cin >> world_popul;
	cout << "Podaj liczne ludnosci Polski: ";
	cin >> pol_popul;

	float ratio = (float) pol_popul / (float) world_popul * 100.0f;

	cout << "Populacja Polski stawnoi "
		<< ratio << "% poulacji swiata."
		<< endl;

	return 0;
}