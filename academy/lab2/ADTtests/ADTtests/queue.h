#ifndef QUEUE_H_
#define QUEUE_H_
#include "list.h"

class IntQueue
{
	virtual void push(int n) = 0;
	virtual int pop() = 0;
};

class IntQueueAsList : public IntQueue
{
private:
	IntList2Direct list;
public:
	IntQueueAsList() {};
	int pop();
	void push(int n);
};

#endif // !QUEUE_H
