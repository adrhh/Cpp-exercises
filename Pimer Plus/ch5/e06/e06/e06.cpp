/*Do Programming Exercise 5 but use a two-dimensional array to store input for 3
years of monthly sales. Report the total sales for each individual year and for the
combined years.*/

#include <string>
#include <iostream>
#include <array>


int main()
{
	using namespace std;

	const int YEARS = 3;

	array <string, 12> miesiace{ "Styczen", "Luty", "Marzec", "Kwiecen",
		"Maj", "Czerwiec", "Lipiec", "Sierpien",
		"Wrzesien", "Pazdziernik", "Listopad",
		"Grudzien" };

	int n = miesiace.size(),
		sum[YEARS] = {0,0,0},
		sprzedaz[YEARS][12];

	for (int j = 0; j < YEARS; j++)
	{
		cout << "Rok nr: "<< j+1 << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Podaj wynik sprzedazy w miesiacu "
				<< miesiace[i] << ": ";
			cin >> sprzedaz[j][i];
			sum[j] += sprzedaz[j][i];
		}
	}

	for(int j = 0; j < YEARS; j++)
		cout << "Calkowita sprzedaz w roku nr: " << j+1 << " wynisola:"
		<< sum[j] << endl;

	return 0;
}