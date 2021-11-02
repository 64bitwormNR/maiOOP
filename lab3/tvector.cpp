//TVECTOR.CPP
#include "tvector.h"
#include <iostream>
#include <cstring>

TVector::TVector()
{
	vals = NULL;
	len = 0;
	rLen = 0;
}

TVector::TVector(const TVector& other)
{
	len = other.len;
	rLen = other.rLen;
	vals = (et_tvector*)malloc(sizeof(et_tvector)*len);
	memcpy((void*)vals, (void*)other.vals, sizeof(et_tvector)*len);
}

void TVector::Erase(int pos)
{
	if(len == 1)
	{
		Clear();
		return;
	}
	vals[pos] = NULL;
	memmove((void*)&(vals[pos]),(void*)&(vals[pos+1]),sizeof(et_tvector)*(len-pos-1));
	len--;
	if(len==rLen>>1)
		resize(len);
}

void TVector::InsertLast(const et_tvector& elem)
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
	vals[len] = elem;
	len++;
}

void TVector::RemoveLast()
{
	Erase(len-1);
}

const et_tvector& TVector::Last()
{
	return vals[len-1];
}

et_tvector& TVector::operator[](const size_t idx)
{
	return vals[idx];
}

bool TVector::Empty()
{
	return len == 0;
}

size_t TVector::Length()
{
	return len;
}

std::ostream& operator<<(std::ostream& os, TVector& obj)
{
	os << '[';
	for(int i = 0; i < obj.len; i++)
	{
		os << obj.vals[i].get()->Area();
		if(i != obj.len - 1)
			os << " ";
	}
	os << ']';
	return os;
}

void TVector::Clear()
{
	if(!Empty())
	{
		for(int i=0;i<len;i++)
			vals[i]=NULL;
		free(vals);
		vals = NULL;
		len = 0;
		rLen = 0;
	}
}

void TVector::resize(int newsize)
{
	vals = (et_tvector*)realloc((void*)vals, sizeof(et_tvector)*newsize);
}

TVector::~TVector()
{
	Clear();
}

