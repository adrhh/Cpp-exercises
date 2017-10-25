/* Daphne invests $100 at 10% simple interest.That is, every year, the investment earns
10% of the original investment, or $10 each and every year:
interest = 0.10  × original balance
At the same time, Cleo invests $100 at 5% compound interest.That is, interest is 5%
of the current balance, including previous additions of interest:
interest = 0.05  × current balance
Cleo earns 5% of $100 the first year, giving her $105.The next year she earns 5% of
$105, or $5.25, and so on.Write a program that finds how many years it takes for
the value of Cleo’s investment to exceed the value of Daphne’s investment and then
displays the value of both investments at that time.*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const float DAPH_P = 0.1f;
	const float CLEO_P = 0.05f;

	float daph_orginal_balance = 100.0f;
	float daph_interest = daph_orginal_balance * DAPH_P;

	float cleo_current_balance = 100.0f;
	float cleo_interest = cleo_current_balance * CLEO_P;
	cleo_current_balance += cleo_interest;

	int year = 1;

	while (cleo_interest < daph_interest)
	{
		cout << "Po roku nr " << year++ << setw(6) << setprecision(4)
			<< "\t zysk Cleo: " << cleo_interest
			<< "\t zysk Daph: " << daph_interest
			<< endl;
		daph_interest += daph_orginal_balance * DAPH_P;
		cleo_interest += cleo_current_balance * CLEO_P;
		cleo_current_balance += cleo_interest;
	}

	cout << "Po " << year << " latach Cleo zysk przekorczyl zysk Daph i wynosi:"
		<< endl << setw(10) << setprecision(4) << "zysk Cleo: " << cleo_interest
		<< "\t zysk Daph: " << daph_interest
		<< endl;

	return 0;
}
