#ifndef _BACKPACK_H
#define _BACKPACK_H

#include "Inventory.h"

class Backpack: public Inventory {
public:
    Backpack(size_t);
    ~Backpack();
    const std::vector<Item*>& showAllItems();
    void addItem(Item* object);
	void removeItem(Item* object);
	Item* showItem() const;
	double itemValue();
    size_t getCapacity();
    size_t getActualSize();
private:
    const size_t size;
    std::vector<Item*> inventory;
};

#endif //_BACKPACK_H
