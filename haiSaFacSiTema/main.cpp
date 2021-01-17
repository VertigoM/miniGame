#include <iostream>
#include <fcntl.h>
#include "Encounter.h"
#include "Menu.h";

int main() {
	Character char1("Mihai", new Human(), new Warrior());

	Menu::createCharacter();

	while (1) {
		Encounter::fight(&char1);
		char1.peekInventory();
	}

	return 0;
}