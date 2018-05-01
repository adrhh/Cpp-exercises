#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <iostream>
#include "list.h"
#include "err.h"

class IntStack
{
public:
	virtual int pop() = 0;
	virtual void push(int n) = 0;
};

class IntStackOnArrConstSizeChange : public IntStack
{
public:
	IntStackOnArrConstSizeChange(int arrSize);
	~IntStackOnArrConstSizeChange();
	int pop();
	void push(int n);
private:
	bool isEmpty() const;
	int position; //top position
	int maxArrSize;
	int* valuesArr;
	void changeSize();
};

class IntStackAsForwardList : public IntStack
{
private:
	IntListForward ifList;
public:
	bool isEmpty() const;
	int pop();
	void push(int n);
};


#endif // !STACK_H_