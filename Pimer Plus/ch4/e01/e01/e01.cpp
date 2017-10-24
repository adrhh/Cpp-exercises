/*Write a C++ program that requests and displays information as shown in the fol-
lowing example of output:
What is your first name? Betty Sue
What is your last name? Yewe
What letter grade do you deserve? B
What is your age? 22
Name: Yewe, Betty Sue
Grade: C
Age: 22
Note that the program should be able to accept first names that comprise more
than one word.Also note that the program adjusts the grade downward—that is, up
one letter.Assume that the user requests an A, a B, or a C so that you don’t have to
worry about the gap between a D and an F.*/

#include <iostream>
#include <cctype>

using namespace std;

const int MAX = 40;

struct Person
{
	char f_name[MAX];
	char s_name[MAX];
	char grade;
	int age;
};

int main()
{
	Person per;
	char grade;

	cout << "Jak masz imie/imiona: ";
	cin.getline(per.f_name, MAX);
	cout << "Jak masz nazwisko: ";
	cin.get(per.s_name, MAX).get();
	cout << "Jaka masz ocene (A,B,C): ";
	cin.get(grade);
	per.grade = toupper(grade);
	cout << "Jaki jest Twoj wiek: ";
	cin >> per.age;

	cout << "Imie " << per.s_name
		<< ", " << per.f_name << endl
		<< "Ocena: " << per.grade << endl
		<< "Wiek: " << per.age << endl;

	return 0;
}