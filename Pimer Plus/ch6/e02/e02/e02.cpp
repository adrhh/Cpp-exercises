/*Write a program that reads up to 10 donation values into an array of  double . (Or, if
you prefer, use an  array template object.) The program should terminate input on
non-numeric input. It should report the average of the numbers and also report
how many numbers in the array are larger than the average.*/

#include <iostream>
#include <array>

using namespace std;

int main()
{
	const int MAX = 10;
	double x, total = 0;
	array <double, MAX> arr;
	int counter = 0;

	while ((cin >> x) && (counter < MAX))
		arr[counter++] = x;

	for (int j = 0; j < counter; j++)
		total += arr[j];

	cout << "Srednia podanych liczb wynosi: "
		<< total / counter << endl;

	return 0;
}