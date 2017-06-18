#include "Chest.h"

using namespace std;

Chest::Chest(size_t size):			//constructor reserving in memory a vector of given size
	size(size){
    inventory.reserve(size);
}

Chest::~Chest() {					//destructor
    inventory.clear();
}

const vector<Item*>& Chest::showAllItems() {		//returns vector of items
    return inventory;
}

void Chest::addItem(Item* object) { 			//adds item to the end of the vector
    	if(inventory.size() < size)
		inventory.push_back(object);
}

void Chest::removeItem(int position) {		//removes element from the vector at given position 
	if(position < inventory.size())
		inventory.erase(inventory.begin()+position);
}

Item* Chest::showItem(int position) const {		//shows item at given position
	if(position < inventory.size())
		return inventory[position];
	else
		return nullptr;
}

double Chest::itemValue() {				//returns how many identical items are in the inventory
	return 1;
}

size_t Chest::getCapacity() {			//returns maximum size of inventory
	return size;
}

size_t Chest::getActualSize() {			//returns actual size of vector
	return inventory.size();
}

vector< vector<string> > Chest::showInventory(){	//returns vector of vectors (function for drawign inventory 
	string interval ="-----------";
	vector<string> empty,
	       item;
	vector< vector<string> > items;
	for(int i = 0; i <5; i++){
		empty.push_back("|          |");
	}

	for(unsigned i = 0; i < size; i++){
		if(i < inventory.size()) {
			//item = interval;
			item = inventory[i]->draw();
			//item.push_back(interval);
			items.push_back(item);
		} else {
			items.push_back(empty);
		}
	}
	//item.push_back(interval);

	return items;
}
