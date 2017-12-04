#include "queue1.h"
#include "worker.h"
#include <iostream>
#include <cstring>

using namespace std;
const int MAXSIZE = 5;

int main()
{
	Worker* warr[MAXSIZE];
	int qs = 0;

	for (int i = 0; i < MAXSIZE; i++)
	{
		char choice;
		cout << "Podaj kategorie" << endl
			<< "k kelner" << endl
			<< "p  piosenkarz" << endl
			<< "s spiweajacy kelner" << endl
			<< "w koniec" << endl;
		cin >> choice;
		while (strchr("kpsw", choice))
		{
			cout << "wybierz k,p,s lub w" << endl;
			cin >> choice;
		}
		if (choice == 'w')
			break;
		switch (choice)
		{
		case 'k': warr[i] = new Waiter;
			break;
		case 'p': warr[i] = new Singer;
			break;
		case 's': warr[i] = new SingingWaiter;
			break;
		}
		cin.get();
		warr[i]->Set();
		qs++;
	}

	Queue<Worker *> wque(qs);
	for (int i = 0; i < qs; i++)
		wque.enqueue(warr[i]);

	return 0;
}
