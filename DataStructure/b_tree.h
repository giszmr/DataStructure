#ifndef _B_TREE_H_
#define _B_TREE_H_

#pragma once

#include <iostream>
#include <cstdlib>

#define M 3
typedef int KeyType;


typedef struct Node
{
	int keyNum;
	Node* parent;
	KeyType key[M + 1];  //key[0] not used
	Node* ptr[M + 1];
	Node() :keyNum(0), parent(NULL)
	{
		for (int i = 0; i <= M; i++)
		{
			key[i] = 0;
			ptr[i] = NULL;
		}
	}
}Node;

typedef struct  // result of search
{
	Node* node; // node that found
	int idx;    // position of the key
	int tag;    // success or fail of search
}Result;







/***
一棵m阶的B-Tree有如下特性：
1. 每个节点最多有m个孩子。
2. 除了根节点和叶子节点外，其它每个节点至少有Ceil(m/2)个孩子。
3. 若根节点不是叶子节点，则至少有2个孩子
4. 所有叶子节点都在同一层，且不包含其它关键字信息
5. 每个非终端节点包含n个关键字信息（P0,P1,…Pn, k1,…kn）
6. 关键字的个数n满足：ceil(m/2)-1 <= n <= m-1
7. ki(i=1,…n)为关键字，且关键字升序排序。
8. Pi(i=1,…n)为指向子树根节点的指针。P(i-1)指向的子树的所有节点关键字均小于ki，但都大于k(i-1)
***/
class BTree
{
public:
	BTree();
	Node* GetHead() { return m_head; };
	bool SearchKey_BTree(KeyType key, Node* &recNode, int& recIndex);
	bool InsertKey_BTree(KeyType key);
	//bool Delete_BTree(KeyType key);
	//void Destroy(Node* & node);
	//void WalkThrough(Node* & node);


private:
	int SearchKey_BTreeNode(Node*& node, KeyType key);
	void InsertKey_BTreeNode(Node*& curNode, int idx, KeyType key, Node* node);
	bool split(Node*& curNode, int midKeyIdx, Node*& newNode, KeyType& midKey);
	bool NewRoot(Node*& head, Node*& lhs, KeyType midKey, Node*& rhs);
	//void RotateLeft(Node* parent, int idx, Node* cur, Node* rsilb);
	//void RotateRight(Node* parent, int idx, Node* cur, Node* rsilb);
	//void Merge(Node* parent, int idx, Node* lsilb, Node* cur);
	//void DeleteBalance(Node* curNode);
	//void Delete(Node* curNode, int curIdx);


	Node* m_head;

};



#endif




