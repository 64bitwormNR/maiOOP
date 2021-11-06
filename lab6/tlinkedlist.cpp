//TLINKEDLIST.CPP
#include "tlinkedlist.h"

TLinkedList::TLinkedList()
{
	root = NULL;
	len = 0;
}

TNode* TLinkedList::First()
{
	return GetItem(0);
}

TNode* TLinkedList::Last()
{
	return GetItem(len-1);
}

int TLinkedList::Find(void* ptr)
{
	int ret = 0;
	TNode *cur = root;
	while(cur)
	{
		if(cur->ptr==ptr)
			return ret;
		cur = cur->next;
		ret++;
	}
	return -1;
}

void TLinkedList::InsertFirst(TNode *elem)
{
	Insert(elem, 0);
}

void TLinkedList::InsertLast(TNode *elem)
{
	Insert(elem, len);
}

void TLinkedList::Insert(TNode *elem, size_t position)
{
	if(len==0)
	{
		root = elem;
		elem->next = NULL;
	}
	else if(position==0)
	{
		elem->next = root;
		root = elem;
	}
	else
	{
		TNode *last = GetItem(position-1);
		elem->next = last->next;
		last->next = elem;
	}
	len++;
}

void TLinkedList::RemoveFirst()
{
	Remove(0);
}

void TLinkedList::RemoveLast()
{
	Remove(len-1);
}

void TLinkedList::Remove(size_t position)
{
	if(len==1)
	{
		root = NULL;
	}
	else if(position)
	{
		TNode *prev = GetItem(position-1);
		prev->next = prev->next->next;
	}
	else
	{
		root = root->next;
	}
	len--;
}

void TLinkedList::RemoveNulls()
{
	while(First()->ptr==NULL)
		RemoveFirst();
	TNode *cur = root;
	while(cur->next)
	{
		if(cur->next->ptr)
		{
			cur = cur->next;
		}
		else
		{
			cur->next = cur->next->next;
		}
	}
}

TNode* TLinkedList::GetItem(size_t idx)
{
	TNode *cur = root;
	while(idx--)
		cur = cur->next;
	return cur;
}

size_t TLinkedList::Length()
{
	return len;
}

std::ostream& operator<<(std::ostream& os, TLinkedList& list)
{
	TNode *cur = list.root;
	while(cur)
	{
		os << cur->ptr << ' ';
		cur = cur->next;
	}
	return os;
}

void TLinkedList::Clear()
{
	root = NULL;
	len = 0;
}

TLinkedList::~TLinkedList()
{
	Clear();
}
