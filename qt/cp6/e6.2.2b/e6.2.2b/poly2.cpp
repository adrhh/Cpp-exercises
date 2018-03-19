#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	virtual ~A() {}
	virtual void foo()
	{
		cout << "foo() z A" << endl;
	}
};

class B : public A
{
public:
	void foo()
	{
		cout << "foo() z B" << endl;
	}
};

class C : public B
{
public:
	void foo()
	{
		cout << "foo() z C" << endl;
	}
};

int main()
{
	C co;
	B bo;
	B* bptr = &co;
	bptr->foo();
	A* aptr = &co;
	aptr->foo();
	aptr = &bo;
	aptr->foo();

	return 0;
}