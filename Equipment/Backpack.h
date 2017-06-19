#ifndef _BACKPACK_H
#define _BACKPACK_H

#include "Inventory.h"

class Backpack: public Inventory {
public:
	Backpack(size_t);
	Backpack(): size(0){}		//default constructor required by boost library
	~Backpack();
	const std::vector<Item*>& showAllItems();
	void addItem(Item* object);
	void removeItem(int);
	Item* showItem(int) const;
	double itemValue();
	size_t getCapacity();
	size_t getActualSize();
	std::vector< std::vector<std::string> > showInventory();

	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
		ar & size;	  	//serialize vector of pointers to items
        	for(size_t i = 0; i < inventory.size(); ++i){
		            ar & *inventory[i];}
	}
private:
    const size_t size;
    std::vector<Item*> inventory;
};

#endif //_BACKPACK_H
