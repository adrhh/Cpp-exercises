#include <iostream>
#include <cctype>
#include "stack2.h"

using namespace std;

int main()
{
	Stack test;
	{
		Stack st;
		char ch;
		unsigned long po;
		cout << "D - utworz deklaracje" << endl
			<< "P - przetworz deklaracje" << endl
			<< "K - zakoncz" << endl;
		while (cin >> ch && toupper(ch) != 'K')
		{
			while (cin.get() != '\n')
				continue;
			if (!isalpha(ch))
			{
				cout << "Nieporawne dane\a\a\a" << endl;
				continue;
			}
			switch (ch)
			{
			case 'D':
			case 'd':
				cout << "Podaj nr deklaracji: " << endl;
				cin >> po;
				if (st.isfull())
					cout << "stos pelny" << endl;
				else
					st.push(po);
				break;
			case 'P':
			case 'p':
				if (st.isempty())
					cout << "stos pusty" << endl;
				else
				{
					st.pop(po);
					cout << "Deklaracja nr: " << po << " zdjeta" << endl;
				}
				break;
			}
			cout << "D - utworz deklaracje" << endl
				<< "P - przetworz deklaracje" << endl
				<< "K - zakoncz" << endl;
		}

		test = st;
	}

	cout << "Ostatni stan stosu: " << endl;
	Item temp;
	while (!test.isempty())
	{
		temp = test.getitem();
		test.pop(temp);
	}
		

	cout << "Stos opruznony" << endl;

	return 0;
}