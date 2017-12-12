#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int iin1 = 0, iin2 = 0;

	cout << "Podaj dwie liczby calkowite (| by zakonczyc)" << endl;
	while (cin >> iin1 >> iin2)
	{
		if (iin1 > iin2)
			cout << iin1 << " jest wieksza od " << iin2 << endl;
		else if (iin1 == iin2)
			cout << iin1 << " jest rowne " << iin2 << endl;
		else
			cout << iin2 << " jest wieksza od " << iin1 << endl;
	}

	return 0;
}