#ifndef BASE_H_
#define BASE_H_

class Base
{
public:
	Base();
	void a();
	virtual void b();
	virtual void c(bool con = true);
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived();
	virtual void a();
	virtual void b();
	virtual void c();
};

#endif // !BASE_H_
