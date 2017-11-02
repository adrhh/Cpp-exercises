/*Define a recursive function that takes an integer argument and returns the factorial
of that argument. Recall that 3 factorial, written 3!, equals 3  × 2!, and so on, with 0!
defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
in a program that uses a loop to allow the user to enter various values for which the
program reports the factorial.*/

#include <iostream>

using namespace std;

unsigned long fact(int);

int main()
{
	int a=0;
	cout << "oblicz silnie liczby: " << endl;
	while  (cin >> a)
	{
		if (a < 0)
			break;
		cout << "a! = " << fact(a) << endl;
		cout << "podaj kolejna liczbe: " << endl;
	}
	
	return 0;
}

unsigned long fact(int n)
{
	if (n < 2)
		return 1;
	else
		return fact(n - 1) * n;
}