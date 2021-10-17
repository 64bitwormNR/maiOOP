//TVECTOR_ITEM.H
#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#define et_tvectoritem Figure

#include<iostream>
#include "square.h"
#include <memory>

class TVectorItem
{
	public:
		TVectorItem(const std::shared_ptr<et_tvectoritem>& elem);
		const std::shared_ptr<et_tvectoritem> getElement();
		~TVectorItem();
		friend std::ostream& operator<<(std::ostream& os, TVectorItem& obj);

	private:
		std::shared_ptr<et_tvectoritem> element;
};

#endif
