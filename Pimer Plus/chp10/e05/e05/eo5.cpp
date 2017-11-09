#include <iostream>
#include <cctype>
#include "stack.h"

Customer get_cust();
using namespace std;
void menu();

int main()
{
	
	Stack st;
	Customer cst;
	char ch;
	static double total;
	
	menu();
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
			if (st.isfull())
				cout << "Stos pelny" << endl;
			else
			{
				cout << "Podaj dane kupca " << endl;
				cst = get_cust();
				st.push(cst);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stos pusty" << endl;
			else
			{
				st.pop(cst);
				total += cst.payment;
				cout << "Kupiec zjdety, cala kwota do zaplaty: " << total << endl;
				break;
			}
		}
		menu();
	}

	return 0;
}

Customer get_cust()
{
	Customer temp;
	cout << "Podaj imie kupca:" << endl;
	cin.getline(temp.fullname, LEN);
	cout << "Podaj wysokosc oplaty: " << endl;
	cin >> temp.payment;
	cin.get();
	
	return temp;
}

void menu()
{
	cout << "nacisjnij D, aby wprowadzic kupca" << endl
		<< "P by dodac go do rachunku, K by zakonczyc" << endl;
}