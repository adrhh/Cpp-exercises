/* Many state lotteries use a variation of the simple lottery portrayed by Listing 7.4. In
these variations you choose several numbers from one set and call them the field
numbers. For example, you might select five numbers from the field of 1–47).You
also pick a single number (called a mega number or a power ball, etc.) from a sec-
ond range, such as 1–27.To win the grand prize, you have to guess all the picks cor-
rectly.The chance of winning is the product of the probability of picking all the
field numbers times the probability of picking the mega number. For instance, the
probability of winning the example described here is the product of the probability
of picking 5 out of 47 correctly times the probability of picking 1 out of 27 cor-
rectly. Modify Listing 7.4 to calculate the probability of winning this kind of lottery.*/


#include <iostream>

using namespace std;
long double prob(unsigned, unsigned, unsigned);

int main()
{
	int total, choices, total_oneoft;
	cout << "podaj ilosc skreslen, ilosc wszytkich liczb oraz"
		<< "ilosc liczb w drugim losowaniu 1 z n: " << endl;

	while ((cin >> total >> choices >> total_oneoft) && choices <= total)
		cout << "szansza wygranej wynosi: "
		<< prob(total, choices, total_oneoft)
		<< endl << "Podaj kolejny trzy liczby." << endl;

	return 0;
}

long double prob(unsigned n, unsigned p, unsigned r)
{
	long double result = 1.0;
	long double i = (long double) n; //numbers iterator
	long double j = (long double) p;  //picks iterator

	for (; j > 0; i--, j--)
		result *= i / j;

	return result * r;
}