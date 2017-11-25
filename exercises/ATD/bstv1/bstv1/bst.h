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
	Node* bmin(Node* n) const;
	
public:
	Bst() {root = nullptr;};
	Node* next(Node* n) const;
	Node* find(int x) const;
	void insert(int x);
	void in_order(Node* n) const;
	void delete_node(Node* n);
	int get_key(Node* n) { return n->key; };
	Node* get_root() { return root; };

};
#endif // !BST_H_
