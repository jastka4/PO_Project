#ifndef _SPELL_H
#define _SPELL_H

#include "Item.h"

class Spell: public Item {
public: 
	Spell(std::string, double,  unsigned int, std::string, unsigned int, unsigned int);
	virtual ~Spell();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
private: 
	unsigned int cost;
	unsigned int cooldown;
};

#endif //_SPELL_H
