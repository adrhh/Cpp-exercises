#include "bigint.h"
#include <iostream>

using namespace std;

int main()
{
	BigInt t1 = BigInt("56775676565765732237898099089057567789");
	BigInt t2 = BigInt("1123");
	BigInt t3 = t1 + t2;
	//t3.showBigInt();
	//cout << endl;
	//t1.showBigInt();
	//cout << endl;
	//t3.showBigInt();
	//cout << endl;
	BigInt t5 = BigInt("976576565756765756776579");
	BigInt t6 = t1 * t5;
	t6.showBigInt();

	return 0;
}