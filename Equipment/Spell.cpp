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

vector<string> Spell::showStats() {
	vector<string> stats;
	stats.push_back(name);
	stats.push_back("WEIGHT: " + to_string(weight));
	stats.push_back("PRICE: " + to_string(price));
	stats.push_back("COOLDOWN: " + to_string(cooldown));
	return stats;
}

std::string Spell::myType() {
    return "spell";
}
