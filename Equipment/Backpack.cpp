#include "Backpack.h"

using namespace std;

Backpack::Backpack(size_t size):
	size(size){
}

Backpack::~Backpack() {
}

const vector<Item*>& Backpack::showAllItems() {
	return ;
}

void Backpack::addItem(Item* object) {
}

void Backpack::removeItem(Item* object) {
}

Item* Backpack::showItem() {
	return nullptr;
}

double Backpack::itemValue() {
	return 0;
}

unsigned short Backpack::getCapacity() {
	return 0;
}

unsigned short Backpack::getActualSize() {
	return 0;
}