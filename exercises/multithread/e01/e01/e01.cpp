#include <iostream>
#include <thread>
#include <chrono>

using std::thread;
using std::cout;
using std::endl;

void f1(int n)
{
	static int c1 = 0;
	while (c1++ < n)
	{ 
		cout << "Hello, from f1: " << c1 << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(600));
	}
}

void f2(int n)
{
	static int c2 = 0;
	while (c2++ < n)
	{ 
		cout << "Hello, from f2: " << c2 << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

int main()
{
	const int CT = 10;

	thread t1(f1,10), t2(f2, 6);
	thread* tarr[2] = { &t1, &t2 };

	for (int i = 0; i < 2; i++)
		tarr[i]->join();

	return 0;
}


