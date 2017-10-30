/*Write a program that opens a text file, reads it character-by-character to the end of
the file, and reports the number of characters in the file.*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

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
		cout << "Blad otwarcia pliku";
		exit(EXIT_FAILURE);
	}

	char ch;
	int counter = 0;

	file >> ch;
	while (file.good())
	{
		counter++;
		file >> ch;
	}
	if (file.eof())
		cout << "Koniec pliku" << endl;

	file.close();
	cout << "Plik:" << filename
		<< " sklada sie z: " << counter << " znakow"
		<< endl;

	cin.get();

	return 0;
}