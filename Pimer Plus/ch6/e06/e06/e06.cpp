/*Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the num-
ber of contributors and then solicit the user to enter the name and contribution of
each contributor.The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a  double member to hold the amount of the
contribution.After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should
be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons. If there are no donors in one
of the categories, the program should print the word “none.”Aside from displaying
two categories, the program need do no sorting.*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct person_d
{
	string name;
	double amount;
};

int main()
{
	unsigned int n;
	
	cout << "Podaj liczbe wplacajacych: ";
	cin >> n;

	person_d* list = new person_d[n];
	
	for (int i = 0; i < n; i++)
	{ 
		cout << "Podaj dane wplacajacego: ";
		cin.ignore();
		getline(cin, list[i].name);
		cout << "Podaj wielkosc jego wplaty: ";
		cin >> list[i].amount;
	}

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
		for (int i = 0; i < gp_counter; i++)
		{
			cout << grand_patrons[i].name << endl;
			cout << setprecision(10) << grand_patrons[i].amount << endl << endl;
		}
	}
	else
		cout << "Brak wspanialych sponsorow." << endl;

	if(p_counter)
	{
		cout << "Lista sponsorow:" << endl;
		for (int i = 0; i < p_counter; i++)
		{
			cout << patrons[i].name << endl;
			cout << setprecision(10) << patrons[i].amount << endl << endl;
		}
	}
	else
		cout << "Brak sponsorow." << endl;

	delete[] list;
	delete[] grand_patrons;
	delete[] patrons;

	return 0;
}