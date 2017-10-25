/*Redo Listing 5.4 using a type  array object instead of a built-in array and type
long double instead of  long long . Find the value of 100!*/

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main()
{
	const int ArSize = 101;
	array <long double, ArSize> factorials;

	factorials[0] = 1L;
	factorials[1] = 1L;

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		cout << i << "!= " << factorials[i] << endl;

	cout << endl <<"100!= " << setprecision(200) 
		<< factorials[100] << endl;

	return 0;
}