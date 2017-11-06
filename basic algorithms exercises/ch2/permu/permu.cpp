/*permutacja*/

#include <iostream>

using namespace std;

bool zadanie(int*, const int);


int main()
{
	const int n = 5;
	int t_1[n] = {1,4,2,3,5};
	int t_2[n] = {1,4,3,3,5};

	cout << zadanie(t_1, n) << endl;
	cout << zadanie(t_2, n) << endl;

	return 0;
}

bool zadanie(int* t, const int n)
{
	bool wynik = true;
	int *zlicz = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		zlicz[i] = 0;
	for (int i = 0; i < n; i++)
		if (t[i] > n || zlicz[t[i]] == 1)
			wynik = false;
		else
			zlicz[t[i]]++;

	delete [] zlicz;
	return wynik;
}
