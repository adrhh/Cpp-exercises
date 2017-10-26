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
		<< "Producent: " << cars[i].company << endl
		<< "Rok produkcji: " << cars[i].year << endl
		<< endl;

	return 0;
}