#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Item.h"
#include <vector>

class Inventory {
public: 
    //virtual const vector<Item*>& showAllItems() = 0;
    virtual void addItem(Item*) = 0;
    virtual void removeItem(Item*) = 0;
    virtual Item* showItem() const = 0;
    virtual double itemValue() = 0;
    virtual size_t getCapacity() = 0;
    virtual size_t getActualSize() = 0;
};

#endif //_INVENTORY_H