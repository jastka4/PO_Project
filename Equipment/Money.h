#ifndef _MONEY_H
#define _MONEY_H

#include "Item.h"

class Money: private Item
{
public:
	Money(std::string, double, double);
	~Money();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
private:
	double amount;
};

#endif //_MONEY_H
