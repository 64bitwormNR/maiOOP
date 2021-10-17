//TVECTOR_ITEM.CPP
#include "tvector_item.h"
#include <iostream>

TVectorItem::TVectorItem(const std::shared_ptr<et_tvectoritem>& elem)
{
	this->element = elem;
}

const std::shared_ptr<et_tvectoritem> TVectorItem::getElement()
{
	return this->element;
}

std::ostream& operator<<(std::ostream& os, TVectorItem& obj)
{
	os << *(obj.element);
	return os;
}

TVectorItem::~TVectorItem()
{

}
