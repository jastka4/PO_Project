#ifndef _BACKPACK_H
#define _BACKPACK_H

#include "Inventory.h"

class Backpack: public Inventory {
public: 
    Backpack(size_t);
    ~Backpack();
    const std::vector<Item*>& showAllItems();
    void addItem(Item* object) = 0;
	void removeItem(Item* object) = 0;
	Item* showItem() = 0;
	double itemValue() = 0;
    unsigned short getCapacity() = 0;
    unsigned short getActualSize() = 0;
private: 
    const size_t size;
    std::vector<Item*> inventory;
};

#endif //_BACKPACK_H