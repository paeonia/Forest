#include "TreeNode.h"
#include <iostream>


TreeNode::TreeNode( int i )
{
	value = i;
	myLeft = 0;
	myRight = 0;
}


TreeNode::~TreeNode(void)
{
	if( myRight != 0 )
	{
		delete myRight;
	}

	if( myLeft != 0 )
	{
		delete myLeft;
	}
}

int TreeNode::getNodeCount()	 
{
	int c = 1;

	if( myLeft != 0 )
	{
		c += myLeft->getNodeCount();
	}
	
	if( myRight != 0 )
	{
		c += myRight->getNodeCount();
	}

	return c;
}

// Prints the subtree
void TreeNode::print()
{
	// print left subtree
	if( myLeft != 0 )
	{
		myLeft->print();
	}

	// print this node
	std::cout << value << " ";

	// print right subtree
	if( myRight != 0 )
	{
		myRight->print();
	}

}