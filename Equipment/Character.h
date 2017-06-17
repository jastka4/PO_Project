#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>
#include <fstream>

class Character {
public:
	Character(std::string, unsigned short, unsigned int, unsigned int, std::string);
	~Character();
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
	std::string drawCharacter();
	void displayStats();
private:
	const std::string name;
	const std::string playerClass;
	unsigned short level;
	unsigned int health;
	unsigned int mana;

    friend class Item;
};

#endif //_CHARACTER_H
