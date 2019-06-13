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
һ��m�׵�B-Tree���������ԣ�
1. ÿ���ڵ������m�����ӡ�
2. ���˸��ڵ��Ҷ�ӽڵ��⣬����ÿ���ڵ�������Ceil(m/2)�����ӡ�
3. �����ڵ㲻��Ҷ�ӽڵ㣬��������2������
4. ����Ҷ�ӽڵ㶼��ͬһ�㣬�Ҳ����������ؼ�����Ϣ
5. ÿ�����ն˽ڵ����n���ؼ�����Ϣ��P0,P1,��Pn, k1,��kn��
6. �ؼ��ֵĸ���n���㣺ceil(m/2)-1 <= n <= m-1
7. ki(i=1,��n)Ϊ�ؼ��֣��ҹؼ�����������
8. Pi(i=1,��n)Ϊָ���������ڵ��ָ�롣P(i-1)ָ������������нڵ�ؼ��־�С��ki����������k(i-1)
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




