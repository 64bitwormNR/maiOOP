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

et_tvector& TVector::operator[](int idx)
{
	return vals[idx];
}

void TVector::resize(int newsize)
{
	vals = (et_tvector*)realloc((void*)vals, sizeof(et_tvector)*newsize);
}

void TVector::push_back(const et_tvectoritem& sq)
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
	vals[len]=TVectorItem(sq);
	len++;
}

et_tvectoritem TVector::pop_back()
{
	et_tvector ret = vals[len-1];
	erase(len-1);
	return ret.getElement();
}

void TVector::erase(int pos)
{
	memmove((void*)&(vals[pos]),(void*)&(vals[pos+1]),sizeof(et_tvector)*(len-pos-1));
	len--;
	if(len==rLen>>1)
		resize(len);
}

void TVector::clear()
{
	if(!empty())
	{
		delete vals;
		vals = NULL;
		len = 0;
		rLen = 0;
	}
}

std::ostream& operator<<(std::ostream& os, TVector& obj)
{
	os << '[';
	for(int i = 0; i < obj.len; i++)
	{
		os << obj.vals[i];
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

