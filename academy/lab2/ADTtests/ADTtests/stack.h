#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <iostream>
#include "pch.h"
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
	IntStackOnArrConstSizeChange(int arrSize = 1);
	~IntStackOnArrConstSizeChange();
	int pop();
	int getPosition() const { return position; }
	void push(int n);
	bool isEmpty() const;
private:
	int* valuesArr;
	void changeSize();
	int position;
	int maxArrSize;
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