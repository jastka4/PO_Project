#include "Character.h"
#include <iostream>
#include <ncurses.h>

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
    ifstream file ("Character/knight.txt");             //Open file

    string lines = "";									//Store all lines

    if (file){                                          //Check if everything is good
        while (file.good ()){
	    string TempLine;								//Temp line
	    getline (file , TempLine);						//Get temp line
	    TempLine += "\n";                               //Add newline character

	    lines += TempLine;                              //Add newline
        }
    } else {
        lines = "ERROR File does not exist.";           //Return error
    }

    file.close ();                                      //Close file
	return lines;                                       //Print it to the screen
}

void Character::displayStats() {
	int row = 4,
	    col = 35;
	mvprintw(row++, col,("NAME: " + name).c_str());
	mvprintw(row++, col,("CLASS: " + playerClass).c_str());	
	mvprintw(row++, col,("LEVEL: " + to_string(level)).c_str());
	mvprintw(row++, col,("HEALTH: " + to_string(health)).c_str());
	mvprintw(row++, col,("MANA: " + to_string(mana)).c_str());
}
