#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool close_doubles(double d1, double d2);

int main()
{
	double din1 = 0, din2 = 0;

	cout << "Podaj dwie liczby calkowite (| by zakonczyc)" << endl;
	while (cin >> din1 >> din2)
	{
		if (din1 > din2)
		{ 
			cout << din1 << " jest wieksza od " << din2 << endl;
			if (close_doubles(din1, din2))
				cout << "liczby sa prawie rowne" << endl;
		}
		else if (din1 == din2)
			cout << din1 << " jest rowne " << din2 << endl;
		else
		{
			cout << din2 << " jest wieksza od " << din1 << endl;
			if (close_doubles(din2, din1))
				cout << "liczby sa prawie rowne" << endl;
		}
	}

	return 0;
}

bool close_doubles(double d1, double d2)
{
	bool answ = false;
	if (d1 - d2 < 1.0 / 100)
		answ = true;

	return answ;
}