#include "Spell.h"

using namespace std;

Spell::Spell(std::string name, unsigned int weight, double price, unsigned int cost, double cooldown):
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
