/* Write a program that requests the user to enter two integers.The program should
then calculate and report the sum of all the integers between and including the two
integers.At this point, assume that the smaller integer is entered first. For example, if
the user enters  2 and 9 , the program should report that the sum of all the integers
from 2 through 9 is 44.*/

#include <iostream>

using namespace std;

int main()
{
	int min, max, total = 0;

	cout << "Podaj minium przedzialu: ";
	cin >> min;
	cout << "Podaj maksimum przedzialu: ";
	cin >> max;

	for (int i = min; i <= max; i++)
		total += i;

	cout <<endl <<  "Suma liczb w tym przedziale wynosi: "
		<< total << endl;

	return 0;
}