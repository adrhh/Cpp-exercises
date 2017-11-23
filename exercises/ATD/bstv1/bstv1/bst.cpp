#include "bst.h"
#include <iostream>

using std::cout;

Bst::Bst()
{
	root = nullptr;
}

void Bst::insert(int x)
{
	Node* temp = nullptr;
	Node* act = root;

	Node* add = new Node;
	add->key = x;
	add->parent = nullptr;
	add->left = nullptr;
	add->right = nullptr;

	while (act != nullptr)
	{
		temp = act;
		if (x < act->key)
			act = act->left;
		else
			act = act->right;
	}
	add->parent = temp;
	if (temp == nullptr)
		root = add;
	else
	{
		if (add->key < temp->key)
			temp->left = add;
		else
			temp->right = add;
	}
}

void Bst::in_order(Node* n)
{

	if (n != nullptr)
	{
		in_order(n->left);
		cout << n->key;
		in_order(n->right);
	}
}

