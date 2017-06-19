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

vector<string> Weapon::showStats() {
	vector<string> stats;
	stats.push_back(name);
	stats.push_back("WEIGHT: " + to_string(weight));
	stats.push_back("PRICE: " + to_string(price));
	stats.push_back("DAMAGE: " + to_string(damage));
	return stats;
}

string Weapon::myType() {
    return "weapon";
}

ostream& operator<<(ostream & ostr, const Weapon & obj) { //example of operator overloading
	ostr << static_cast<const Item&>(obj);
	ostr << " DAMAGE: " << obj.damage;
	return ostr;
}
