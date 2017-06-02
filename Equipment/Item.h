#ifndef _ITEM_H
#define _ITEM_H

#include <string>

class Item
{
public:
	Item(std::string, unsigned int, double);
	~Item();
	virtual void use() = 0;
	virtual void draw() = 0;
	virtual int* showStats() = 0;
	virtual std::string myType() = 0;
protected:
	std::string name;
	unsigned int weight;
	double price;
};

#endif //_ITEM_H