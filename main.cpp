#include <iostream>
#include "b_tree.h"

int main(int argc, char* argv[])
{
	BTree btree;
	Node* node;
	int idx = 0;
	btree.SearchKey_BTree(1, node, idx);
	return 0;
}