#include <iostream>

using namespace std;

int main()
{
	double val1, val2;
	char oper;
	while (cin >> val1 >> val2 >> oper)
	{
		switch (oper)
		{
		case '+' :
			cout << val1 << " + " << val2 << " = " << val1 + val2 << endl;
			break;
		case '-':
			cout << val1 << " - " << val2 << " = " << val1 - val2 << endl;
			break;
		case '*':
			cout << val1 << " * " << val2 << " = " << val1 * val2 << endl;
			break;
		case '/':
			cout << val1 << " / " << val2 << " = " << val1 / val2 << endl;
			break;
		default:
			cout << "Nieporawne wartosci" << endl;
		}
	}
	return 0;
}