#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "nacisjnij D, aby wprowadzic deklaracje" << endl
		<< "P by ja przetworzyc, K by zakonczyc" << endl;
	while (cin >> ch && toupper(ch) != 'K')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'D':
		case 'd':
			cout << "Podaj nr deklaracji: " << endl;
			cin >> po;
			if (st.isfull())
				cout << "Stos pelny" << endl;
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
				cout << "Dklaracja nr: " << po << " zjdeta" << endl;
				break;
			}
		}
	cout << "nacisjnij D, aby wprowadzic deklaracje" << endl
			<< "P by ja przetworzyc, K by zakonczyc" << endl;
	}

	return 0;
}