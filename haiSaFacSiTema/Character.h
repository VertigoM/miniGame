#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include "CharacterRace.h"
#include "CharacterClass.h"
#include "Item.h"
class Character
{
	int healthPoints;
	int attackPoints;
	int characterLevel;
	std::string characterName;
	CharacterRace* characterRace;
	CharacterClass* characterClass;

	std::vector<Item> characterInventory;
	int characterMoney;
public:
	Character(std::string, CharacterRace*, CharacterClass*);
	friend std::ostream& operator<<(std::ostream&, const Character&);

	Character(const Character&);
	Character& operator=(const Character&);

	std::string getCharacterName() const;
	void peekInventory() const;
	int getInventorySize() const;
	void addItem(const Item&);
	void sellItem(int);
	void sellAll();
	~Character();
};

