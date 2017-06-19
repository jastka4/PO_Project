#include "Spell.h"

using namespace std;

Spell::Spell(std::string name, double weight, unsigned int price, string source, unsigned int cost, unsigned int cooldown):
	Item(name, weight, price, source), cost(cost), cooldown(cooldown) {

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
	stats.push_back("MANA COST: " + to_string(cost));
	stats.push_back("COOLDOWN: " + to_string(cooldown));
	return stats;
}

std::string Spell::myType() {
    return "spell";
}

ostream& operator<<(ostream & ostr, const Spell & obj) { //example of operator overloading
	ostr << static_cast<const Item&>(obj);
	ostr << " MANA COST: " << obj.cost
	     << " COOLDOWN: " << obj.cooldown;
	return ostr;
}
