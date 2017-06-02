#ifndef _WEAPON_H
#define _WEAPON_H

#include "Item.h"


class Weapon: public Item {
public: 
    Weapon(std::string name, unsigned int weight, double price, unsigned int damage);
    ~Weapon();
    void use();
    void draw();
    int* showStats();
    std::string myType();
private: 
    unsigned int damage;
};

#endif //_WEAPON_H