/*zabka z01*/

#include <iostream>
#include <cmath>

using namespace std;

int zadanie(int, int, int);

int main()
{
	//input x,y,z (naturalne od 1 do 10e9)
	// x <= y,z
	int x, y, z, answ;

	//test
	x = 10;
	y = 85;
	z = 30;

	cout << zadanie(x, y, z) << endl; 
	//>> 3, OK

}

int zadanie(int a, int b, int c)
{
	double skok = (double)c;
	double droga = (double)b - (double)a;

	return (int)(ceil((droga / skok)));
}
