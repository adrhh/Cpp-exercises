/*Write a program that reads keyboard input to the  @ symbol and that echoes the
input except for digits, converting each uppercase character to lowercase, and vice
versa. (Don’t forget the  cctype family.)*/

#include <cctype>
#include <iostream>

using namespace std;

int main()
{
	cout << "Podawaj tekst, zakoncz wpsiujac znak @: ";

	char ch;
	cin.get(ch);

	while (ch != '@')
	{
		if (isalpha(ch))
		{
			if (isupper(ch))
				cout << (char) tolower(ch);
			else
				cout << (char) toupper(ch);
		}
		cin.get(ch);
	}

	return 0;
}