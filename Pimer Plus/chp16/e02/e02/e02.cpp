#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::transform;

bool is_pali(const string& str);
string to_low_str(const string& str);
string remove_whitespaces(const string& str);
char to_lower(char ch) { return tolower(ch); }

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

string remove_whitespaces(const string& str)
{
	string temp;

	for (auto i : str)
		if (!isspace(i))
			temp += i;

	return temp;
}

string to_low_str(const string& str)
{
	string temp(str.rbegin(), str.rend());
	transform(temp.begin(), temp.end(), temp.begin(), to_lower);

	return temp;
}

bool is_pali(const string& str)
{
	bool answ = false;
	
	string temp_str = to_low_str(str);
	temp_str = remove_whitespaces(temp_str);
	string s_rev(temp_str.rbegin(), temp_str.rend());

	if (s_rev == temp_str)
		answ = true;

	return answ;
}