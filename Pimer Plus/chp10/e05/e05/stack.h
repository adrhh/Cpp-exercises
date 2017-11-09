#ifndef STACK_H_
#define STACK_H_

const int LEN = 35;

struct Customer
{
	char fullname[LEN];
	double payment;
};

typedef Customer Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top;
	static double total_pay;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif // !STACK_H_
