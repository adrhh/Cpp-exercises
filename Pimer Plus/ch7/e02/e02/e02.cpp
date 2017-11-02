/*Write a program that asks the user to enter up to 10 golf scores, which are to be
stored in an array.You should provide a means for the user to terminate input prior
to entering 10 scores.The program should display all the scores on one line and
report the average score. Handle input, display, and the average calculation with
three separate array-processing functions.*/

#include <iostream>
#include <iomanip>

const int MSIZE = 10;
using namespace std;

int fill(int[], int);
void show(const int[], int);
double avrg(const int[], int);

int main()
{
	int score[MSIZE], size;

	cout << "Wypelnij tablice wynikow: " << endl;
	size = fill(score, MSIZE);
	cout << size << endl;

	if (size > 0)
	{
		show(score, size);
		cout << "Srednia wynikow wynosi: " << avrg(score, size) << endl;
	}

	return 0;
}

int fill(int tab[], int n)
{
	int i;
	int temp;
	for (i = 0; i < n; i++)
	{
		cout << "Podaj wynik nr " << i + 1 << " :" << endl;
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane" << endl;
			break;
		}
		else if (temp <= 0)
			break;
		tab[i] = temp;
	}
	return i;
}

void show(const int tab[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << i+1;
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(5) << tab[i];
	cout << endl;
}

double avrg(const int tab[], int n)
{
	int total=0;
	for (int i = 0; i < n; i++)
		total += tab[i];
	return (double) total / (double) n;
}
