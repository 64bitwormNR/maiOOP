//TVCETOR.CPP
#include "tvector.h"
#include <iostream>
#include <cstring>

TVector::TVector()
{
	vals = NULL;
	len = 0;
	rLen = 0;
}

int TVector::size()
{
	return len;
}

char TVector::empty()
{
	return len == 0;
}

std::shared_ptr<et_tvector>& TVector::operator[](int idx)
{
	return vals[idx];
}

void TVector::resize(int newsize)
{
	vals = (std::shared_ptr<et_tvector>*)realloc((void*)vals, sizeof(std::shared_ptr<et_tvector>)*newsize);
}

void TVector::push_back(const std::shared_ptr<et_tvectoritem>& sq)
{
	if(rLen)
	{
		if(len>=rLen)
		{
			rLen<<=1;
			resize(rLen);
		}
	}
	else
	{
		rLen=1;
		resize(rLen);
	}
	vals[len]=std::shared_ptr<TVectorItem>(new TVectorItem(sq));
	len++;
}

std::shared_ptr<et_tvectoritem> TVector::pop_back()
{
	std::shared_ptr<et_tvector> ret = vals[len-1];
	erase(len-1);
	return ret->getElement();
}

void TVector::erase(int pos)
{
	for(int i = pos; i < len - 1; i++)
	{
		vals[i] = vals[i + 1];
	}
	len--;
	if(len==rLen>>1)
		resize(len);
}

void TVector::clear()
{
	if(!empty())
	{
		for(int i = 0; i < len; i++)
			vals[i] = NULL;
		delete vals;
		len = 0;
		rLen = 0;
	}
}

std::ostream& operator<<(std::ostream& os, TVector& obj)
{
	os << '[';
	for(int i = 0; i < obj.len; i++)
	{
		os << *(obj.vals[i]);
		if(i != obj.len - 1)
			os << ", ";
	}
	os << ']';
	return os;
}

TVector::~TVector()
{
	clear();
}
