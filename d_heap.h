#ifndef _D_HEAP_H_
#define _D_HEAP_H_
#include <vector>
#include <string>


#pragma once


namespace DataStructureTest
{
	//reference: https://www.cnblogs.com/skywang12345/p/3610187.html
	//<<Data Structures and Algorithm Analysis in C>> Chapter 6.4
	// used case: priority queue.
	class DHeap
	{
	public:
		DHeap(size_t arity);
		~DHeap() {};
		void DHeap_InsertTest();
		void DHeap_RemoveTest();

	private:
		std::vector<int> m_DHeap;
		size_t m_Arity;
		
		bool DHeap_IsEmpty();
		bool DHeap_FindMin(int& out);
		void DHeap_Insert(int data);
		bool DHeap_DeleteMin(int& out);
		/*void MaxHeap_FilterUp();
		void MaxHeap_FilterDown(int curIdx);*/
		void Output(std::vector<int> myVector, std::string name);
	};



}



#endif
