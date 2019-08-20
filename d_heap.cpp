#include <algorithm>
#include <iomanip>
#include <iostream>
#include "d_heap.h"

using namespace DataStructureTest;


DHeap::DHeap(size_t arity) :m_Arity(arity)
{
}



bool DHeap::DHeap_IsEmpty()
{
	return m_DHeap.empty();
}

bool DHeap::DHeap_FindMin(int &out)
{
	if (m_DHeap.empty())
		return false;

	out = m_DHeap[0];
	return true;
}

void DHeap::DHeap_Insert(int data)
{
	if (m_DHeap.size() == 0)
	{
		m_DHeap.push_back(data);
		return;
	}

	size_t idx = m_DHeap.size();
	m_DHeap.resize(m_DHeap.size() + 1);
	while (m_DHeap[(idx - 1) / m_Arity] > data)
	{
		m_DHeap[idx] = m_DHeap[(idx - 1) / m_Arity];
		idx = (idx - 1) / m_Arity;
		if (idx == 0) break;
	}
	m_DHeap[idx] = data;
}

bool DHeap::DHeap_DeleteMin(int &out)
{
	if (m_DHeap.size() == 0)
		return false;

	out = m_DHeap[0];

	size_t idx = 0;
	size_t minChildIdx = 0;
	int lastElement = m_DHeap[m_DHeap.size() - 1];
	while (idx * m_Arity + 1 < m_DHeap.size())
	{
		minChildIdx = idx * m_Arity + 1;
		//find the smallest in children
		size_t i = 1;
		size_t curMinChildIdx = minChildIdx;
		while (i < m_Arity)
		{
			if (minChildIdx + i == m_DHeap.size()) break;

			if (m_DHeap[curMinChildIdx] > m_DHeap[minChildIdx + i])
			{
				curMinChildIdx = minChildIdx + i;
			}
			i++;
		}

		if (lastElement > m_DHeap[minChildIdx])
			m_DHeap[idx] = m_DHeap[minChildIdx];
		else
			break;
		idx = minChildIdx;
	}

	m_DHeap[idx] = lastElement;
	m_DHeap.erase(m_DHeap.end() - 1);

	return true;
}





void DHeap::DHeap_RemoveTest()
{
	std::cout << "\n********DHeap_RemoveTest*********" << std::endl;


	while (m_DHeap.size())
	{
		int out = 0;
		if(DHeap_DeleteMin(out))
		{
			std::cout << std::setw(2) << out << " | ";
			Output(m_DHeap, "myDHeap");
		}
	}

}

void DHeap::DHeap_InsertTest()
{
	std::cout << "\n********DHeap_InsertTest*********" << std::endl;


	for (int i = 0; i < 20; i++)
	{
		DHeap_Insert(i);
	}
	Output(m_DHeap, "myDHeap");

	for (int i = 5; i < 15; i++)
	{
		DHeap_Insert(i);
	}
	Output(m_DHeap, "myDHeap");
}


void DHeap::Output(std::vector<int> myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (auto it : myVector) std::cout << std::setw(2) << it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}




