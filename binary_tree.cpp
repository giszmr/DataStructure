#include "binary_tree.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace DataStructureTest;

BinaryTree::BinaryTree(int length)
{
	m_Heap.reserve(length);
}



BinaryTree::~BinaryTree()
{

}


void BinaryTree::MaxHeap_FilterUp()
{
	int curIdx = (int)m_Heap.size() - 1;
	int parIdx = (curIdx - 1) / 2;
	int tmp = m_Heap.at(curIdx);

	while (curIdx > 0)
	{
		if (m_Heap.at(parIdx) >= tmp)
			break;
		else
		{
			m_Heap.at(curIdx) = m_Heap.at(parIdx);
			curIdx = parIdx;
			parIdx = (curIdx - 1) / 2;
		}
	}
	m_Heap.at(curIdx) = tmp;
}



void BinaryTree::MaxHeap_FilterDown(int idx)
{
	int curIdx = idx;
	int leftChildIdx = curIdx * 2 + 1;
	int tmp = m_Heap.at(idx);

	while (leftChildIdx < (int)m_Heap.size())
	{
		if (leftChildIdx + 1 < (int)m_Heap.size()    //if the value of "leftChildIdx" is "m_Heap.size()-1", then "leftChildIdx + 1" will overflow.
			&& m_Heap.at(leftChildIdx) < m_Heap.at(leftChildIdx + 1))
		{
			leftChildIdx++;
		}

		if (tmp >= m_Heap.at(leftChildIdx))
			break;
		m_Heap.at(curIdx) = m_Heap.at(leftChildIdx);
		curIdx = leftChildIdx;
		leftChildIdx = curIdx * 2 + 1;
	}
	m_Heap.at(curIdx) = tmp;
}


void BinaryTree::MaxHeap_Insert(int data)
{
	m_Heap.emplace_back(data);
	MaxHeap_FilterUp();
}




void BinaryTree::MaxHeap_Remove(int data)
{
	auto iter = std::find(m_Heap.begin(), m_Heap.end(), data);
	
	*iter = *(m_Heap.end() - 1);
	m_Heap.erase(m_Heap.end() - 1);
	if (m_Heap.size() > 0)  //there is no use to filter down when size of m_Heap is 0.
		MaxHeap_FilterDown((int)(iter - m_Heap.begin()));
}



void BinaryTree::MaxHeap_InsertTest()
{
	for (int i = 0; i < 10; i++)
	{
		MaxHeap_Insert(i);
	}
	Output(m_Heap, "myHeap");
}


void BinaryTree::MaxHeap_RemoveTest()
{
	for (int i = 9; i >= 0; i--)   //type of "i" should not be size_t. Because when i = 0, then i-1 will be "-1"(the max value) of type size_t.
	{
		MaxHeap_Remove(i);
		Output(m_Heap, "myHeap");
	}
}




void BinaryTree::Output(std::vector<int> myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (auto it : myVector) std::cout << it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}