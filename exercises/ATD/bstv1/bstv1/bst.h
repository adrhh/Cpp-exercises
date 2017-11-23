#ifndef BST_H_
#define BST_H_

struct Node
{
	int key;
	Node* parent;
	Node* left;
	Node* right;
};

class Bst
{
private:
	Node* root;
public:
	Bst();
	void insert(int x);
	void in_order(Node* n);
	Node* get_root() { return root; };

};
#endif // !BST_H_
