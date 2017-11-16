#ifndef STACK2_H_
#define STACK2_H

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX=10};
	Item *pitems;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack& s);
	~Stack();
	Item getitem();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& s);
};

#endif // !STACK2_H_
