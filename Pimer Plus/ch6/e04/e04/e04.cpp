/*When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a pro-
gram that can list members by real name, by job title, by secret name, or by a mem-
ber’s preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
struct bop {
char fullname[strsize]; // real name
char title[strsize];    // job title
char bopname[strsize];  // secret BOP name
int preference;         // 0 = fullname, 1 = title, 2 = bopname
};
In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alterna-
tives:
a. display by name     b. display by title
c. display by bopname  d. display by preference
q. quit
Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is  1 , choice  d would display the programmer’s job title.A sample run
may look something like the following:
Benevolent Order of Programmers Report
a. display by name     b. display by title
c. display by bopname  d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!*/

#include <iostream>

using namespace std;

const int STRsize = 20;
const int MAX = 5;

void menu();

struct bop
{
	char name[STRsize];
	char title[STRsize];
	char bopname[STRsize];
	int preference;
};

void byname(bop[], int);
void bytitle(bop[], int);
void bynick(bop[], int);
void bypref(bop[], int);

int main()
{
	char choice;
	bop boplist[MAX] =
	{
		{"Malick Evouna", "Forward", "Malick", 1},
		{"Yves Moto", "Goalkeeper", "Bitseki", 1},
		{"Mario Lemina", "Midfielder", "Rene Junior", 0},
		{"Randal Oto'o", "Right back", "Oto", -1},
		{"Franck Obambou", "Defender", "Oba", 0}
	};

	menu();
	cin >> choice;

	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a': byname(boplist, MAX);
			break;
		case 'b': bytitle(boplist, MAX);
			break;
		case 'c': bynick(boplist, MAX);
			break;
		case 'd': bypref(boplist, MAX);
			break;
		default: cout << "Wrong choice" << endl;
		}

		menu();
		cin >> choice;
	}

	return 0;
}

void menu()
{
	cout <<"a. display by name   b. display by title" << endl
		<< "c.display by bopname d.display by preference" << endl
		<< "q.quit" << endl;
}

void byname(bop l[], int n)
{
	for (int i = 0; i < n; i++)
		cout << l[i].name << endl;
}
void bytitle(bop l[], int n)
{
	for (int i = 0; i < n; i++)
		cout << l[i].title << endl;
}
void bynick(bop l[], int n)
{
	for (int i = 0; i < n; i++)
		cout << l[i].bopname << endl;
}
void bypref(bop l [], int n)
{
	for (int i = 0; i < n; i++)
	{
		if(!l[i].preference)
			cout << l[i].name << endl;
		else if (l[i].preference == 1)
			cout << l[i].title << endl;
		else
			cout << l[i].bopname << endl;
	}
}
