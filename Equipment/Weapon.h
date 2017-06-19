#ifndef _WEAPON_H
#define _WEAPON_H

#include "Item.h"


class Weapon: public Item {
public: 
	Weapon(std::string, double, unsigned int, std::string, unsigned int);
	Weapon(){}	 //default constructor required by boost library
	virtual ~Weapon();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
	friend std::ostream& operator<<(std::ostream&,const Weapon&); //example of operator overloading
private: 
	unsigned int damage;
	
	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
		ar & boost::serialization::base_object<Item>(*this);
    		ar & damage;	 //serialize the data members
	}
};

#endif //_WEAPON_H
