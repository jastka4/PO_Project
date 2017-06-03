#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(string name, unsigned short level, unsigned int health, unsigned int mana, string playerClass) :
	name(name), level(level), health(health), mana(mana), playerClass(playerClass) {}

Character::~Character() {

}

unsigned short Character::getLevel() {
	return level;
}

unsigned int Character::getMana() {
	return mana;
}

unsigned int Character::getHealth() {
	return health;
}

string Character::getName() {
	return name;
}

string Character::getPlayerClass() {
	return playerClass;
}

void Character::addLevel() {
    level++;
}

void Character::addMana(unsigned int amount) {
    mana += amount;
}

void Character::addHealth(unsigned int amount) {
    health += amount;
}

void Character::deleteMana(unsigned int amount) {
    health -= amount;
}

void Character::deleteHealth(unsigned int amount) {
    health -= amount;
}

string Character::drawCharacter() {

    ifstream File ("Character/Knight.txt");             //Open file

    std::string Lines = "";                             //Store all lines

    if (File){                                          //Check if everything is good
        while (File.good ()){
	    std::string TempLine;                           //Temp line
	    std::getline (File , TempLine);                 //Get temp line
	    TempLine += "\n";                               //Add newline character

	    Lines += TempLine;                              //Add newline
        }
	return Lines;
    } else {
        Lines = "ERROR File does not exist.";           //Return error
    }

    File.close ();                                      //Close file
    return Lines;                                       //Print it to the screen
}
