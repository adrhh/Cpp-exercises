#include <iostream>
#include "string2.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	String s1(" i ucze sie C++");
	String s2 = "Podaj swoje imie: ";
	String s3, s4, s5;

	cout << s2;
	cin >> s3;
	s4 += s3;
	s4 += " jest spoko";
	cout << s4 << endl;
	s5 = s3 + s1;
	cout << s5 << endl;

	return 0;
}