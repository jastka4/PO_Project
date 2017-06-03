#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include<iostream>

using namespace std;

int main() {
    Character player("Roland", 1, 500, 200, "Knight");
    cout << player.drawCharacter()  << endl;

	cin.get(); cin.ignore();
	return 0;
}
