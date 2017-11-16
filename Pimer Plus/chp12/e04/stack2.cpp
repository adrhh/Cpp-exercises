#include "stack2.h"
#include <iostream>

Stack::Stack(int n)
{
	top = 0;
	size = 0;
	pitems = new Item[n];
}

//konstruktor kopjujacy
Stack::Stack(const Stack& s)
{
	size = s.size;
	pitems = new Item[MAX]{0};
	for (int i = 0; i < size; i++)
		pitems[i] = s.pitems[i];
	top = s.top;
}
Stack::~Stack()
{
	delete[] pitems;
}
bool Stack::isempty() const
{
	return top == 0;
}
bool Stack::isfull() const
{
	return top == MAX;
}
bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		size++;
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = pitems[--top];
		size--;
		std::cout << "Usunieto wartosc: " << pitems[top] << std::endl;
		return true;
	}
	else
		return false;
}

Item Stack::getitem()
{
	if (size)
		return pitems[top];
	else
		return 0.0;
}

Stack& Stack::operator=(const Stack& s)
{
	delete[] pitems;
	top = s.top;
	size = s.size;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = s.pitems[i];

	return *this;
}