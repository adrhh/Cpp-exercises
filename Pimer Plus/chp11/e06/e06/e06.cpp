#include "stone.h"

using namespace std;

int main()
{
	Stone test1(2, 8);
	Stone test2(60);
	test1.set_mode(LBF);
	cout << test1 << endl << test2 << endl;
	Stone test3 = test1 + test2;
	cout << test3 << endl;
	test3 = test2 * 4;
	cout << test3 << endl;
	test3 = test3 - test1;
	cout << test3 << endl;
	cout << 6 * test3 << endl;

	return 0;
}