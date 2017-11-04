/*Design a function  calculate() that takes two type  double values and a pointer to
a function that takes two  double arguments and returns a  double.The
calculate() function should also be type  double, and it should return the value
that the pointed - to function calculates, using the double arguments to
calculate().For example, suppose you have this definition for the  add()
function:
double add(double x, double y)
{
	return x + y;
}
Then, the function call in the following would cause  calculate() to pass the val -
ues 2.5 and 10.4 to the  add() function and then return the  add() return value
(12.9) :
	double q = calculate(2.5, 10.4, add);
Use these functions and at least one additional function in the  add() mold in a
program.The program should use a loop that allows the user to enter pairs of num -
bers.For each pair, use  calculate() to invoke  add() and at least one other func -
tion.If you are feeling adventurous, try creating an array of pointers to  add() - style
functions and use a loop to successively apply  calculate() to a series of functions
by using these pointers.Hint: Here’s how to declare such an array of three pointers :
double(*pf[3])(double, double);
You can initialize such an array by using the usual array initialization syntax and
function names as addresses.*/


#include <iostream>

using namespace std;

double add(double, double);
double sub(double, double);
double div(double, double);
double mult(double, double);
double calc(double, double, double (*)(double, double));

int main()
{
	const int ARSIZE = 4;
	double (*fptr[ARSIZE])(double, double) = {add, sub, div, mult};

	char ch;
	double a, b;

	while (true)
	{
		cout << "podaj dwie liczby" << endl;
		if (!(cin >> a >> b))
			break;
		cout << " wybierz dzialanie ktore chesz wykonac [+,-,/,*], q - wyjdz:" << endl;

		cin.get();
		cin.get(ch);
		if (ch == 'q')
			break;
		switch (ch) 
		{
		case '+': cout << "wynik: " << calc(a, b, fptr[0]) << endl;
			break;
		case '-': cout << "wynik: " << calc(a, b, fptr[1]) << endl;
			break;
		case '/': cout << "wynik: " << calc(a, b, fptr[2]) << endl;
			break;
		case '*': cout << "wynik: " << calc(a, b, fptr[3]) << endl;
			break;
		default: cout << "Zly wybor, wybierz z [+,-,/,*]" << endl;
		}
	}

	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}

double mult(double x, double y)
{
	return x * y;
}

double div(double x, double y)
{
	return x / y;
}

double calc(double x, double y, double (*ptr)(double, double))
{
	return (*ptr)(x, y);
}
