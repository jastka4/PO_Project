#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include<iostream>
#include <curses.h>

using namespace std;

int col = 0;
int row = 0;
char tekst[] = "dsadasdasds";

int main() {
    Character player("Roland", 1, 500, 200, "Knight");
	cout << player.drawCharacter();

	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row / 2, (col / 2) - (sizeof(tekst) / 2), tekst);
	getch();
	endwin();
	return 0;
}