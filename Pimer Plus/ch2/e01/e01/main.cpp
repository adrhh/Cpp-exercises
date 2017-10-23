/* Write a C++ program that displays your name and address 
(or if you value your privacy, a fictitious name and address).
*/

#include <iostream>
#include <string>

int main()
{
	std::string imie = "Adrian";
	std::string nazwisko = "Horyn";
	std::string adres = "Lancut";

	std::cout << "Imie: " << imie
			  << " nazwisko: " << nazwisko
			  << " adres: " << adres
			  << std::endl;

	return 0;
}