#include <iostream>
#include "complex0.h"

using namespace std;

int main()
{
	complex a(3.0, 4.0);
	complex c;
	cout << "Podaj liczbe zespolona:" << endl;
	while (cin >> c)
	{
		cout << "c: " << c << endl;
		cout << "~c: " << ~c << endl;
		cout << "a: " << a << endl;
		cout << "a + c = " << a + c << endl;
		cout << "a - c = " << a - c << endl;
		cout << "a * c = " << a * c << endl;
		cout << "2 * c = " << 2 * c << endl;
		cout << "Podaj liczbe zespolona:" << endl;
	}

	return 0;
}