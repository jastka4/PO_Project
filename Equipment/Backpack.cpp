#include "Backpack.h"

using namespace std;

Backpack::Backpack(size_t size):
	size(size){
    inventory.reserve(size);
}

Backpack::~Backpack() {
    inventory.clear();
}

const vector<Item*>& Backpack::showAllItems() {
    return inventory;
}

void Backpack::addItem(Item* object) { 
    	inventory.push_back(object);
	
}

void Backpack::removeItem(Item* object) {
	
}

Item* Backpack::showItem(int place) const {
	return inventory[place];
}

double Backpack::itemValue() {
	return 0;
}

size_t Backpack::getCapacity() {
	return size;
}

size_t Backpack::getActualSize() {
	return inventory.size();
}

vector< vector<string> > Backpack::showInventory(){
	string interval ="-----------";
	vector<string> empty,
	       item;
	vector< vector<string> > items;
	for(int i = 0; i <5; i++){
		empty.push_back("|          |");
	}

	for(int i = 0; i < 9; i++){
		if(i < inventory.size()) {
			//item = interval;
			item = inventory[i]->draw();
			item.push_back(interval);
			items.push_back(item);
		} else {
			items.push_back(empty);
		}
	}
	//item.push_back(interval);

	return items;
}
