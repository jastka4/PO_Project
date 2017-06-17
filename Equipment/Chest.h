#ifndef _CHEST_H
#define _CHEST_H

#include "Inventory.h"

class Chest: public Inventory {
public: 
	Chest(size_t);
	~Chest();
    const std::vector<Item*>& showAllItems();
    void addItem(Item* object) = 0;
	void removeItem(Item* object) = 0;
    Item* showItem(int) const = 0;
    double itemValue() = 0;
    size_t getCapacity() = 0;
    size_t getActualSize() = 0;
private: 
    const size_t size;
    std::vector<Item*> inventory;
};

#endif //_CHEST_H
