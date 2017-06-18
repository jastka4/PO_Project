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
	Chest chest(16);
	//Armour* armour = new Armour("Plate armour", 100, 350, 50);		TODO: copy from Weapon to other items; fix item description after move; do serialization
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

	initscr();		//ncurses start
	noecho();		//pressed characters do not print on the screen
	cbreak();		//pressed keys are immediately returned by getch() instead of waiting until new line is read
	
	//get screen size
	getmaxyx(stdscr, yMax, xMax);
	
	//create window for input
	WINDOW * menuwin = newwin(3, xMax-12, 30, 5);		//create window for the menu
	WINDOW * playerwin = newwin(25, 50, 0, 5); 		//create window for the player view
	WINDOW * inventorywin = newwin(10, 25, 4, 55);		//create window for the inventory view
	WINDOW * descriptionwin = newwin(3, xMax-12, 26, 5); 	//create window for description
	//box(inventorywin,0,0);
	//PANEL * inventorypanel = *new_panel(inventorywin);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	wrefresh(inventorywin);

	do {	
		wclear(playerwin); 		//clear player window
		wclear(descriptionwin);		//clear description window
		wclear(inventorywin);		//clear inventory window
		fflush(stdin);			//clear buffer after using getch()

		//show menu
		string choices[] = {"Player stats", "Inventory", "Chest", "Exit"};	
		for(int i = 0; i < 4; i++) {
			wattron(menuwin, A_REVERSE);
			mvwaddch(menuwin,1, 1+i*20, choices[i].at(0));
			wattroff(menuwin, A_REVERSE);
			mvwprintw(menuwin, 1, 2+i*20, choices[i].substr(1).c_str());
		}
		wrefresh(menuwin);
		wrefresh(inventorywin);
		wrefresh(descriptionwin);
		switch(choice)
		{
			case 'p':
				{
				//show player character
				mvwprintw(playerwin, 0, 0, player.drawCharacter().c_str());
	
				//show player stats
				vector<string> playerStats = player.displayStats();
				for(unsigned int i = 0; i < 5; i++){
					mvwprintw(playerwin, i+4, 35, playerStats[i].c_str());
				} 
				wrefresh(playerwin);
				wmove(menuwin, 1, 65);
				break;
				}
			case 'i':
				{
				keypad(playerwin, true); //makes it so user can use arrow keys
				int itemChoice,
				    highlight = 0;
				vector<Item*> backpackInvStats = backpack.showAllItems(); 
				
				string description[] = {"Press ENTER to view stats", "Press M to move item to the chest", "Press B to get to the menu"};
				for(int i = 0; i < 3; i++) {
					mvwprintw(descriptionwin, 0, i*45, description[i].c_str());
					wrefresh(descriptionwin);
				}

				do {
					vector< vector<string> > backpackInv = backpack.showInventory();
					for(unsigned int i = 0, d = 0, p = 4; i < backpackInv.size(); i++, d += 12) {
						if(i > 2 && i < 5) p = 4+6;
						else if (i > 5) p = 4+12;
						for(unsigned int j = 0; j < backpackInv[i].size(); j++) {
							if(i == 3 || i == 6) d = 0;
							if(i == highlight)
								wattron(playerwin, A_REVERSE);
							mvwprintw(playerwin, j+p, d, backpackInv[i][j].c_str());
							wattroff(playerwin, A_REVERSE);
						}
					}
					wrefresh(playerwin);
							//function for moving in the inventory
					itemChoice = wgetch(playerwin);
				
					switch(itemChoice) {
						case KEY_UP:
							highlight -= 3;
							if(highlight < 0)
								highlight += 3;
							break;
						case KEY_DOWN:
							highlight += 3;
							if(highlight > 8)
								highlight -= 3;
							break;
						case KEY_LEFT:
							highlight--;
							if(highlight == -1)
								highlight = 0;
							break;
						case KEY_RIGHT:
							highlight++;
							if(highlight == 9)
								highlight = 8;
							break;
						case 10:
							wclear(inventorywin);		//clear inventory window			
							if(highlight < backpackInvStats.size()){
								vector<string> itemStats = backpackInvStats[highlight]->showStats();
								for(unsigned int i = 0; i < itemStats.size(); i++){
									mvwprintw(inventorywin, i, 0, itemStats[i].c_str());
								}
							} else {
								mvwprintw(inventorywin, 0, 0, "Slot is empty!");
							}
							wrefresh(inventorywin);
							wmove(menuwin, 1, 65);
							break;
						case 'm':
							if(highlight < backpack.getActualSize()) {
								chest.addItem(backpack.showItem(highlight));
								backpack.removeItem(highlight);
								mvwprintw(inventorywin, 0, 0, "Move successful");
							} else {
								mvwprintw(inventorywin, 0, 0, "Can't move an empty slot!");
							}
							wrefresh(inventorywin);
							break;
						default:
							break;
						}
					}while(itemChoice != 'b');
				break;
				}
			case 'c':
				{
				keypad(playerwin, true); //makes it so user can use arrow keys
				int itemChoice,
				    highlight = 0;
				vector<Item*> chestInvStats = chest.showAllItems(); 
				
				string description[] = {"Press ENTER to view stats", "Press M to move item to the backpack", "Press B to get back to the menu"};
				for(int i = 0; i < 3; i++) {
					mvwprintw(descriptionwin, 0, i*45, description[i].c_str());
					wrefresh(descriptionwin);
				}

				do {
					vector< vector<string> > chestInv = chest.showInventory();
					for(unsigned int i = 0, d = 0, p = 2; i < chestInv.size(); i++, d += 12) {
						if(i > 3 && i < 7) p = 2+6;
						else if (i > 7 && i < 11) p = 2+12;
						else if (i > 11) p = 2+18;
						for(unsigned int j = 0; j < chestInv[i].size(); j++) {
							if(i == 4 || i == 8 || i == 12) d = 0;
							if(i == highlight)
								wattron(playerwin, A_REVERSE);
							mvwprintw(playerwin, j+p, d, chestInv[i][j].c_str());
							wattroff(playerwin, A_REVERSE);
						}
					}
					wrefresh(playerwin);
							//function for moving in the inventory
					itemChoice = wgetch(playerwin);
					choice = itemChoice;
					
					switch(itemChoice) {
						case KEY_UP:
							highlight -= 4;
							if(highlight < 0)
								highlight += 4;
							break;
						case KEY_DOWN:
							highlight += 4;
							if(highlight > 15)
								highlight -= 4;
							break;
						case KEY_LEFT:
							highlight--;
							if(highlight == -1)
								highlight = 0;
							break;
						case KEY_RIGHT:
							highlight++;
							if(highlight == 16)
								highlight = 15;
							break;
						case 10:
							wclear(inventorywin);		//clear inventory window				
							if(highlight < chestInvStats.size()){
								vector<string> itemStats = chestInvStats[highlight]->showStats();
								for(unsigned int i = 0; i < itemStats.size(); i++){
									mvwprintw(inventorywin, i, 0, itemStats[i].c_str());
								}
							} else {
								mvwprintw(inventorywin, 0, 0, "Slot is empty!");
							}
							wrefresh(inventorywin);
							break;
						case 'm':
							if(highlight < chest.getActualSize()) {
								backpack.addItem(chest.showItem(highlight));
								chest.removeItem(highlight);
								mvwprintw(inventorywin, 1, 0, "Move successful");
							} else {
								mvwprintw(inventorywin, 1, 0, "Can't move an empty slot!");
							}
							wrefresh(inventorywin);
							break;
						default:
							break;
						}
					} while(itemChoice != 'b');
				break;
				}
			case 'e':
				programOn = false;
				break;
			default:
				break;
		}
		choice = wgetch(menuwin);
	}while(programOn == true);
	
	//makes sure program waits before exiting
	//getch();
	endwin(); 
	/* NCURSES END */

	return 0;
}
