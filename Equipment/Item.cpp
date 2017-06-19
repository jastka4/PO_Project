#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(std::string name, unsigned int weight, double price, string source):
	name(name), weight(weight), price(price), source(source){}

Item::~Item() //TODO: check if this is right
{
	name = "";
	weight = 0;
	price = 0;
	source = "";
}

vector<string> Item::draw()
{
	ifstream file(source);									//Open file

	vector<string> lines;										//Store all lines

	if (file) {												//Check if everything is good
		while (file.good()) {
			string tempLine;								//Temp line
			getline(file, tempLine);						//Get temp line
			//tempLine += "\n";                               //Add newline character

			lines.push_back(tempLine);                              //Add newline
		}
		return lines;
	}
	else {
		//lines = "ERROR File does not exist.";				//Return error
	}

	file.close();											//Close file
	return lines;											//Print it to the screen
}

ostream& operator<<(ostream & ostr, const Item & obj) { //example of operator overloading
	ostr << " NAME: " << obj.name
	     << " WIEGHT: " << obj.weight
	     << " PRICE: " << obj.price
	     << " SOURCE: " << obj.source;
	return ostr;
}
