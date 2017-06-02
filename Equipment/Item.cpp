#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(std::string name, unsigned int weight, double price): name(name), weight(weight), price(price){}

Item::~Item() //TODO: sprawdzic czy tak moze byc
{
	name = "";
	weight = 0;
	price = 0;
}