#include "stack.h"

IntStackOnArrConstSizeChange::IntStackOnArrConstSizeChange(int arrSize) : position(0), maxArrSize(arrSize)
{
	valuesArr = new int[maxArrSize];
}

int IntStackOnArrConstSizeChange::pop()
{
	if (isEmpty())
		error("Stack is empty, can't pop element");
	return valuesArr[--position];
}

bool IntStackOnArrConstSizeChange::isEmpty() const
{
	if (position == 0)
		return true;
	else
		return false;
}

IntStackOnArrConstSizeChange::~IntStackOnArrConstSizeChange()
{
	delete[] valuesArr;
}

void IntStackOnArrConstSizeChange::push(int n)
{
	if (maxArrSize <= position)
		changeSize();

	valuesArr[position++] = n;
}

void IntStackOnArrConstSizeChange::changeSize()
{
	maxArrSize += maxArrSize;
	int* nPtr = new int[maxArrSize];
	for (int i = 0; i < position; i++)
		nPtr[i] = valuesArr[i];
	
	delete[] valuesArr;
	valuesArr = nPtr;
}

bool IntStackAsForwardList::isEmpty() const
{
	if (ifList.isEmpty())
		return true;
	else
		return false;
}

int IntStackAsForwardList::pop()
{
	return ifList.pop_back();
}

void IntStackAsForwardList::push(int n)
{
	ifList.push_back(n);
}