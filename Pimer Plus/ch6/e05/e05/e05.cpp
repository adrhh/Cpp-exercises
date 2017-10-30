/*The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
lowing income tax code:
First 5,000 tvarps: 0% tax
Next 10,000 tvarps: 10% tax
Next 20,000 tvarps: 15% tax
Tvarps after 35,000: 20% tax
For example, someone earning 38,000 tvarps would owe 5,000  × 0.00 + 10,000  ×
0.10 + 20,000  × 0.15 + 3,000  × 0.20, or 4,600 tvarps.Write a program that uses a
loop to solicit incomes and to report tax owed.The loop should terminate when
the user enters a negative number or non-numeric input.*/

#include <iostream>

using namespace std;

int main()
{
	const int FIRST = 5000;
	const int SECOND = 10000;
	const int THIRD = 20000;
	const int FOURTH = 35000;
	const float FIRST_T = 0.0; 
	const float SECOND_T = 0.10;
	const float THIRD_T = 0.15;
	const float FOURTH_T = 0.20;

	long income;

	cout << "Podaj swoj dochod: ";

	while ((cin >> income) && (income > 0))
	{
		float total_tax = 0;
		long reaming = income;

		while (reaming)
		{
			
			if (reaming < FIRST)
			{
				total_tax += (float) FIRST_T;
				break;
			}
			else
			{
				total_tax += (float) FIRST_T;
				reaming -= FIRST;
			}

			if (reaming < SECOND)
			{
				total_tax += (float) reaming * SECOND_T;
				break;
			}
			else
			{
				total_tax += (float) SECOND * SECOND_T;
				reaming -= SECOND;
			}

			if (reaming < THIRD)
			{
				total_tax += (float) reaming * THIRD_T;
				break;
			}
			else
			{
				total_tax += (float) THIRD * THIRD_T;
				reaming -= THIRD;
			}

			if (reaming)
			{
				total_tax += (float) reaming * FOURTH_T;
				reaming -= reaming;
			}
		}

		cout << "Wartosc podatku przy dochodzie: " << income
			<< " wynosi: " << total_tax << endl;
		cout << "Podaj kolejny przychod: ";
	}

	return 0;
}
