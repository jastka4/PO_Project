#ifndef _SPELL_H
#define _SPELL_H

#include "Item.h"

class Spell: public Item {
public: 
	Spell(std::string, double,  unsigned int, std::string, unsigned int, unsigned int);
	Spell(){} 		//default constructor required by boost library
	virtual ~Spell();
	void use();
	std::vector<std::string> showStats();
	std::string myType();
	friend std::ostream& operator<<(std::ostream&,const Spell&); //example of operator overloading
private: 
	unsigned int cost;
	unsigned int cooldown;
	
	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
		ar & boost::serialization::base_object<Item>(*this);
    		ar & cost;	 //serialize the data members
		ar & cooldown;
	}
};

#endif //_SPELL_H
