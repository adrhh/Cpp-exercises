#pragma once
#ifndef QE_H_
#define QE_H_

class Customer
{
private:
	long arr;
	int proc;
public:
	Customer()
	{
		arr = 0;
		proc = 0;
	}
	void set(long when);
	long when() const { return arr; }
	long ptime() const { return proc; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int qcount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};


#endif // !QE_H_
