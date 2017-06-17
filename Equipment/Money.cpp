#include "Money.h"

using namespace std;

Money::Money(std::string name, double weight, double amount):
	Item(name, weight, amount, source), amount(amount){}

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
