#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <vector>
#include <string>


#pragma once


namespace DataStructureTest
{
	//reference: https://www.cnblogs.com/skywang12345/p/3610187.html
	//<<Data Structures and Algorithm Analysis in C>> Chapter 6.4
	// used case: priority queue.
	class BinaryTree
	{
	public:
		BinaryTree() {};
		BinaryTree(int length);
		~BinaryTree();
		void MaxHeap_InsertTest();
		void MaxHeap_RemoveTest();

	private:
		std::vector<int> m_Heap;

		void MaxHeap_Insert(int data);
		void MaxHeap_Remove(int data);
		void MaxHeap_FilterUp();
		void MaxHeap_FilterDown(int curIdx);
		void Output(std::vector<int> myVector, std::string name);
	};



}



#endif