/*Write a precursor to a menu-driven program.The program should display a menu
offering four choices, each labeled with a letter. If the user responds with a letter
other than one of the four valid choices, the program should prompt the user to
enter a valid response until the user complies.Then the program should use a
switch to select a simple action based on the user’s selection.A program run could
look something like this:
Please enter one of the following choices:
c) carnivore           p) pianist
t) tree                g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.*/

#include <iostream>

using namespace std;

void menu();

int main()
{
	char ch;
	bool flag = true;

	while (flag)
	{
		menu();
		cin.get(ch);

		switch (ch)
		{
		case 'c': 
			cout << "Wrrr" << endl;
			break;
		case 'p': 
			cout << "Tititit" << endl;
			break;
		case 't':
			cout << "Szszszz" << endl;
			break;
		case 'g':
			cout << "Bam bam" << endl;
			break;
		case 'q':
			flag = false;
		default:
			cout << "Please enter c, g, p, t, or q to quit: " << endl;
			cin.get(ch);
			continue;
		}	
	}

	return 0;
}

void menu()
{
	cout << "Please enter one of the following choices :" << endl
		<< "c) carnivore \tp) pianist" << endl
		<< "t) tree      \tg) game" << endl
		<< "q) quit" << endl;
}
