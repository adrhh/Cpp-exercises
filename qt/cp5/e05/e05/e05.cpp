#include "crypto.h"
#include <iostream>

using std::endl;
using std::cout;

int main()
{
	Crypto c1(1872, "ppsps", 1);
	string s3, s2, s1 = "zaszyfrowane";
	s2 = c1.decrypt(s1);
	cout << s1 << " " << s2 << endl;
	s3 = c1.encrypt(s2);
	cout << s2 << " " << s3 << endl;

	return 0;
}