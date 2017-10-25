/* William Wingate runs a pizza-analysis service. For each pizza, he needs to record
the following information:
- The name of the pizza company, which can consist of more than one word
- The diameter of the pizza
- The weight of the pizza
Devise a structure that can hold this information and write a program that uses a
structure variable of that type.The program should ask the user to enter each of the
preceding items of information, and then the program should display that informa-
tion. Use  cin (or its methods) and  cout .*/

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
	Pizza pizza;

	cout << "Podaj nazwe firmy: ";
	cin.getline(pizza.name, MAX);
	cout << "Podaj srednice: ";
	cin >> pizza.diameter;
	cout << "Podaj wage: ";
	cin >> pizza.weight;

	cout << "Nazwa firmy: " << pizza.name << endl
		<< "Srednica: " << pizza.diameter << endl
		<< "Waga: " << pizza.weight << endl;

	return 0;
}