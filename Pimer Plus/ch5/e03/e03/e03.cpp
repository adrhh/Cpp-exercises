/*Write a program that asks the user to type in numbers.After each entry, the pro-
gram should report the cumulative sum of the entries to date.The program should
terminate when the user enters  0 .*/

#include <iostream>

using namespace std;

int main()
{
	int x, total;

	cout << "Podaj liczbe (0 konczy program): ";
	cin >> x;
	total = x;

	while(x)
	{
		cout << "Podaj kolejna liczbe: ";
		cin >> x;
		total += x;
		cout << "Suma podanych liczb wynosi: "
			<< total << endl;
	}

	return 0;
}