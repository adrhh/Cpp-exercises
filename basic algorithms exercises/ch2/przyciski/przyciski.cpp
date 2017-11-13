#include <iostream>

using namespace std;

int* zadanie(const int* t, int n, int m);
void nax(int *t, int n, int x);
void pokaz(int *t, int s, int k);

int main()
{
	const int n = 5;
	const int m = 7;
	int* wynik;
	int test[m] = { 3,4,4,6,1,4,4 };

	wynik = zadanie(test, n, m);
	pokaz(wynik, 1, n+1);

	return 0;
}

int* zadanie(const int* t, int n, int m)
{
	int* roz = new int[n+2];
	int max;
	max = 0;

	for (int i = 0; i < n+2; i++)
		roz[i] = 0;

	for (int i = 0; i < m; i++)
	{
		if (t[i] == n + 1)
			nax(roz, n + 1, max);
		else
		{
			roz[t[i]]++;		
			max = roz[t[i]] > max ? roz[t[i]] : max;
		}
	}

	return roz;
}

void nax(int *t, int n, int x)
{
	for (int i = 0; i < n; i++)
		t[i] = x;
}

void pokaz(int *t, int s, int k)
{
	for (int i = s; i < k; i++)
		cout << t[i] << " ";
}