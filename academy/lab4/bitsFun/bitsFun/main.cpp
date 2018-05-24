#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

template <class T>
std::string toBin(T val)
{
	std::string binOut;
	while (val)
	{
		(val % 2) ? binOut += '1' : binOut += '0';
		val /= 2;
	}
	std::reverse(binOut.begin(), binOut.end());
	return binOut;
}

std::string showRawMem(char* ptr)
{
	const int BYTE = 8;
	std::string binOut;
	unsigned char mask = 1;
	mask <<= BYTE - 1;
	for (int i = BYTE - 1; i >= 0; i--)
	{
		if (mask & *ptr)
			binOut += '1';
		else
			binOut += '0';
		mask >>= 1;
	}
	return binOut;
}

int main()
{
	std::cout << toBin(20) << std::endl;
	char ch = 17;
	std::cout << showRawMem(&ch) << std::endl;

	return 0;
}