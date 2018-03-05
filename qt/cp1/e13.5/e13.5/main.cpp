#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;


struct wygrane
{
	int hwins;
	int cwins;
	wygrane() : hwins(0), cwins(0) {}
};

void gra(int n, wygrane& w);


int main()
{
	srand(time(0));
	wygrane wins;
	bool graj_dalej = true;
	while (graj_dalej)
	{
		char ch;
		gra(12, wins);
		cout << "Nowa gra t/n" << endl;
		cin.get(ch);
		while (cin.get() != '\n' )
			continue;
		
		cout << ch << endl;
		while (ch != 't' && ch != 'n')
		{
			cout << "wybierz t lub n" << endl;
			cin.get(ch);
			while (cin.get() != '\n')
				continue;
		}
		if (ch == 'n')
			graj_dalej == false;
	}
	

	return 0;
}

void gra(int n, wygrane& w)
{
	int max = n-1;
	int jama = rand() % (max - 1) + 1;
	int cel = rand() % (max - 1) + 1;
	while (cel == jama)
		cel = rand() % (max - 1) + 1;

	cout << "jama: " << jama << endl;
	cout << "cel: " << cel << endl;

	int cp, up;
	cp = up = 0;
	while (true)
	{
		up += (rand() % 6 + 1) + (rand() % 6 + 1);
		cp += (rand() % 6 + 1) + (rand() % 6 + 1);
		if (up > max)
			up %= max;
		if (cp > max)
			cp %= max;
		cout << "pozycja czlowieka: " << up << endl;
		cout << "pozycja komputera: " << cp << endl;
		if (up == jama || cp == cel)
		{
			w.cwins++;
			cout << "Komputer wygral, ilosc zwyciestw: " << w.cwins << endl;
			break;
		}
		if( cp == jama || up == cel)
		{
			w.hwins++;
			cout << "wygrales, ilosc zwyciestw: " << w.hwins << endl;
			break;
		}
	}
}