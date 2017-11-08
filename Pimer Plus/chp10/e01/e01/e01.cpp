/*Provide method definitions for the class described in Chapter Review Question 5
and write a short program that illustrates all the features.*/

#include "ac.h"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	Bank_acc test1("Michal", 22332, 10000);
	Bank_acc test2("Marek", 22422);

	test1.show();
	test2.show();
	test1.add(4000);
	test1.show();
	test1.pop(6000);
	test1.show();

	double temp;
	cout << "Podaj wysokosc wplaty: " << endl;
	cin >> temp;
	test2.add(temp);
	test2.show();

	return 0;
}
