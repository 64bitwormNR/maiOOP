//TALLOCATOR.CPP
#include "tallocator.h"

TAllocator::TAllocator(int size, int bnchSize)
{
	elemSize = size;
	bunchSize = bnchSize;
	notused = new TLinkedList();
	used = new TLinkedList();
	allocated = new TLinkedList();
}

void* TAllocator::Allocate()
{
	if(notused->Length()==0)
	{
		char *newBlock = (char*)malloc(sizeof(TNode)+(elemSize+sizeof(TNode))*bunchSize);
		TNode *newBlockNode = new(newBlock) TNode(newBlock);
		allocated->InsertFirst(newBlockNode);
		for(int i=0;i<bunchSize;i++)
		{
			char* offset = newBlock+sizeof(TNode)+i*(elemSize+sizeof(TNode));
			TNode *newNode = new(offset+elemSize) TNode(offset);
			notused->InsertFirst(newNode);
		}
	}
	TNode *notusedElem = notused->First();
	notused->RemoveFirst();
	used->InsertFirst(notusedElem);
	return notusedElem->ptr;
}

void TAllocator::Deallocate(void* ptr)
{
	int regionSize = (sizeof(TNode)+(elemSize+sizeof(TNode))*bunchSize);
	char *mptr = NULL;
	int mid = -1;
	for(size_t i=0;i<allocated->Length();i++)
	{
		char* memptr = (char*)(allocated->GetItem(i)->ptr);
		if(ptr>=memptr && ptr<memptr+regionSize)
		{
			mptr = memptr;
			mid = i;
			break;
		}
	}
	int usedElem = used->Find(ptr);
	TNode *usedNode = used->GetItem(usedElem);
	used->Remove(usedElem);
	notused->InsertFirst(usedNode);
	char regionUsed = 0;
	TNode *cur = used->First();
	while(cur)
	{
		if(cur->ptr>=mptr && cur->ptr<mptr+regionSize)
		{
			regionUsed = 1;
			break;
		}
		cur=cur->next;
	}
	if(!regionUsed)
	{
		free(mptr);
		allocated->Remove(mid);
	}
}

TAllocator::~TAllocator()
{
	for(size_t i=0;i<allocated->Length();i++)
		free((char*)(allocated->GetItem(i)->ptr));
	delete notused;
	delete used;
	delete allocated;
}
