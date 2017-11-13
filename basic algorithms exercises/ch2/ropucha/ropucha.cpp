#include <iostream>

using namespace std;

int zadanie(const int t[], int n, int a);

int main()
{
	const int arrs = 8;
	int tab1[arrs] = { 1, 3, 1, 4, 2, 3, 5, 4 };
	int a = 5;
	int tab2[arrs] = { 1, 3, 1, 4, 2, 3, 3, 4 };

	cout << zadanie(tab1, arrs, a) << endl;
	cout << zadanie(tab2, arrs, a) << endl;

	return 0;
}

int zadanie(const int t[], int n, int a)
{
	int wynik = -1;
	int droga = a;
	int *zlicz = new int[n];
	for (int i = 0; i < n; i++)
		zlicz[i] = 0;

	for (int i = 0; i < n; i++)
	{
		if (zlicz[t[i]] == 0)
			droga--;
		if (!droga)
		{
			wynik = i + 1;
			break;
		}
		zlicz[t[i]]++;
	}
	delete[] zlicz;
	return wynik;
}