/*Write a program that requests the user to enter three times for the 40-yd dash (or
40-meter, if you prefer) and then displays the times and the average. Use an  array
object to hold the data. (Use a built-in array if  array is not available.)*/

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main()
{
	const char MAX = 3;

	array<int, MAX> m40_times;

	for (int i = 0; i < MAX; i++)
	{
		cout << "Podaj czas nr " << i+1 << " w biegu na 40m [s]: ";
		cin >> m40_times[i];
	}

	int total = 0;
	float avrg;

	for (int i = 0; i < MAX; i++)
		total += m40_times[i];
	avrg = (float) ((float) total / (float) MAX);

	cout << "Srednia czasow wynosi: " << setprecision(3) << avrg << endl;

	return 0;
}