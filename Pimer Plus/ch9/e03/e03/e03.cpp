/* Begin with the following structure declaration:
struct chaff
{
char dross[20];
int slag;
};
Write a program that uses placement  new to place an array of two such structures in
a buffer.Then assign values to the structure members (remembering to use
strcpy() for the  char array) and use a loop to display the contents. Option 1 is to
use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular
new to allocate the buffer.
*/

#include <iostream>

using std::cout;
using std::endl;

const int BUF = 32;
char buffer[BUF];

struct chaff
{
	char dross[20];
	int slag;
};

void show(const chaff* t, int n);

int main()
{
	chaff test_s[2] = 
	{
		{"Lubudubu", 4},
		{"Lele", 3}
	};
	
	chaff* test_d;
	test_d = new (buffer) chaff[2];
	
	strcpy_s(test_d[0].dross, test_s[0].dross);
	strcpy_s(test_d[1].dross, test_s[1].dross);
	test_d[0].slag = test_s[0].slag;
	test_d[1].slag = test_s[1].slag;

	show(test_s, 2);
	show(test_d, 2);

	return 0;
}

void show(const chaff* t, int n)
{
	for (int i = 0; i < n; i++)
		cout << t[i].dross << ": " << t[i].slag << endl;
}