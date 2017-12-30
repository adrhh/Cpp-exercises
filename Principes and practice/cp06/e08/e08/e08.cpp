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
	int b, c=0;

	while (true)
	{
		cchoice = Words[rand() % Words.size()];

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
	string temp_f = f;
	string temp_a = a;
	//delete correct letters from answer
	//delete by swap letter to @
	for (int i = 0; i < f.length(); i++)
	{
		if (a[i] == f[i])
		{
			temp_f[i] = '@';
			temp_a[i] = '@';
		}
		if (i == a.length() - 1)
			break;
	}
	for (int i = 0; i < temp_a.length(); i++)
	{

		for (int j = 0; j < temp_f.length(); j++)
			if (temp_a[i] == temp_f[j] && temp_f[j] != '@')
			{		
				cows++;	
				temp_a[i] = '@';
				break;
			}
	}
	return cows;
}


int bull_count(string f, string a)
{
	int bulls = 0;
	for (int i = 0; i < f.length(); i++)
	{ 
		if (a[i] == f[i])
			bulls++;
		if (i == a.length() - 1)
			break;
	}
	return bulls;
}
