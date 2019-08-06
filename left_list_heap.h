//#ifndef _LEFT_LIST_HEAP_H_
//#define _LEFT_LIST_HEAP_H_
//#include <vector>
//#include <string>
//
//
//#pragma once
//
//
//namespace DataStructureTest
//{
//	template <class T>
//	class LeftListNode
//	{
//	public:
//		T key;
//		int npl;
//		LeftListNode* left;
//		LeftListNode* right;
//
//		LeftListNode(T value, LeftListNode* l, LeftListNode* r) :key(value), npl(0), left(l), right(r) {}
//	};
//
//
//
//	template <class T>
//	class LeftListHeap
//	{
//	public:
//		LeftListHeap() {};
//		~LeftListHeap() {};
//
//
//		void PreOrder();
//		void InOrder();
//		void PostOrder();
//		bool Insert(T key);
//		bool Remove(T key);
//		bool Merge(LeftListNode<T>* other);
//		void Destroy();
//
//
//		void LeftListHeap_InsertTest();
//		void LeftListHeap_RemoveTest();
//
//	private:
//		void PreOrder(LeftListNode<T>* heap) const;
//		void InOrder(LeftListNode<T>* heap) const;
//		void PostOrder(LeftListNode<T>* heap) const;
//		void SwapNode(LeftListNode<T>*& x, LeftListNode<T>*& y);
//		LeftListNode<T>* Merge(LeftListNode<T>*& x, LeftListNode<T>*& y);
//		LeftListNode<T>* Insert(LeftListNode<T>*& heap, T key);
//		LeftListNode<T>* Remove(LeftListNode<T>*& heap, T key);
//		void Destroy(LeftListNode<T>*& heap);
//
//		void Output(LeftListNode<T>*& heap, T key, int direction);
//	};
//
//
//
//}
//
//
//
//#endif