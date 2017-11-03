/* Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of  double values and an
array size. It prompts the user to enter  double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input, and it returns the actual number of entries.
Show_array() takes as arguments the name of an array of  double values and an
array size and displays the contents of the array.
Reverse_array() takes as arguments the name of an array of  double values and an
array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array, and then
show the array.*/

#include <iostream>

using namespace std;

int fill_array(double[], int);
void show_array(const double[], int);
void reverse_array(double[], int);

int main()
{
	const int MAXS = 10;
	int size;
	double test[MAXS];

	size = fill_array(test, MAXS);
	show_array(test, size);
	reverse_array(test, size);
	show_array(test, size);

	return 0;
}

int fill_array(double t[], int n)
{
	int i = 0;
	double temp;

	while ( i < n)
	{
		cout << "Podaj wartosc tablic o indeskie: " << i << endl;
		if (!(cin >> temp))
			break;
		t[i++] = temp;
	}

	return i;
}

void show_array(const double t[], int n)
{
	for (int i = 0; i < n; i++)
		cout << t[i] << endl;
}

void reverse_array(double t[], int n)
{
	double temp;
	for (int i = 0, j = n-1; i < n/2 ; i++, j--)
	{
		temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
}
