//TALLOCATOR.H
#ifndef TALLOCATOR_H
#define TALLOCATOR_H

#include "tlinkedlist.h"

class TAllocator
{
	public:
		TAllocator(int size, int bunchSize);
		void* Allocate();
		void Deallocate(void* ptr);
		~TAllocator();

	private:
		int elemSize;
		int bunchSize;
		TLinkedList *notused;
		TLinkedList *used;
		TLinkedList *allocated;
};

#endif
