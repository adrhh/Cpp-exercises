/*You sell the book C++ for Fools.Write a program that has you enter a year’s worth
of monthly sales (in terms of number of books, not of money).The program should
use a loop to prompt you by month, using an array of  char * (or an array of
string objects, if you prefer) initialized to the month strings and storing the input
data in an array of  int .Then, the program should find the sum of the array con-
tents and report the total sales for the year.*/

#include <string>
#include <iostream>
#include <array>

int main()
{
	using namespace std;

	array <string, 12> miesiace {"Styczen", "Luty", "Marzec", "Kwiecen",
								"Maj", "Czerwiec", "Lipiec", "Sierpien",
								"Wrzesien", "Pazdziernik", "Listopad",
								"Grudzien"};

	int n = miesiace.size(), sum=0;
	array <int, 12> sprzedaz;
	for (int i = 0; i < n; i++)
	{
		cout << "Podaj wynik sprzedazy w miesiacu "
			<< miesiace[i] << ": ";
		cin >> sprzedaz[i];
		sum += sprzedaz[i];
	}

	cout << "Calkowita sprzedaz w biezzacym roku wynisola:"
		<< sum << endl;

	return 0;
}