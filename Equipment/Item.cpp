#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(std::string name, unsigned int weight, double price, string source):
	name(name), weight(weight), price(price), source(source){}

Item::~Item() //TODO: sprawdzic czy tak moze byc
{
	name = "";
	weight = 0;
	price = 0;
	source = "";
}

string Item::draw(string source)
{
	ifstream File(source);									//Open file

	string Lines = "";										//Store all lines

	if (File) {												//Check if everything is good
		while (File.good()) {
			string TempLine;								//Temp line
			getline(File, TempLine);						//Get temp line
			TempLine += "\n";                               //Add newline character

			Lines += TempLine;                              //Add newline
		}
		return Lines;
	}
	else {
		Lines = "ERROR File does not exist.";				//Return error
	}

	File.close();											//Close file
	return Lines;											//Print it to the screen
}
