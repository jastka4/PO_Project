#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include<iostream>
#include <curses.h>

using namespace std;

int xMax = 0;
int yMax = 0;
int main() {
    	Character player("Roland", 1, 500, 200, "Knight");
	const char* playerClass = player.getPlayerClass().c_str();
	const char* name = player.getName().c_str();
	
	//ncurses start
	initscr();
	noecho();
	cbreak();
	
	//get screen size
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * playerwin = newwin(25, xMax-12, 0, 5);
	
	//create window for player view
	refresh();
	mvwprintw(playerwin, 0, 0, player.drawCharacter().c_str());
	wrefresh(playerwin);
	//player.displayStats();

	//create window for input
	WINDOW * menuwin = newwin(3, xMax-12, 26, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);
	
	string choices[] = {"Player stats", "Inventory", "Chest", "Exit"};
	int choice;
	int highlight = 0;
	
	for(int i = 0; i < 4; i++) {
		mvwprintw(menuwin, 1, 1+i*20, choices[i].c_str());
	}

	wrefresh(menuwin);
	getch();
	endwin(); //ncurses end
	
	return 0;
}
