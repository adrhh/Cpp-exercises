#include <iostream>
#include <climits>

using namespace std;

int min(int* t, int n);
int max(int* t, int n);
int *csort(int* t, int n);
void poka(int* t, int n);

int zadanie(int* t, int n);

int main()
{
	//zadanie maks iloczyn trzech liczb z danej listy
	//wejscie t1 i t2;
	int t1[5] = { 1,4,3,2,5 };
	int t2[4] = { -2,1,1,5 };
	cout << zadanie(t1, 5) << endl;
	cout << zadanie(t2, 4) << endl;

	return 0;
}

int zadanie(int* t, int n)
{
	int* posortowane = csort(t, n);
	int i1 = posortowane[n - 1] * posortowane[n - 2] * posortowane[n - 3];
	int i2 = posortowane[n - 1] * posortowane[0] * posortowane[1];
	return (i1 > i2) ? i1 : i2;
}

int *csort(int *t, int n)
{
	int _max = max(t, n);
	int _min = min(t, n);
	int* zlicz = new int[_max - _min + 1] {0};
	int* posor = new int[n];

	for (int i = 0; i < n; i++)
		zlicz[t[i] - _min]++;
	for (int i = _min + 1; i <= _max; i++)
		zlicz[i - _min] += zlicz[i - _min - 1];
	for (int i = n - 1; i >= 0; i--)
		posor[(zlicz[t[i] - _min]--) - 1] = t[i];
	free(zlicz);

	return posor;
}

int min(int* t, int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
		if (min > t[i])
			min = t[i];
	return min;
}

int max(int* t, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (max < t[i])
			max = t[i];
	return max;
}


void poka(int* t, int n)
{
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";
	cout << endl;
}