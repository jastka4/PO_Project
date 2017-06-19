#ifndef _WEAPON_H
#define _WEAPON_H

#include "Item.h"


class Weapon: public Item {
public: 
	Weapon(std::string, double, unsigned int, std::string, unsigned int);
	virtual ~Weapon();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
private: 
	unsigned int damage;
};

#endif //_WEAPON_H
