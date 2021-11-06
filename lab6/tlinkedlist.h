//TLINKEDLIST.H
#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include <iostream>

class TNode
{
	public:
		TNode(void *data)
		{
			ptr = data;
		}
		void *ptr;
		TNode *next;
};

class TLinkedList
{
	public:
		TLinkedList();
		TNode* First();
		TNode* Last();
		int Find(void* ptr);
		void InsertFirst(TNode *elem);
		void InsertLast(TNode *elem);
		void Insert(TNode *elem, size_t position);
		void RemoveFirst();
		void RemoveLast();
		void Remove(size_t position);
		void RemoveNulls();
		TNode* GetItem(size_t idx);
		size_t Length();
		friend std::ostream& operator<<(std::ostream& os, TLinkedList& list);
		void Clear();
		~TLinkedList();
	private:
		TNode *root;
		int len;
};

#endif
