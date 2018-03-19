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
		bar();
	}
	virtual void bar()
	{
		cout << "bar() z A" << endl;
	}
};

class B : public A
{
public:
	void foo()
	{
		cout << "foo() z B" << endl;
		A::foo();
	}
	void bar()
	{
		cout << "bar() z B" << endl;
	}
};

int main()
{
	B bo;
	A *apt = &bo;
	apt->foo();
	cout << "=======================" << endl;
	A ao = *apt;
	ao.foo();
	cout << "=======================" << endl;
	ao = bo;
	ao.foo();
	cout << "=======================" << endl;
	bo.foo();

	return 0;
}