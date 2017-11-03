/*Redo Listing 7.7, modifying the three array-handling functions to each use two
pointer parameters to represent a range.The  fill_array() function, instead of
returning the actual number of items read, should return a pointer to the location
after the last location filled; the other functions can use this pointer as the second
argument to identify the end of the data.*/

#include <iostream>

using namespace std;

double* fill_array(double *, int);
void show_array (double*, double*);
void revalue(double, double*, double*);

int main()
{
	const int ARSIZE = 10;

	double test[ARSIZE];
	double* koniec = fill_array(test, ARSIZE);
	show_array(test, koniec);
	if (koniec - test)
	{
		cout << "Podaj czynnik zmiany: " << endl;
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "nieprwana wartosc, podaj liczbe" << endl;
		}
		revalue(factor, test, koniec);
		show_array(test, koniec);
	}

	return 0;
}

double* fill_array(double* t, int n)
{
	double temp;
	double* wsk = t;

	for (int i = 0; i < n; i++)
	{
		cout << "Podaj wartosc nr: " << i + 1 << endl;
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane" << endl;
			break;
		}
		*wsk++ = temp;
	}

	return wsk; 
}

void show_array(double* start, double* end)
{
	int i = 1;
	for (double* wsk = start; wsk != end; wsk++)

		cout << "Wrtosc z indeksem " << i++ << " wynosi " << *wsk << endl;
}

void revalue(double r, double* start, double* end)
{
	double *wsk = start;
	while (wsk++ != end)
		*wsk *= r;
}