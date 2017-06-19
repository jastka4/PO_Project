#include "Armour.h"
#include <iostream>

using namespace std;

Armour::Armour(string name, unsigned int weight, double price, string source, unsigned int defense):
    Item(name, weight, price, source), defense(defense){}

Armour::~Armour() {

}

void Armour::use() {
}


vector<string> Armour::showStats() {
	vector<string> stats;
	stats.push_back(name);
	stats.push_back("WEIGHT: " + to_string(weight));
	stats.push_back("PRICE: " + to_string(price));
	stats.push_back("DEFENSE: " + to_string(defense));
	return stats;
}

std::string Armour::myType() {
    return "armour";
}

ostream& operator<<(ostream & ostr, const Armour & obj) { //example of operator overloading
	ostr << static_cast<const Item&>(obj);
	ostr << " DEFENSE: " << obj.defense;
	return ostr;
}
