#include "bigint.h"
#include <iostream>

using namespace std;

int main()
{
	BigInt t1 = BigInt("123");
	BigInt t2 = BigInt("321");
	BigInt t3 = t1 + t2;
	cout << endl;
	cout << endl;
	t1.showBigInt();
	cout << endl;
	t3.showBigInt();

	//test char 
	char ch = '1';
	cout << '\n' <<  ch - '0' << endl;
	cout << ch - '0' << endl;

	return 0;
}