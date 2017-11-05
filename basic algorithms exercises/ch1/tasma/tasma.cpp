/*tasma*/

#include <iostream>
#include <math.h>

using namespace std;

int zadanie(const int *tab, const int n);

int main() 
{

	// n 2<=n<=1000000
	// arr[n-1], -1000<=arr[i]<==1000

	//test
	const int n = 5;
	int test_tab[5] = {3,1,2,4,3};
	cout << zadanie(test_tab, n) << endl;
	//>> 1 ok

	return 0;
}

int zadanie(const int *tab, const int n)
{
	long total, lewa, prawa, roznica, wynik = 2000;
	total = lewa = prawa = 0;


	for (int i = 0; i < n; i++)
		total += tab[i];
	for (int i = 0; i < n - 1; i++)
	{
		lewa += tab[i];
		prawa = total - lewa;
		roznica = abs(lewa - prawa);
		wynik = (wynik < roznica) ? wynik : roznica;
	}

	return wynik;
}
