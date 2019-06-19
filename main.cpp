#include <iostream>
#include "b_tree.h"
#include "binary_tree.h"
#include "d_heap.h"

using namespace DataStructureTest;

int main(int argc, char* argv[])
{
	//BTree btree;
	//Node* node;
	//int idx = 0;
	//btree.SearchKey_BTree(1, node, idx);



	//BinaryTree binarytree(10);
	//binarytree.MaxHeap_InsertTest();
	//binarytree.MaxHeap_RemoveTest();



	DHeap dheap(3);
	dheap.DHeap_InsertTest();
	dheap.DHeap_RemoveTest();


	return 0;
}