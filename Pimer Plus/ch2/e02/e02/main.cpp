/* Write a C++ program that asks for a distance in furlongs 
and converts it to yards.(One furlong is 220 yards.) */

#include <iostream>

const long FUR_TO_YARD = 220;

using std::cin;
using std::cout;
using std::endl;

int main()
{
	long furlongs;
	cout << "Podaj odleglosc w furach" << endl;
	cin >> furlongs;
	cout << furlongs << " fur odpowiada "
		 << furlongs * FUR_TO_YARD << " jardom"
		 << endl;

	return 0;
}