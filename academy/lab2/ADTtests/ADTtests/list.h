#ifndef LIST_H_
#define LIST_H_
#include "err.h"
#include <ostream>

class IntList
{
public:
	virtual void push_back(int n) = 0;
	virtual void insert(int index, int n) = 0;
	virtual void erase_at(int index) = 0;
	virtual int pop_back() = 0;
	//virtual int find_value(int n) = 0;
	virtual int operator[](int index) const = 0;
	virtual void reverse() = 0;
};

class IntListForward : public IntList
{
private:
	struct Node
	{
		int value;
		Node* next;
		Node(int n, Node* ptr) : value(n), next(ptr) {}
		void operator=(int n) { value = n; }
		friend std::ostream& operator<<(std::ostream& os, Node& nd) 
			{ os << nd.value; return os; }
	};
	Node* head;

	int size;
	bool isInRange(int n) const;
	void kill();
public:
	IntListForward();
	~IntListForward() { size = 0; kill(); };
	bool isEmpty() const;
	void push_back(int n);
	void insert(int index, int n);
	void erase_at(int index);
	void reverse();
	int pop_back();
	int find_value(int n);
	int operator[](int index) const;
	//Node& operator[](int index);
};

class IntList2Direct : public IntList
{
private:
	struct Node
	{
		int value;
		Node* next;
		Node* prev;
		Node(int n, Node* nptr, Node* pptr) : value(n), next(nptr), prev(pptr) {}
	};
	Node* head;
	Node* tail;
	int size;
	bool isInRange(int n) const;
	void kill();
	bool isEmpty() const;
public:
	IntList2Direct();
	~IntList2Direct() { size = 0;  kill(); };
	void push_back(int n);
	void insert(int index, int n);
	void erase_at(int index);
	void reverse(); 
	int pop_back();
	int pop_front();
	int operator[](int index) const;
};

#endif // !LIST_H_
