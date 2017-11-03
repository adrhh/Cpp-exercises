/* Redo Listing 7.15 without using the  array class. Do two versions:
a. Use an ordinary array of  const char * for the strings representing the sea-
son names, and use an ordinary array of  double for the expenses.
b. Use an ordinary array of  const char * for the strings representing the sea-
son names, and use a structure whose sole member is an ordinary array of
double for the expenses. (This design is similar to the basic design of the
array class.)*/

#include <iostream>;

using namespace std;

const int PORY = 4;
const int MAXC = 7;

void fill_arr(const char[][MAXC], int, double*);
void show_arr(const char[][MAXC], int, double*);

const char miesiace[PORY][MAXC] =
	{ "Wiosna", "Lato", "Jesien", "Zima" };

int main()
{
	double test[PORY];
	fill_arr(miesiace, PORY, test);
	show_arr(miesiace, PORY, test);

	return 0;
}

void fill_arr(const char s[][MAXC], int n, double* t)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Podaj wynik za " << s[i] << endl;
		cin >> *(t + i);
	}
}

void show_arr(const char s[][MAXC], int n, double* t)
{
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Wynik za " << s[i] << " wynosi: " << *(t + i) << endl;
		total += *(t + i);
	}

	cout << "Lancze wydatki wynosza: " << total << endl;
}