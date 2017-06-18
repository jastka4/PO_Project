#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Item.h"
#include <vector>

class Inventory {
public: 
	virtual const std::vector<Item*>& showAllItems() = 0;
	virtual void addItem(Item*) = 0;
	virtual void removeItem(int) = 0;
	virtual Item* showItem(int) const = 0;
	virtual double itemValue() = 0;
	virtual size_t getCapacity() = 0;
	virtual size_t getActualSize() = 0;
	virtual std::vector< std::vector<std::string> > showInventory() = 0;
};

#endif //_INVENTORY_H
