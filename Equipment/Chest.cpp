#include "Chest.h"

using namespace std;

Chest::Chest(size_t size):
	size(size){
}

Chest::~Chest() {
}

const vector<Item*>& Chest::showAllItems() {}

void Chest::addItem(Item* object) {
    return;
}

void Chest::removeItem(Item* object) {
    return;
}

Item* Chest::showItem() {
    return nullptr;
}

double Chest::itemValue() {
    return 0;
}

unsigned short Chest::getCapacity() {
    return 0;
}

unsigned short Chest::getActualSize() {
    return 0;
}