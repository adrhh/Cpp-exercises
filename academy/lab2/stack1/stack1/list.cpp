#include "list.h"

IntListForward::IntListForward() : head(nullptr), size(0)
{
}

bool IntListForward::isEmpty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

bool IntListForward::isInRange(int n) const
{
	if(n > size)
	{ 
		error("range error");
		return false;
	}
	return true;
}

void IntListForward::push_back(int n)
{
	Node* newNode = new Node(n, nullptr);
	if (isEmpty())
			head = newNode;
	else
	{
		Node* actual = head;
		Node* prev = actual;
		while (actual != nullptr)
		{
			prev = actual;
			actual = actual->next;	
		}
		prev->next = newNode;
	}
	size++;
}

int IntListForward::pop_back()
{
	int returnedInt = 0;
	if (isEmpty())
		error("list is empty");
	else
	{
		Node* actual = head;
		Node* prev = actual;
		Node* prev_prev = prev;
		while (actual != nullptr)
		{
			prev_prev = prev;
			prev = actual;
			actual = actual->next;	
		}
		returnedInt = prev->value;
		delete prev;
		prev_prev->next = nullptr;
		size--;
	}
	return returnedInt;
}

void IntListForward::insert(int index, int n)
{
	if (isInRange(index))
	{
		int step = 0;
		Node* newNode = new Node(n, nullptr);
		Node* actual = head;
		while (step != index)
		{
			actual = actual->next;
			step++;
		}
		newNode->next = actual->next;
		actual->next = newNode;
		size++;
	}
}

int IntListForward::operator[](int index) const
{
	int returnedInt = 0;
	if(isInRange(index))
	{
		int step = 0;
		Node* actual = head;
		while (step != index)
		{
			actual = actual->next;
			step++;
		}
		returnedInt = actual->value;
	}
	return returnedInt;
}

IntListForward::Node& IntListForward::operator[](int index)
{
	if (isInRange(index))
	{
		int step = 0;
		Node* actual = head;
		while (step != index)
		{
			actual = actual->next;
			step++;
		}
		return *actual;
	}
}

//returns index of n value or -1 if n is not in list
int IntListForward::find_value(int n)
{
	int index = 0;
	Node* actual = head;
	while(actual != nullptr)
	{
		if (actual->value == n)
			return index;
		actual = actual->next;
		index++;
	}
	return -1;
}

void IntListForward::erase_at(int index)
{
	if (isInRange(index))
	{
		int step = 0;
		Node* actual = head;
		Node* prev = actual;
		Node* prev_prev = prev;
		while (step != index)
		{
			step++;
			prev_prev = prev;
			prev = actual;
			actual = actual->next;
		}
		delete prev;
		prev_prev->next = actual;
	}
}

