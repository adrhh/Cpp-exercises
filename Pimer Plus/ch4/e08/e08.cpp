/*Do Programming Exercise 7 but use  new to allocate a structure instead of declaring
a structure variable.Also have the program request the pizza diameter before it
requests the pizza company name.*/

#include <iostream>

using namespace std;
const int MAX = 40;

struct Pizza
{
	char name[MAX];
	int diameter;
	float weight;
};

int main()
{
	Pizza* pizza = new Pizza;

	cout << "Podaj nazwe firmy: ";
	cin.getline(pizza->name, MAX);
	cout << "Podaj srednice: ";
	cin >> pizza->diameter;
	cout << "Podaj wage: ";
	cin >> pizza->weight;

	cout << "Nazwa firmy: " << pizza->name << endl
		<< "Srednica: " << pizza->diameter << endl
		<< "Waga: " << pizza->weight << endl;

	delete pizza;

	return 0;
}