#include "b_tree.h"

using namespace DataStructureTest;

BTree::BTree()
{
	this->m_head = NULL;
}


/*
description: find the postion of 'key' in current node
paremeter  : node, pointer of current node
			 key,  new key 
return     : key=key[1...M], key is in current node
			 key¡Ùkey[1...M], key is in ptr[i] node, i¡Ê[0...M]
*/
int BTree::SearchKey_BTreeNode(Node*& node, KeyType key)
{
	if (node == nullptr)
		return -1;
	int i;
	for (i = 0; i < node->keyNum && node->key[i+1] <= key; i++);
	return i;
}



bool BTree::SearchKey_BTree(KeyType key, Node* & recNode, int& recIdx)
{
	Node* pNode = m_head;

	while (pNode)
	{
		int idx = this->SearchKey_BTreeNode(pNode, key);
		if (idx >= 0)
		{
			if (pNode->key[idx] == key)
			{
				recNode = pNode;
				recIdx = idx;
				return true;
			}
			else
			{
				recNode = pNode;
				recIdx = idx;
				pNode = pNode->ptr[idx];
			}
		}
	}

	return false;
}


void BTree::InsertKey_BTreeNode(Node*& curNode, int idx, KeyType key, Node* node)
{
	for (int i = curNode->keyNum; i > idx; i--)
	{
		curNode->key[i + 1] = curNode->key[i];
		curNode->ptr[i + 1] = curNode->ptr[i];
	}

	curNode->key[idx + 1] = key;   //should be [idx + 1], not [idx]
	curNode->ptr[idx + 1] = node;

	++curNode->keyNum;
}


bool BTree::split(Node*& curNode, int midKeyIdx, Node*& newNode, KeyType& midKey)
{
	//newNode is used to preserve right side of curNode after splitting.
	newNode = new Node;
	if (!newNode)
	{
		std::cerr << "overflow_error!" << std::endl;
		return false;
	}

	//after splitting of curNode, parent of newNode and curNode are the same.
	newNode->parent = curNode->parent;
	
	//get the value of midKey
	midKey = curNode->key[midKeyIdx];

	curNode->key[midKeyIdx] = 0;
	//child(ptr[0]) of newNode should be curNode->ptr[midKeyIdx]
	newNode->ptr[0] = curNode->ptr[midKeyIdx];
	//Originaly, if curNode->ptr[midKeyIdx]!=nullptr, now, its parent should be newNode.
	if (newNode->ptr[0])
	{
		newNode->ptr[0]->parent = newNode;
	}
	curNode->ptr[midKeyIdx] = nullptr;


	//copy right side of curNode to newNode
	for (int i = 1; i <= M - midKeyIdx; i++)
	{
		newNode->key[i] = curNode->key[midKeyIdx + 1];
		newNode->ptr[i] = curNode->ptr[midKeyIdx + 1];
		curNode->key[midKeyIdx + 1] = 0;
		curNode->ptr[midKeyIdx + 1] = nullptr;

		//modify parent of newNode's new children.
		if (newNode->ptr[i])
			newNode->ptr[i]->parent = newNode;
	}

	newNode->keyNum = M - midKeyIdx;
	curNode->keyNum = midKeyIdx - 1;  //midKey will be add to parent node

	return true;

}


bool BTree::NewRoot(Node*& head, Node*& lhs, KeyType midKey, Node*& rhs)
{
	Node* tmpNode = new Node;
	if (!tmpNode)
	{
		std::cerr << "overflow_error!" << std::endl;
		return false;
	}

	tmpNode->keyNum = 1;
	tmpNode->key[1] = midKey;
	tmpNode->ptr[0] = lhs;
	if(tmpNode->ptr[0])
	{
		tmpNode->ptr[0]->parent = tmpNode;
	}
	tmpNode->ptr[1] = rhs;
	if (tmpNode->ptr[1])
	{
		tmpNode->ptr[1]->parent = tmpNode;
	}

	head = tmpNode;
	return true;
}


bool BTree::InsertKey_BTree(KeyType key)
{
	Node* curNode = nullptr;
	int curIdx = -1;
	if (this->SearchKey_BTree(key, curNode, curIdx))
	{
		std::cout << "Key[" << key << "] is already existed in this tree." << std::endl;
		return false;
	}
	else //key is not in this tree. start to insert it.
	{
		bool finished = false;
		Node* newNode = nullptr;  //new node after splitting
		KeyType midKey = key;     //middle key that used to split current node. and it will be insert into its parent node.

		while (!finished && curNode)
		{
			this->InsertKey_BTreeNode(curNode, curIdx, midKey, newNode);
			if (curNode->keyNum < M)   //keyNum should be less than M
			{
				finished = true;
			}
			else
			{
				int midKeyIdx = (M + 1) / 2;
				if (!this->split(curNode, midKeyIdx, newNode, midKey))    //split failed
				{
					return false;
				}

				if (curNode->parent == nullptr)
				{
					break;
				}
				else
				{
					curNode = curNode->parent;
					curIdx = this->SearchKey_BTreeNode(curNode, midKey); //find the position to insert midKey.
				}
			}
		}


		//if root is nullptr, or root is already split.
		if(!finished && !this->NewRoot(m_head, curNode, midKey, newNode))
		{
			std::cerr << "failed to create a new root." << std::endl;
			exit(EXIT_FAILURE);
		}

		return true;
	}
}










