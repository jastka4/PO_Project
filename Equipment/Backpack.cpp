#include "Backpack.h"

using namespace std;

Backpack::Backpack(size_t size):
	size(size){
    inventory.reserve(size);
}

Backpack::~Backpack() {
    size = 0;
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

Item* Backpack::showItem() {
}

double Backpack::itemValue() {
	return 0;
}

unsigned short Backpack::getCapacity() {
	return size;
}

unsigned short Backpack::getActualSize() {
	return inventory.size();
}
