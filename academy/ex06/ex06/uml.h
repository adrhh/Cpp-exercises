#ifndef UML_H_
#define UML_H_

class testClass
{
private:
	int x;
	int y;
public:
	testClass(int a = 0, int b = 0) : x(a), y(b) {}
	void show() const;
	int getX() const { return x; }
	int getY() const { return y; }
};


//assoctaiton, class A knows B
class assocClass
{
public:
	assocClass(testClass* ptr) : ptrToTest(ptr) {}
	void fun() const;
private:
	testClass* ptrToTest;
};

//dependency, class A uses B
class depenClass
{
public:
	void fun(testClass* ptr) const;
};

//aggregation, A have B, destructor doesnt kill B
class aggClass
{
public:
	void addPtr(testClass* ptr);
private:
	static const int MAX_SIZE;
	testClass* ptrTable[MAX_SIZE];

};


#endif // !UML_H_
