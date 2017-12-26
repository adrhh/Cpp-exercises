#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

bool is_pali(const string& str);

int main()
{
	string temp;
	cout << "Podaj tekst to sprawdzenia" << endl;
	getline(cin, temp);
	bool pali = is_pali(temp);

	if (pali)
		cout << temp << " jest palindromem." << endl;
	else
		cout << temp << " nie jest palindromem." << endl;

	return 0;
}

bool is_pali(const string& str)
{
	bool answ = false;
	string s_rev(str.rbegin(), str.rend());

	if (s_rev == str)
		answ = true;

	return answ;
}