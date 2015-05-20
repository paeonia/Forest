#include "Tree.h"

#include <iostream>

int main()
{
	Tree tree;

	tree.add(10);
	tree.add(4);
	tree.add(15);
	tree.add(30);
	tree.add(25);
	tree.add(2);
	tree.add(3);
	tree.add(11);
	tree.add(1);
	tree.add(5);

	tree.print();
	std::cout <<"\n";

	tree.deleteNode( 10 );
	tree.deleteNode( 5 );

	tree.print();

}