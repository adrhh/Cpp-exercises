#include <iostream>
#include "classic.h"

using namespace std;

void Bravo(const Cd& disck);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Fantazja C_moll", "Brandel", "Philips", 2, 57.15);

	Cd* pcd = &c1;

	cout << "bezposrednie uzycie obiektu:" << endl << endl;
	c1.report();
	c2.report();
	cout << endl;

	cout << "uzycie przez wskaznik na typ CD:" << endl << endl;
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "test przypisania:" << endl << endl;
	Classic copy;
	copy = c2;
	copy.report();

	return 0;
}

void Bravo(const Cd& disck)
{
	disck.report();
}