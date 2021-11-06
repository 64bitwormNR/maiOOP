//TVECTOR.CPP
#include "tvector.h"
#include <iostream>
#include <cstring>

template<class E>
TVector<E>::TVector()
{
	vals = NULL;
	len = 0;
	rLen = 0;
}

template<class E>
TVector<E>::TVector(const TVector& other)
{
	len = other.len;
	rLen = other.rLen;
	vals = (std::shared_ptr<E>*)malloc(sizeof(std::shared_ptr<E>)*len);
	memcpy((void*)vals, (void*)other.vals, sizeof(std::shared_ptr<E>)*len);
}

template<class E>
void TVector<E>::Erase(int pos)
{
	if(len == 1)
	{
		Clear();
		return;
	}
	vals[pos] = NULL;
	memmove((void*)&(vals[pos]),(void*)&(vals[pos+1]),sizeof(std::shared_ptr<E>)*(len-pos-1));
	len--;
	if(len==rLen>>1)
		resize(len);
}

template<class E>
void TVector<E>::InsertLast(const std::shared_ptr<E>& elem)
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

template<class E>
void TVector<E>::RemoveLast()
{
	Erase(len-1);
}

template<class E>
const std::shared_ptr<E>& TVector<E>::Last()
{
	return vals[len-1];
}

template<class E>
std::shared_ptr<E>& TVector<E>::operator[](const size_t idx)
{
	return vals[idx];
}

template<class E>
bool TVector<E>::Empty()
{
	return len == 0;
}

template<class E>
size_t TVector<E>::Length()
{
	return len;
}

template<class E>
std::ostream& operator<<(std::ostream& os, TVector<E>& obj)
{
	os << '[';
	for(size_t i = 0; i < obj.Length(); i++)
	{
		os << obj[i].get()->Area();
		if(i != obj.Length() - 1)
			os << " ";
	}
	os << ']';
	return os;
}

template<class E>
void TVector<E>::Clear()
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

template<class E>
void TVector<E>::resize(int newsize)
{
	vals = (std::shared_ptr<E>*)realloc((void*)vals, sizeof(std::shared_ptr<E>)*newsize);
}

template<class E>
TVector<E>::~TVector()
{
	Clear();
}

