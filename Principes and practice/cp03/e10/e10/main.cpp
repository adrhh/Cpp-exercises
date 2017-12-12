#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main()
{
	string operations;
	double din1, din2, dout;

	cout << "Podaj operator i dwa operandy" << endl;
	cin >> operations >> din1 >> din2;

	if (operations == "+" || operations == "plus")
		dout = din1 + din2;
	else if (operations == "-"|| operations == "minus")
		dout == din1 - din2;
	else if (operations == "*" || operations == "mno")
		dout == din1 * din2;
	else if (operations == "/" || operations == "dziel")
		dout == din1 / din2;
	else
	{
		cout << "Blad wejscia";
		return -1;
	}

	cout << din1 << ' ' << operations << ' ' << din2 << " = " << dout << endl;

	return 0;
}