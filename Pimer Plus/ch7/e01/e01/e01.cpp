/*Write a program that repeatedly asks the user to enter pairs of numbers until at
least one of the pair is  0 . For each pair, the program should use a function to calcu-
late the harmonic mean of the numbers.The function should return the answer to
main() , which should report the result.The harmonic mean of the numbers is the
inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0  × x × y / (x + y)*/

#include <iostream>

using namespace std;

double harmonic(double, double);

int main()
{
	double x, y, z;
	cout << "Podaj dwie liczby: (0 konczy dzialanie programu): " << endl;
	while ((cin >> x >> y) && x != 0 && y != 0)
	{
		z = harmonic(x, y);
		cout << "Srednia harmoniczna " << x << " i " << y
			<< "wynosi: " << z << endl;
		cout << "Podaj dwie koljne liczby: " << endl;
	}
}

double harmonic(double a, double b)
{
	return 2.0 * a * b / (a + b);
}