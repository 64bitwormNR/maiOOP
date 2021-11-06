//TITERATOR.H

#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>

template<class E> class TIterator
{
	public:
		TIterator<E>(std::shared_ptr<E> *vct, int ix)
		{
			vect = vct;
			idx = ix;
		}

		E* operator*()
		{
			return vect[idx].get();
		}

		E* operator->()
		{
			return vect[idx].get();
		}

		void operator++()
		{
			idx++;
		}

		TIterator<E> operator++(int)
		{
			TIterator iter(vect,idx);
			++(*this);
			return iter;
		}

		bool operator==(TIterator const& i)
		{
			return idx == i.idx;
		}

		bool operator!=(TIterator const& i)
		{
			return idx != i.idx;
		}

	private:
		std::shared_ptr<E> *vect;
		int idx;
};

#endif
