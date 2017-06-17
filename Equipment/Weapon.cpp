#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(string name, double weight, unsigned int price, string source, unsigned int damage):
	Item(name, weight, price, source), damage(damage) {}

Weapon::~Weapon() {

}

void Weapon::use() {
    return;
}

int* Weapon::showStats() {
	return nullptr;
}

string Weapon::myType() {
    return "weapon";
}
