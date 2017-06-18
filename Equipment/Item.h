#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <fstream>
#include <vector>

class Item
{
public:
	Item(std::string, unsigned int, double, std::string);
	~Item();
	virtual void use() = 0;
	std::vector<std::string> draw();
	virtual std::vector<std::string> showStats() = 0;
	virtual std::string myType() = 0;
protected:
	std::string name;
	double weight;
	unsigned int price;
	std::string source;
};

#endif //_ITEM_H
