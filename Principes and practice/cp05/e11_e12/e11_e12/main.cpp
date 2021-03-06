#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cin;
using std::cout;
using std::vector;

int rand_i(int n);
vector<int> i_tov(int x);
int cow_count(vector<int> f, vector<int> a);
int bull_count(vector<int> f, vector<int> a);

int main()
{
	srand((unsigned int)time(0));
	int cchoice;
	int hchoice=0;
	vector<int> f;
	vector<int> a;
	int b, c;

	while (true)
	{
		cchoice = rand_i(4);
		f = i_tov(cchoice);
		cout << cchoice << endl;

		while(hchoice != cchoice)
		{ 
		cin >> hchoice;
		a = i_tov(hchoice);
		c = cow_count(f, a);
		b = bull_count(f, a);
		cout << cchoice << endl;
		cout << "krowy: " << c << " byki: " <<  b << endl;
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

int rand_i(int n)
{
	int answ = 0;
	int multiper = 1;
	while (n--)
	{
		int x = (rand() % 10);
		if (!x)
			answ *= 10;
		else
			answ += x * multiper;
		multiper *= 10;
	}
	return answ;
}

int cow_count(vector<int> f, vector<int> a)
{
	int cows = 0;
	if (f.size() != a.size())
		return -1;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
			if (a[i] == f[j] && i != j)
			{
				cows++;
				f.erase(f.begin() + j);
				f.insert(f.begin() + j, -1);
				break;
			}
	}
	return cows;
}

int bull_count(vector<int> f, vector<int> a)
{
	int bulls = 0;
	if (f.size() != a.size())
		return -1;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == f[i])
				bulls++;
	return bulls;
}

vector<int> i_tov(int x)
{
	vector<int> digs;
	while (x)
	{
		digs.push_back(x % 10);
		x /= 10;
	}
	return digs;
}