//#define USE_INCLUDES

#ifdef USE_INCLUDES
#include <iostream>
#else
import std.core;
#endif

#include "binary_tree.h"
#include "linked_list.h"

int main()
{
	std::cout << std::endl << "#BINARY TREE#" << std::endl;

	BinaryTree<int> tree(1);

	std::cout << "1 was added to the tree" << std::endl;

	tree.Add(10);

	std::cout << "10 was added to the tree" << std::endl;

	std::cout << "Tree contains 1: " << tree.Contains(1) << std::endl;
	std::cout << "Tree contains 6: " << tree.Contains(6) << std::endl;
	std::cout << "Tree contains 10: " << tree.Contains(10) << std::endl;

	std::cout << std::endl << "#LINKED LIST#" << std::endl;

	LinkedList<int> linked_list(10);

	linked_list.Place(30);
	linked_list.Place(402);
	linked_list.Place(123);
	linked_list.Place(2, 1);
	linked_list.Place(7, 0);

	const int lenght = linked_list.GetLenght();

	for (int i = 0; i < lenght; ++i)
	{
		std::cout << "At " << i << " : " << linked_list.Get(i) << std::endl;;
	}

	return 0;
}