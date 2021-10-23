//TVECTOR.H

#ifndef TVECTOR_H
#define TVECTOR_H
#define et_tvector Square

#include <iostream>
#include "square.h"

class TVector
{
	public:
		TVector();
		TVector(const TVector& other);
		void Erase(int pos);
		void InsertLast(const et_tvector& elem);
		void RemoveLast();
		const et_tvector& Last();
		et_tvector& operator[](const size_t idx);
		bool Empty();
		size_t Length();
		friend std::ostream& operator<<(std::ostream& os, TVector& obj);
		void Clear();
		~TVector();
	private:
		void resize(int newsize);
		et_tvector *vals;
		int len;
		int rLen;
};

#endif

