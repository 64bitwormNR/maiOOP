//TVCETOR.H
#ifndef TVECTOR_H
#define TVECTOR_H
#define et_tvector TVectorItem

#include<iostream>
#include "tvector_item.h"
#include <memory>

class TVector
{
	public:
		TVector();
		~TVector();
		int size();
		char empty();
		std::shared_ptr<et_tvector>& operator[](int idx);
		void resize(int newsize);
		void push_back(const std::shared_ptr<et_tvectoritem>& sq);
		std::shared_ptr<et_tvectoritem> pop_back();
		void erase(int pos);
		void clear();
		friend std::ostream& operator<<(std::ostream& os, TVector& obj);

	private:
		std::shared_ptr<et_tvector> *vals;
		int len;
		int rLen;
};

#endif
