#ifndef _CHEST_H
#define _CHEST_H

#include "Inventory.h"

class Chest: public Inventory {
public: 
	Chest(size_t);
	~Chest();
	const std::vector<Item*>& showAllItems();
	void addItem(Item* object);
	void removeItem(int);
	Item* showItem(int) const;
	double itemValue();
	size_t getCapacity();
	size_t getActualSize();
	std::vector< std::vector<std::string> > showInventory();
private: 
	const size_t size;
	std::vector<Item*> inventory;
};

#endif //_CHEST_H
