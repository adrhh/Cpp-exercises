/*Write a short program that asks for your height in integer inches and then converts
your height to feet and inches.Have the program use the underscore character to
indicate where to type the response.Also use a  const symbolic constant to repre -
sent the conversion factor.*/

#include <iostream>

const int INCH_IN_FOOT = 12;

using namespace::std;

int main()
{
	int inch, inch_m, foot;

	cout << "Podaj wzrost w calach:___\b\b\b";
	cin >> inch;

	foot = inch / INCH_IN_FOOT;
	inch_m = inch % INCH_IN_FOOT;

	cout << inch << " cali to: "
		<< foot << " stop i "
		<< inch_m << " cali\n";

	return 0;
}