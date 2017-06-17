#include "Chest.h"

using namespace std;

Chest::Chest(size_t size):
	size(size){
}

Chest::~Chest() {
}

const vector<Item*>& Chest::showAllItems() {
	return inventory;
}

void Chest::addItem(Item* object) {
    return;
}

void Chest::removeItem(Item* object) {
}

Item* Chest::showItem(int place) const {
	return inventory[place];
}

double Chest::itemValue() {
    return 0;
}

size_t Chest::getCapacity() {
    return 0;
}

size_t Chest::getActualSize() {
    return 0;
}
