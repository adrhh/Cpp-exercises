#include "singletonTest.h"

int main()
{
	const int SIZE = 10;
	Singleton1* sArr[SIZE];
	for (int i = 0; i < SIZE; i++)
		sArr[i] = Singleton1::getSingleton();

	for (int i = 0; i < SIZE; i++)
		sArr[i]->testFun();


	return 0;
}