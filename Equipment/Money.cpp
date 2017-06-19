#include "Money.h"

using namespace std;

Money::Money(std::string name, double weight, string source, double amount):
	Item(name, weight, amount, source), amount(amount){}

Money::~Money()
{
}

void Money::use()
{
}

vector<string> Money::showStats(){
	vector<string> stats;
	stats.push_back(name);
	stats.push_back("WEIGHT: " + to_string(weight));
	stats.push_back("PRICE: " + to_string(price));
	stats.push_back("Amount: " + to_string(amount));
	return stats;
}

std::string Money::myType()
{
	return "money";
}

ostream& operator<<(ostream & ostr, const Money & obj) { //example of operator overloading
	ostr << static_cast<const Item&>(obj);
	ostr << " AMOUNT: " << obj.amount;
	return ostr;
}
