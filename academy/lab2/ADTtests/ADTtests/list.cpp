#include "list.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "pch.h"

using std::cout;
using std::endl;

//INT LIST FORWARD METHODS:

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
	else
		error("range error");
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
		size--;
		delete prev;
		prev_prev->next = actual;
	}
}

void IntListForward::reverse()
{
	if (size != 0)
	{
		std::vector<int> tempArr;
		Node* actual = head;
		Node* prev = actual;
		while (actual != nullptr)
		{
			prev = actual;
			tempArr.push_back(prev->value);
			actual = actual->next;
		}
		std::reverse(tempArr.begin(), tempArr.end());
		IntListForward temp;
		for (int i = 0; i < tempArr.size(); i++)
			temp.push_back(tempArr[i]);
		
		kill();
		head = temp.head;
	}
}

void IntListForward::kill()
{
	if (size != 0)
	{
		Node* actual = head;
		Node* prev = actual;
		while (actual != nullptr)
		{
			prev = actual;
			actual = actual->next;
			delete prev;
		}
		size = 0;
	}
}

//INT LIST 2 DIRECT METHODS:

IntList2Direct::IntList2Direct() : head(nullptr), tail(nullptr)
{

}

bool IntList2Direct::isEmpty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

void IntList2Direct::push_back(int n)
{
	Node* newNode = new Node(n, nullptr, nullptr);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else if (size == 1)
	{
		tail = newNode;
		newNode->prev = head;
		head->next = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

bool IntList2Direct::isInRange(int n) const
{
	if (n > size)
	{
		error("range error");
		return false;
	}
	return true;
}

void IntList2Direct::insert(int index, int n)
{
	if (isInRange(index))
	{
		int step = 0;
		
		if (index == 0 || index == size - 1)
		{
			push_back(n);
		}
		else
		{
			Node* newNode = new Node(n, nullptr, nullptr);
			Node* actual = head;
			Node* prev = actual;
			while (step != index)
			{
				prev = actual;
				actual = actual->next;
			}
			prev->next = newNode;
			newNode->prev = prev;
			actual->prev = newNode;
			newNode->next = actual;
		}
		size++;
	}
}

void IntList2Direct::erase_at(int index)
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
		actual->prev = prev_prev;
	}
}

int IntList2Direct::pop_back()
{
	int returnedInt = 0;
	if (isEmpty())
		error("list is empty");
	else if (size == 1)
	{
		returnedInt = head->value;
		delete head;
		head = tail = nullptr;
		size--;
	}
	else
	{
		Node* actual = tail;
		returnedInt = tail->value;
		tail = tail->prev;
		tail->next = nullptr;
		delete actual;
		size--;
	}
	return returnedInt;
}
void IntList2Direct::kill()
{
	if (size != 0)
	{
		Node* actual = head;
		Node* prev = actual;
		while (actual != nullptr)
		{
			prev = actual;
			actual = actual->next;
			delete prev;
		}
		size = 0;
	}
}

int IntList2Direct::pop_front()
{
	int returnedInt = 0;
	if (isEmpty())
		error("list is empty");
	else if (size == 1)
	{
		returnedInt = head->value;
		delete head;
		head = tail = nullptr;
		size--;
	}
	else
	{
		Node* actual = head;
		returnedInt = head->value;
		head = head->prev;
		head->prev = nullptr;
		delete actual;
		size--;
	}
	return returnedInt;
}