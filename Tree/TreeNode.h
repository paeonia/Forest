#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
public:
	TreeNode(int i);
	~TreeNode(void);

	void print();
	int getNodeCount();
	void deleteNode( TreeNode *n);

	int value;
	TreeNode *myLeft;
	TreeNode *myRight;
};

#endif


