#include "bigint.h"
#include <iostream>

using namespace std;

int main()
{
	BigInt t1 = BigInt("123");
	BigInt t2 = BigInt("399");
	BigInt t3 = t1 + t2;
	t1.showBigInt();
	cout << endl;
	t3.showBigInt();

	return 0;
}