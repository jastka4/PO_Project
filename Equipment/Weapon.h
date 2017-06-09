#ifndef _WEAPON_H
#define _WEAPON_H

#include "Item.h"


class Weapon: public Item {
public: 
    Weapon(std::string, unsigned int, double, unsigned int);
    ~Weapon();
    void use();
    int* showStats();
    std::string myType();
private: 
    unsigned int damage;
};

#endif //_WEAPON_H