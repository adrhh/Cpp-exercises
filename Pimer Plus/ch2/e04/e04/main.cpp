/*Write a program that asks the user to enter his or her age.The program then should
display the age in months :
Enter your age : 29
Your age in months is 384.*/

#include <iostream>

int convert(int);

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int years;
	cout << "Podaj swoj wiek: ";
	cin >> years;
	cout << "Twoj wiek  w miesiacach wynosi: "
		<< convert(years)
		<< endl;

	return 0;
}

int convert(int years)
{
	const char YEARS_TO_MONTHS = 12;
	return years * static_cast<int>(YEARS_TO_MONTHS);
}
