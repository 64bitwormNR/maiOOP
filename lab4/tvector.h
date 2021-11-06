//TVECTOR.H

#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include "square.h"
#include <memory>

template<class E>
class TVector
{
	public:
		TVector();
		TVector(const TVector& other);
		void Erase(int pos);
		void InsertLast(const std::shared_ptr<E>& elem);
		void RemoveLast();
		const std::shared_ptr<E>& Last();
		std::shared_ptr<E>& operator[](const size_t idx);
		bool Empty();
		size_t Length();
		void Clear();
		~TVector();
	private:
		void resize(int newsize);
		std::shared_ptr<E> *vals;
		int len;
		int rLen;
};

#endif

