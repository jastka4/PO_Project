#include "Spell.h"

using namespace std;

Spell::Spell(std::string name, double weight, unsigned int price, unsigned int cost, unsigned int cooldown):
	Item(name, weight, price, source), cooldown(cooldown) {

}

Spell::~Spell() {

}

void Spell::use() {
    return;
}

int* Spell::showStats() {
	return nullptr;
}

std::string Spell::myType() {
    return "spell";
}
