#include "queue1.h"

template <typename T>
Queue<T>::Queue(int n) : qsize(n)
{
	front = rear = nullptr;
	items = 0;
}

template <typename T>
bool Queue<T>::enqueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = it;
	add->next = nullptr;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;

	return true;
}

template <typename T>
Queue<T>::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename T>
bool Queue<T>::dequeue(T& item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}