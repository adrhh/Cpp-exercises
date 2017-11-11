#ifndef LIST_H_
#define LIST_H_

#include <iostream>

using std::cout;
using std::endl;

const int MAX = 10;
typedef int item;

struct node
{
	item value;
	node* next;
	node* prev;
};

void mult(node* s, item x);
void show(node* s, item x = 0);


static node* head = new node { 0, NULL, NULL };

class List
{
private:
	node nod;
	
public:
	int counter = 0;
	bool isempty() const;
	bool isfull() const;
	bool add(item x);
	bool append(item x);
	void showall() const;
	void visit(void(*pf)(node*, item), item x=0);
	void visit_back(void(*pf)(node*, item), item x = 0);
};

#endif // !LIST_H_
