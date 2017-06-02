#ifndef _SPELL_H
#define _SPELL_H

#include "Item.h"

class Spell: public Item {
public: 

    Spell(std::string name, unsigned int weight, double price, unsigned int cost, double cooldown);
    ~Spell();
    void use();
    void draw();
    int* showStats();
    std::string myType();
private: 
    unsigned int cost;
    double cooldown;
};

#endif //_SPELL_H