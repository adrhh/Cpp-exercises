/*Design a structure called  car that holds the following information about an auto-
mobile: its make, as a string in a character array or in a  string object, and the year
it was built, as an integer.Write a program that asks the user how many cars to cata-
log.The program should then use  new to create a dynamic array of that many  car
structures. Next, it should prompt the user to input the make (which might consist
of more than one word) and year information for each structure. Note that this
requires some care because it alternates reading strings with numeric data (see252 Chapter 5 Loops and Relational Expressions
Chapter 4). Finally, it should display the contents of each structure.A sample run
should look something like the following:
How many cars do you wish to catalog? 2
Car #1:
Please enter the make: Hudson Hornet
Please enter the year made: 1952
Car #2:
Please enter the make: Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser*/

#include <string>
#include <iostream>

using namespace std;

struct Car
{
	string company;
	int year;
};

int main()
{
	int n;

	cout << "Podaj liczbe sanochodow: ";
	cin >> n;
	cin.get();

	Car* cars = new Car [n];

	for (int i = 0; i < n; i++)
	{
		cout << "Podaj producenta: ";
		getline(cin, cars[i].company);
		cout << "Podaj rok produkcji: ";
		cin >> cars[i].year;
		cin.get();
	}

	for (int i = 0; i < n; i++)
		cout << "Samochod nr: " << i + 1 << endl
		<< "Rok produkcji: " << cars[i].year << endl
		<< "Producent: " << cars[i].company << endl
		<< endl;
	
	delete [] cars;

	return 0;
}
