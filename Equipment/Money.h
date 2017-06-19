#ifndef _MONEY_H
#define _MONEY_H

#include "Item.h"

class Money: public Item
{
public:
	Money(std::string, double, std::string, double);
	Money(){}		//default constructor required by boost library
	virtual ~Money();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
private:
	double amount;
	
	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
		ar & boost::serialization::base_object<Item>(*this);
    		ar & amount;	 //serialize the data members
	}
};

#endif //_MONEY_H
