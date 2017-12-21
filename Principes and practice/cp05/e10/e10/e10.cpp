#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;

void error(const string& s);

int main()
{
	vector<double> dvec;
	double temp;

	cout << "Podawaj liczby (|zakoncz wprowadzanie):" << endl;
	while (cin >> temp)
		dvec.push_back(temp);

	cin.clear();
	while (cin.get() != '\n')
		continue;

	while (true)
	{
		cout << "Podaj  ile liczb chcesz zsumowac" << endl;
		int n;
		double total = 0.0;
		char choice;

		cin.clear();
		while (!(cin >> n)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Podaj liczbe naturalna." << endl;
		}
		try
		{
			if (n < 0)
				error("Indeks mniejszy od zera\n");
			if (n > dvec.size())
				error("Indeks poza zakresem tablic\n");
			for (unsigned int i = 0; i < dvec.size(); i++)
				total += dvec[i];
			cout << "suma " << n << " liczb wynosi: " << total << endl;
			total = 0;
		}
		catch (std::runtime_error& e)
		{
			cout << e.what() << endl;
			continue;
		}

		if(dvec.size() > 2)
		{ 
			vector<double> pairsub;
			for (unsigned int i = 0; i < dvec.size() - 1; i++)
				pairsub.push_back( dvec[i] -  dvec[i + 1] );

			cout << "roznica par: " << endl;
			for (unsigned int i = 0; i < pairsub.size(); i++)
				cout << pairsub[i] << endl;
			cout << endl;
		}

		cout << "wybierz: k - kontynuuj, z- zakoncz" << endl;
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
}

void error(const string& s)
{
	throw std::runtime_error(s);
}