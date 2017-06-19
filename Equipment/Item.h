#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <fstream>
#include <vector>

//#include <boost/serialization/access.hpp>
//#include <boost/serialization/export.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/base_object.hpp>

class Item
{
public:
	Item(std::string, unsigned int, double, std::string);
	Item(){}	//default constructor required by boost library
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
  	
	//allow serialization to access non-public data members.
  	friend class boost::serialization::access;

  	template<typename Archive>
  	void serialize(Archive& ar, const unsigned version) {
    		ar & name;	 //serialize the data members
		ar & weight; 
  		ar & price;
		ar & source;
	}
};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Item)
#endif //_ITEM_H
