/*The  CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a frac-
tional part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that declares such a structure
and creates a  CandyBar variable called  snack , initializing its members to  "Mocha
Munch" , 2.3 , and  350 , respectively.The initialization should be part of the declara-
tion for  snack . Finally, the program should display the contents of the  snack vari-
able.*/

#include <iostream>

using namespace std;

struct CandyBar
{
	char brand[40];
	float weight;
	int calories;
};

int main()
{
	CandyBar snack
	{
		"Mocha Munch",
		2.3,
		350,
	};

	cout << "Brand: " << snack.brand << endl
		<< "Weight: " << snack.weight << endl
		<< "Calories: " << snack.calories << endl;

	return 0;
}