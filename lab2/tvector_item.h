//TVECTOR_ITEM.H
#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#define et_tvectoritem Square

#include<iostream>
#include "square.h"

class TVectorItem
{
	public:
		TVectorItem(const et_tvectoritem& elem);
		TVectorItem(const TVectorItem& another);
		const et_tvectoritem getElement();
		~TVectorItem();
		friend std::ostream& operator<<(std::ostream& os, TVectorItem& obj);

	private:
		et_tvectoritem element;
};

#endif
