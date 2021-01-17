#pragma once
#include <string>
class CharacterClass
{
	std::string className;
public:
	virtual std::string getClassName() {
		return std::string("");
	}

	virtual CharacterClass* getNewInstance() = 0;
};

class Mage : public CharacterClass {
public:
	std::string getClassName() override {
		return std::string("Mage");
	}
	CharacterClass* getNewInstance() override {
		return new Mage();
	}
};

class Warrior : public CharacterClass {
public:
	std::string getClassName() override {
		return std::string("Warrior");
	}

	CharacterClass* getNewInstance() override {
		return new Warrior();
	}
};

class Rogue : public CharacterClass {
public:
	std::string getClassName() override {
		return std::string("Rogue");
	}
	CharacterClass* getNewInstance() override {
		return new Rogue();
	}
};


