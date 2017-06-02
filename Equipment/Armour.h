#ifndef _ARMOUR_H
#define _ARMOUR_H

#include "Item.h"


class Armour: public Item {
public: 
    Armour(std::string, unsigned int, double, unsigned int);
    ~Armour();
    void use();
    void draw();
    int* showStats();
    std::string myType();
private: 
    unsigned int defense;
};

#endif //_ARMOUR_H