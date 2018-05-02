#include "pch.h"
#include "queue.h"

int IntQueueAsList::pop()
{
	return list.pop_front();
}

void IntQueueAsList::push(int n)
{
	list.push_back(n);
}