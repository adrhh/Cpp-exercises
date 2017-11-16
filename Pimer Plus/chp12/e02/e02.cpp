#include <iostream>
#include "string2.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	{
	String s1(" i ucze sie C++");
	String s2 = "Podaj swoje imie: ";
	String s3, s4, s5;

	cout << s2;
	cin >> s3;
	s4 += s3;
	s4 += " jest spoko";
	cout << s4 << endl;
	s2 = "Mam na imie " + s3;
	s5 = s2 + s1;
	cout << s5 << endl;
	}
	cout << String::HowMany() << endl; // 0 ok!

	String s1 = "Tralala bababa!";
	char ch = 'a';
	cout << s1 << " zawiera " << s1.has(ch) << " litery " << ch << endl;
	cout << s1.stringlow() << endl;
	s1.stringup();
	cout << s1 << endl;

	return 0;
}