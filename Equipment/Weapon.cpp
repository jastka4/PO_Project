#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(std::string name, unsigned int weight, double price, unsigned int damage):
	Item(name, weight, price, source), damage(damage) {}

Weapon::~Weapon() {

}

void Weapon::use() {
    return;
}

int* Weapon::showStats() {
	return nullptr;
}

std::string Weapon::myType() {
    return "weapon";
}
