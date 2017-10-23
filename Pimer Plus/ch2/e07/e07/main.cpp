/* Write a program that asks the user to enter an hour value and a minute value.The
main() function should then pass these two values to a type  void function that dis-
plays the two values in the format shown in the following sample run:
Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void czas(int, int);

int main()
{
	int godziny;
	int minuty;
	cout << "Podaj liczbe godziny: ";
	cin >> godziny;
	cout << "Podaj liczbe minut: ";
	cin >> minuty;

	czas(godziny, minuty);

	return 0;
}

void czas(int h, int m)
{
	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}

	cout << h << ':' << m << endl;
}