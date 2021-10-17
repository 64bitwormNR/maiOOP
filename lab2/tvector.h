//TVECTOR.H
#ifndef TVECTOR_H
#define TVECTOR_H
#define et_tvector TVectorItem

#include<iostream>
#include "tvector_item.h"

class TVector
{
	public:
		TVector();
		~TVector();
		int size();
		char empty();
		et_tvector& operator[](int idx);
		void resize(int newsize);
		void push_back(const et_tvectoritem& sq);
		et_tvectoritem pop_back();
		void erase(int pos);
		void clear();
		friend std::ostream& operator<<(std::ostream& os, TVector& obj);

	private:
		et_tvector *vals;
		int len;
		int rLen;
};

#endif
