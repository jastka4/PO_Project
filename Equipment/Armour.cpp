#include "Armour.h"
#include <iostream>

using namespace std;

Armour::Armour(string name, unsigned int weight, double price, unsigned int defense):
    Item(name, weight, price), defense(defense){}

Armour::~Armour() {

}

void Armour::use() {
}

void Armour::draw() {
}

int* Armour::showStats() {
}

std::string Armour::myType() {
    return "";
}
