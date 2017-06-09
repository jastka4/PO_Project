#ifndef _SPELL_H
#define _SPELL_H

#include "Item.h"

class Spell: public Item {
public: 

    Spell(std::string, unsigned int, double, unsigned int, double);
    ~Spell();
    void use();
    int* showStats();
    std::string myType();
private: 
    unsigned int cost;
    double cooldown;
};

#endif //_SPELL_H