#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(string name, unsigned short level, unsigned int health, unsigned int mana, string playerClass) :
	name(name), level(level), health(health), mana(mana), playerClass(playerClass) {}

Character::Character() {

}

unsigned short Character::getLevel() {
	return 0;
}

unsigned int Character::getMana() {
	return 0;
}

unsigned int Character::getHealth() {
	return 0;
}

string Character::getName() {
	return "";
}

string Character::getPlayerClass() {
	return "";
}

void Character::addLevel() {
}

void Character::addMana(unsigned int amount) {
}

void Character::addHealth(unsigned int amount) {
}

void Character::deleteMana(unsigned int amount) {
}

void Character::deleteHealth(unsigned int amount) {
}

void Character::drawCharacter() {
}