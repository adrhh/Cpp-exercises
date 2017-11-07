/*Redo Listing 9.9, replacing the character array with a  string object.The program
should no longer have to check whether the input string fits, and it can compare
the input string to  "" to check for an empty line.*/

#include <string>
#include <iostream>

using std::string;

void str_cnt(const string s);

int main()
{
	string temp;

	std::cout << "Podaj wiersz\n";
	std::getline(std::cin, temp);

	while (temp != "")
	{
		str_cnt(temp);
		std::cout << "Podaj kolejny wiersz\n";
		std::getline(std::cin, temp);
	}

	std::cout << "Koniec\n";
	
	return 0;
}

void str_cnt(const string s)
{
	static int total;
	int count = size(s);
	std::cout << "\"" << s << "\" zawiera: "
		<< count << std::endl;
	total += count;
	std::cout << "Lacznie podano: " << total
		<< " znakow" << std::endl;
}