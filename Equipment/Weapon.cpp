#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int weight, double price, unsigned int damage):
	Item(name, weight, price), damage(damage) {}

Weapon::~Weapon() {

}

void Weapon::use() {
    return;
}

void Weapon::draw() {
    return;
}

int* Weapon::showStats() {
    return nullptr;
}

std::string Weapon::myType() {
    return "";
}