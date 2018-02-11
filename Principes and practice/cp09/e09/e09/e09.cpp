#include <iostream>
#include "Librar.h"
using std::cout;

int main()
{
	Book test(2034, 11451, 30324, 'z', "Pole", "Mikolaj", Book::kids);
	cout << test;

	return 0;
}

