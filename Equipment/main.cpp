#include "Character.h"
#include "Backpack.h"
#include "Chest.h"
#include "Armour.h"
#include "Money.h"
#include "Spell.h"
#include "Weapon.h"
#include <iostream>
#include <curses.h>

using namespace std;

int xMax = 0;
int yMax = 0;
bool programOn = true;
unsigned char choice = 'p';

int main() {
    	Character player("Roland", 1, 500, 200, "Knight");
	Backpack backpack(9);
	//Armour* armour = new Armour("Plate armour", 100, 350, 50);
	//Armour* shield = new Armour("Shield", 10, 130, 10);
	//Money* money = new Money("Novigrad coins", 1, 500);
	//Spell* fire_spell = new Spell("Fire breath", 2.4, 90, 45, 30);
	Weapon* sword = new Weapon("Sword of justice", 15, 300, "Character/sword.txt", 35);
	Weapon* axe = new Weapon("Steel axe", 23, 245, "Character/axe.txt", 59);
	Weapon* bow = new Weapon("Elvish longbow", 5.5, 225, "Character/bow.txt", 28);

	backpack.addItem(sword);
	cout << backpack.getActualSize();
	backpack.addItem(axe);
	backpack.addItem(bow);

	//ncurses start
	initscr();
	noecho();
	cbreak();
	
	//get screen size
	getmaxyx(stdscr, yMax, xMax);
	
	//create window for input
	WINDOW * menuwin = newwin(3, xMax-12, 26, 5);	//create window for the menu
	WINDOW * playerwin = newwin(25, xMax-12, 0, 5); // create window for the player view
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	do {	
		wclear(playerwin); //clear player window

		//show menu
		string choices[] = {"Player stats", "Inventory", "Chest", "Exit"};	
		for(int i = 0; i < 4; i++) {
			mvwprintw(menuwin, 1, 1+i*20, choices[i].c_str());
		}
		wrefresh(menuwin);
		
		switch(choice)
		{
			case 'p':
				{
				//show player character
				mvwprintw(playerwin, 0, 0, player.drawCharacter().c_str());
	
				//show player stats
				vector<string> playerStats = player.displayStats();
				for(int i = 0; i < 5; i++){
					mvwprintw(playerwin, i+4, 35, playerStats[i].c_str());
				} 
				wrefresh(playerwin);
				break;
				}
			case 'i':
				{
				int itemChoice,
				    highlight;
				vector< vector<string> > backpackInv = backpack.showInventory();
				for(int i = 0; i < 3; i++) {
					wprintw(playerwin, backpackInv[i][0].c_str());
				}
				wrefresh(playerwin);

				break;
				}
			case 'c':
				break;
			case 'e':
				programOn = false;
				break;
			default:
				break;
		}
		choice = getch();
	}while(programOn == true);
	
	getch();
	endwin(); //ncurses end

	return 0;
}
