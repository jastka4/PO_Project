#include "Money.h"

using namespace std;

Money::Money(std::string name, unsigned int weight, double price, double amount):
	Item(name, weight, price, source), amount(amount){}

Money::~Money()
{
}

void Money::use()
{
}

int * Money::showStats(){
	return nullptr;
}

std::string Money::myType()
{
	return "money";
}
