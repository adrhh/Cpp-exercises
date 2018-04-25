#include "bigint.h"
#include <iostream>

using namespace std;

int main()
{
	BigInt t1 = BigInt("123");
	BigInt t2 = BigInt("399");
	BigInt t4 = BigInt("9439074309749307904370943790437904379047309743097403772871258612862178783687368736287682368739678263786328768723678362");
	BigInt t3 = t1 + t2;
	t1.showBigInt();
	cout << endl;
	t3.showBigInt();
	t4.showBigInt();

	return 0;
}