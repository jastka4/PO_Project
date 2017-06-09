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

Item* Backpack::showItem() const {
	return nullptr;
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
