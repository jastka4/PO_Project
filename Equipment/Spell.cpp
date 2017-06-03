#include "Spell.h"

Spell::Spell(std::string name, unsigned int weight, double price, unsigned int cost, double cooldown):
	Item(name, weight, price), cooldown(cooldown) {

}

Spell::~Spell() {

}

void Spell::use() {
    return;
}

void Spell::draw() {
    return;
}

int* Spell::showStats() {

}

std::string Spell::myType() {
    return "spell";
}
