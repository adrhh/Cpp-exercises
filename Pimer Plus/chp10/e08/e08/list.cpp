#include "list.h"

bool List::isempty() const
{
	return !counter ? true : false;
}

bool List::isfull() const
{
	return ((counter+1) > MAX) ? true : false;
}

bool List::add(item x)
{	
	bool answ;

	if (isfull())
		answ = false;
	else
	{
		if (isempty())
		{
			head->value = x;
			counter++;
		}
		else
		{
			node* n = new node {x, head, NULL};
			head->prev = n;
			head = n;
			counter++;
		}
		answ = true;
	}

	return answ;
}

void List::showall() const
{
	int i = counter;
	node *actual = head;
	while (i--)
	{
		cout << actual->value << endl;
		actual = actual->next;
	}
}


void List::visit(void(*pf)(node*, item), item x)
{
	int i = counter;
	node *actual = head;
	while (i--)
	{
		pf(actual, x);
		actual = actual->next;
	}
}


void show(node* s, item x)
{
	cout << s->value << endl;
}


void mult(node* s, item x)
{
	s->value = s->value *x;
}