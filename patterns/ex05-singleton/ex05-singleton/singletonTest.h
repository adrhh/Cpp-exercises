#ifndef SINGLETONTEST_H_
#define SINGLETONTEST

#include <iostream>

//pointer singleton
class Singleton1
{
private:
	Singleton1() 
	{
		counter++;
	}
	static Singleton1* s;
	static int counter; //for test 
public:
	static Singleton1* getSingleton()
	{
		if (!s)
			s = new Singleton1;
		return s;
	}
	void testFun() const
	{
		std::cout << "Ta da!\n";
		std::cout << "object nr: " << counter << std::endl;
	}
	~Singleton1() 
	{
		delete s;
		s = nullptr;
	}
};

int Singleton1::counter = 0;
Singleton1* Singleton1::s = nullptr;

#endif // !SINGLETONTEST_H_
