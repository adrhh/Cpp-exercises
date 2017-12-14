#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<char> Cchoice{ 'p', 'k', 'n' };

int main()
{
	srand(time(0));
	char ch;
	char cch;
	cout << "wybierz [k, p, n] q-zakoncz" << endl;
	while (cin.get(ch) && ch!='q')
	{
		while (cin.get() != '\n')
			continue;
		cch = Cchoice[rand() % 3];
		switch (ch)
		{
		case 'p':
			if (cch == 'p')
				cout << cch << ch << "remis" << endl;
			else if (cch == 'k')
				cout << cch << ch << "zwyciestwo" << endl;
			else
				cout << cch << ch << "porazka" << endl;
			break;
		case 'k':
			if (cch == 'p')
				cout << cch << ch << "porazka" << endl;
			else if (cch == 'k')
				cout << cch << ch << "remis" << endl;
			else
				cout << cch << ch << "zwyciestwo" << endl;
			break;
		case 'n':
			if (cch == 'p')
				cout << cch << ch << "zwyciestwo" << endl;
			else if (cch == 'k')
				cout << cch << ch << "porazka" << endl;
			else
				cout << cch << ch << "remis" << endl;
			break;
		default:
			cout << "zly wybor" << endl;
		}
	}

	return 0;
}