#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <fstream>

class Item
{
public:
	Item(std::string, unsigned int, double, std::string);
	~Item();
	virtual void use() = 0;
	std::string draw(std::string);
	virtual int* showStats() = 0;
	virtual std::string myType() = 0;
protected:
	std::string name;
	unsigned int weight;
	double price;
	std::string source;
};

#endif //_ITEM_H