#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;


int cow_count(string f, string a);
int bull_count(string f, string a);

vector<string> Words = { "ziemniak", "zupa", "kawa" };

int main()
{
	srand((unsigned int)time(0));
	string cchoice;
	string hchoice;
	int b, c;

	while (true)
	{
		cchoice = Words[rand() % Words.size()];
		cout << Words[1] << endl;

		while (hchoice != cchoice)
		{
			cin >> hchoice;
			c = cow_count(cchoice, hchoice);
			b = bull_count(cchoice, hchoice);
			cout << cchoice << endl;
			cout << "krowy: " << c << " byki: " << b << endl;
		}

		cout << "k-kontynnuj, z-zakoncz" << endl;

		char choice;
		while (cin >> choice)
		{
			if (choice == 'k' || choice == 'z')
				break;
			cout << "wybierz: k - kontynuuj, z- zakoncz" << endl;
			while (cin.get() != '\n')
				continue;
		}
		if (choice == 'z')
			break;

	}
	return 0;
}

int cow_count(string f, string a)
{
	int cows = 0;
	string temp = f;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < temp.length(); j++)
			if (a[i] == temp[j] && i!=j)
			{		
				cows++;	
				temp.erase(j, j + 1);
				break;
			}
	}
	return cows;
}


int bull_count(string f, string a)
{
	int bulls = 0;
	for (int i = 0; i < a.length(); i++)
	{ 
		if (i == f.length() - 1)
			break;
		if (a[i] == f[i])
			bulls++;
	}
	return bulls;
}
