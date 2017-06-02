#ifndef _MONEY_H
#define _MONEY_H

#include "Item.h"

class Money: private Item
{
public:
	Money::Money(std::string, unsigned int, double, double);
	~Money();
	void use();
	void draw();
	int* showStats();
	std::string myType();
private:
	double amount;
};

#endif //_MONEY_H