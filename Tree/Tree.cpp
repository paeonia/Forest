#include "Tree.h"

#include <iostream>

Tree::Tree(void)
{
	root = 0;
}


Tree::~Tree(void)
{
	if( root != 0 )
	{
		delete root;
	}
}

void Tree::deleteNode( int key  )
{
	TreeNode *current = root;
	TreeNode *prev;
	bool found = false;

	// search the node to be deleted
	while( current != 0 )
	{
		if( current->value == key )
		{
			found = true;
			break;
		}
		else
		{
			prev = current;
			
			if( current->value >= key )
			{
				current = current->myLeft;
			}
			else
			{
				current = current->myRight;
			}
		}
	}

	if( !found )
	{
		std::cout << "Key not found!" << std::endl;
		return;
	}

	// ----------------------------------------
	// CASE 1: the current node has no children
	if( ( current->myLeft == 0 ) && ( current->myRight == 0 ) )
	{
		if( prev->myLeft == current )
		{
			prev->myLeft = 0;
		}
		else
		{
			prev->myRight = 0;
		}
		delete current;
	}
	// ------------------------------------------------------
	// CASE 2: the current node has one child
	else if( current->myLeft == 0 && current->myRight != 0 ) // the node to be deleted has a right child
	{
		if(prev->myLeft == current)
		{
			prev->myLeft = current->myRight;
		}
		else
		{
	        prev->myRight = current->myRight;
		}
		delete current;
		
	}
	else if( current->myRight == 0 && current->myLeft != 0 ) // the node to be deleted has a left child
	{
        if( prev->myLeft == current)
		{
            prev->myLeft = current->myLeft;
		}
        else
		{
            prev->myRight = current->myLeft;
		}
		delete current;
		
	}
	// --------------------------------------------------------
	// CASE 3:
	// the current node has both right and left child
	else if( current->myLeft != 0 && current->myRight != 0 )
	{
		TreeNode *tmp = current->myRight;

		// If the current node's right child has no children		
		// copy the value from right child and delete tmp
		if( tmp->myLeft == 0 && tmp->myRight == 0 )
		{
			current->value = tmp->value;
			delete tmp;
			current->myRight = 0;
		}		
		// The current node has a left child
		// find the largest value on the left side of the
		// node and set its value to the current node
		else if( current->myRight->myLeft != 0 )
		{
			TreeNode *left_current = current->myRight;
			TreeNode *left_current_prev = current->myRight->myLeft;
			
			while( left_current->myLeft != NULL)
			{
				left_current_prev = left_current;
				left_current = left_current->myLeft;
			}
			
			current->value = left_current->value;
			delete left_current;
			left_current_prev->myLeft = 0;
		}
		// The tmp node has only right child
		// copy data from tmp to current and delete tmp
		else
		{
			current->value = tmp->value;
			current->myRight = tmp->myRight;
			delete tmp;
    }
}



}

int Tree::getNodeCount()
{
	int c = 0;
	if( root != 0 )
	{
		c = root->getNodeCount();
	}

	return c;
}

void Tree::add(int i)
{
	TreeNode *n = new TreeNode(i);
	
	// If there are no nodes in the tree
	// yet, make this the root node
	if( root == 0 )
	{
		root = n;	
	}
	else
	{
		// Search the correct place for the node
		// We'll start from the root
		TreeNode *temp = root;
		bool added = false;

		while( ! added )
		{
			// Select either the right or left subtree..

			if( i < temp->value )
			{
				if( temp->myLeft == 0 )
				{
					// add the new node as left child
					added = true;
					temp->myLeft = n;
				}
				else
				{
					// go to left branch
					temp = temp->myLeft;
				}
			}
			else
			{
				if( temp->myRight == 0 )
				{
					// add the new node as right child
					added = true;
					temp->myRight = n;
				}
				else
				{
					// go the right branch
					temp = temp->myRight;
				}
			}
		}
	}

}

void Tree::print()
{
	if( root != 0 )
	{
		root->print();
	}
}

