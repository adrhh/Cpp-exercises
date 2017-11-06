/*The  CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a frac-
tional part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that uses a function that takes
as arguments a reference to  CandyBar , a pointer-to- char , a  double , and an  int and
uses the last three values to set the corresponding members of the structure.The last
three arguments should have default values of “Millennium Munch,” 2.85, and 350.
Also the program should use a function that takes a reference to a  CandyBar as an
argument and displays the contents of the structure. Use  const where appropriate.*/

#include <iostream>
#include <cstring>

int const MAXS = 20;
using namespace std;

struct CandyBar
{
	char brand[MAXS];
	float weight;
	int calories;
};

void set_candy(CandyBar &s, const char str[MAXS] = "Millennium Munch",
				const float w = 2.85f, const int cal = 350);
void show_candy(const CandyBar &s);

int main()
{
	CandyBar test;
	CandyBar &test_ref = test;

	set_candy(test);
	show_candy(test);
	set_candy(test, "Nowa", 15.2f, 200);
	show_candy(test);

	char n_brand[MAXS] = "Jeszcze nowsza";
	float n_w = 19.0f;
	int n_cal = 2000;

	set_candy(test, n_brand, n_w, n_cal);
	show_candy(test);

	return 0;
}

void set_candy(CandyBar &s, const char str[MAXS],
			const float w, const int cal)
{
	strcpy_s(s.brand, str);
	s.weight = w;
	s.calories = cal;
}

void show_candy(const CandyBar &s)
{
	cout << "Firma: " << s.brand << endl
		<< "Waga: " << s.weight << endl
		<< "Kalorie: " << s.calories << endl;
}