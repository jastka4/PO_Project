#include "Armour.h"
#include <iostream>

using namespace std;

Armour::Armour(string name, unsigned int weight, double price, unsigned int defense):
    Item(name, weight, price, source), defense(defense){}

Armour::~Armour() {

}

void Armour::use() {
}


int* Armour::showStats() {
    return nullptr;	
}

std::string Armour::myType() {
    return "";
}
