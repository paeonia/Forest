#ifndef TREE_H
#define TREE_H


#include "TreeNode.h"

class Tree
{
public:
	Tree(void);
	~Tree(void);

	void add(int i);
	void print();
	int getNodeCount();
	void deleteNode(int value);

	TreeNode *root;
};


#endif
