#include <iostream>
#include "dma.h"

using namespace std;
const int ARMAX = 5;
const int CMAX = 100;

int main()
{	
	char temp_label[CMAX];
	char temp_style[CMAX];
	char temp_color[40];
	int temp_rating;
	int choice;
	baseDMA* barr[ARMAX];

	for (int i = 0; i < ARMAX; i++)
	{
		cout << "Podaj label:" << endl;
		cin >> temp_label;
		cout << "Podaj rating:" << endl;
		cin >> temp_rating;
		cout << "Wybierz rodzaj obiektu:\n[0] - lackDMA\n[1]-hasDMA" << endl;
		while (cin >> choice && (choice != 0 && choice != 1))
			cout << "wpisz 1 lub 2" << endl;
		if (choice == 0)
		{
			cout << "Podaj kolor:" << endl;
			cin >> temp_color;
			barr[i] = new lackDMA(temp_color, temp_label, temp_rating);
		}
		else
		{
			cout << "Podaj styl:" << endl;
			cin >> temp_style;
			barr[i] = new hasDMA(temp_style, temp_label, temp_rating);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < ARMAX; i++)
	{
		barr[i]->view();
		cout << endl;
	}
	for (int i = 0; i < ARMAX; i++)
		delete[] barr[i];

	return 0;
}