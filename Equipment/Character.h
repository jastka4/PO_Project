#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>

class Character {
public: 
	Character(std::string, unsigned short, unsigned int, unsigned int, std::string);
	Character();
	unsigned short getLevel();
	unsigned int getMana();
	unsigned int getHealth();
	std::string getName();
	std::string getPlayerClass();
    void addLevel();
    void addMana(unsigned int amount);
    void addHealth(unsigned int amount);
    void deleteMana(unsigned int amount);
    void deleteHealth(unsigned int amount);
    void drawCharacter();
private: 
    const std::string name;
    const std::string playerClass;
    unsigned short level;
    unsigned int health;
    unsigned int mana;
};

#endif //_CHARACTER_H