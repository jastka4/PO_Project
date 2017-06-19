#ifndef _ARMOUR_H
#define _ARMOUR_H

#include "Item.h"


class Armour: public Item {
public: 
	Armour(std::string, unsigned int, double, std::string, unsigned int);
	Armour(){}		//default constructor required by boost library
	virtual ~Armour();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
	friend std::ostream& operator<<(std::ostream&,const Armour&); //example of operator overloading
private: 
	unsigned int defense;
	
	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
		ar & boost::serialization::base_object<Item>(*this);
    		ar & defense;	 //serialize the data members
	}
};

#endif //_ARMOUR_H
