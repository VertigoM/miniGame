#include "Character.h"

Character::Character(std::string n, CharacterRace* r, CharacterClass* c) :
	characterName(n), characterRace(r), characterClass(c),  characterLevel(1), characterMoney(0) {
	try {
		healthPoints = r->healthPoints();
		attackPoints = r->atackPoints();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}

Character::Character(const Character&c):
	characterName(c.characterName),
	characterRace(c.characterRace->getNewInstance()),
	characterClass(c.characterClass->getNewInstance()),
	characterLevel(c.characterLevel),
	healthPoints(c.healthPoints),
	attackPoints(c.attackPoints),
	characterMoney(c.characterMoney){
	copy(c.characterInventory.begin(), c.characterInventory.end(), back_inserter(characterInventory));
	}

Character& Character::operator=(const Character& other)
{
	if (this == &other) {
		return (*this);
	}
	if (characterClass) {
		delete characterClass;
	}
	if (characterRace) {
		delete characterRace;
	}
	characterClass = other.characterClass->getNewInstance();
	characterRace = other.characterRace->getNewInstance();

	characterName = other.characterName;
	characterMoney = other.characterMoney;
	characterLevel = other.characterLevel;
	healthPoints = other.healthPoints;
	attackPoints = other.attackPoints;

	return (*this);
}

std::string Character::getCharacterName() const
{
	return std::string(characterName);
}

void Character::peekInventory() const
{
	int index = 1;
	for (auto& i : characterInventory) {
		std::cout << index++ << ". " << i;
	}
}

int Character::getInventorySize() const
{
	return characterInventory.size();
}

void Character::addItem(const Item& i)
{
	characterInventory.push_back(i);
}

void Character::sellItem(int i)
{
	characterMoney += 10;
	characterInventory.erase(characterInventory.begin() + (i - 1));
}

void Character::sellAll()
{
	characterMoney += 10 * characterInventory.size();
	characterInventory.clear();
}

Character::~Character()
{
	delete characterRace;
	delete characterClass;
}

std::ostream& operator<<(std::ostream& os, const Character& c)
{
	os  << "Numele caracterului: " << c.characterName << '\n'
		<< "Level-ul caracterului: " << c.characterLevel << '\n'
		<< "Rasa caracterului: " << c.characterRace->getRaceName() << '\n'
		<< "Clasa caracterului: " << c.characterClass->getClassName() << '\n';
	return os;
}
