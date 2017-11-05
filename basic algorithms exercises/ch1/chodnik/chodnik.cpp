/* chodnik */

#include <iostream>

using namespace std;

int zadanie(int, int*);

int main()
{
	//input: naturalne: 1 <= n <= 5e5
	// t[n-1] tablica liczb {1..n}

	int n, *tab;

	//test
	n = 5;
	tab = new int[n-1];
	tab[0] = 2;
	tab[1] = 3;
	tab[2] = 1;
	tab[3] = 5;

	cout << "wynik: " << zadanie(n, tab) << endl; //cout 4 OK


	return 0;
}

int zadanie(int n, int *t)
{
	int suma_szeregu = n*(n + 1) / 2;
	int suma_tablicy = 0;

	for (int i = 0; i < n - 1; i++)
		suma_tablicy += *(t+i);

	return suma_szeregu - suma_tablicy;
}