#include "Money.h"

Money::Money(std::string name, unsigned int weight, double price, double amount):
	Item(name, weight, price), amount(amount){}

Money::~Money()
{
}

void Money::use()
{
}

void Money::draw()
{
}

int * Money::showStats()
{
	return nullptr;
}

std::string Money::myType()
{
	return std::string();
}