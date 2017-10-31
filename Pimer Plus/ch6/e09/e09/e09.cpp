/*Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

struct person_d
{
	string name;
	int amount;
};

int main()
{
	const int MAX = 20;
	char filename[MAX];
	ifstream file;

	cout << "Podaj nazwe pliku: ";
	cin.getline(filename, MAX);
	file.open(filename);
	if (!file.is_open())
	{
		cout << "Blad otwarcia pliku" << endl;;
		exit(EXIT_FAILURE);
	}

	int n,i=0;
	file >> n;
	file.get();
	
	cout << n << endl;
	person_d* list = new person_d[n];

	while (i < n)
	{
		
		string temp;
		getline(file,list[i].name);
		getline(file, temp);
		list[i].amount = stoi(temp);

		i++;
	}

	if (file.eof())
		cout << "Koniec pliku" << endl;

	file.close();

	person_d* patrons = new person_d[n];
	person_d* grand_patrons = new person_d[n];
	unsigned int p_counter = 0, gp_counter = 0;

	for (int i = 0; i < n; i++)
	{
		if (list[i].amount < 10000)
			patrons[p_counter++] = list[i];
		else
			grand_patrons[gp_counter++] = list[i];
	}

	if (gp_counter)
	{
		cout << "Lista wspanialych sponsorow:" << endl;
		for (unsigned int i = 0; i < gp_counter; i++)
		{
			cout << grand_patrons[i].name << endl;
			cout << setprecision(10) << grand_patrons[i].amount << endl << endl;
		}
	}
	else
		cout << "Brak wspanialych sponsorow." << endl;

	if (p_counter)
	{
		cout << "Lista sponsorow:" << endl;
		for (unsigned i = 0; i < p_counter; i++)
		{
			cout << patrons[i].name << endl;
			cout << setprecision(10) << patrons[i].amount << endl << endl;
		}
	}
	else
		cout << "Brak sponsorow." << endl;

	cin.get();

	delete[] list;
	delete[] grand_patrons;
	delete[] patrons;

	return 0;
}
