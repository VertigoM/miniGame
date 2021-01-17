#pragma once
#include <string>

class CharacterRace
{
	std::string raceName;
public:
	CharacterRace(std::string);
	virtual std::string getRaceName() const {
		return std::string("");
	}
	virtual int healthPoints() {
		return 0;
	}
	virtual int atackPoints() {
		return 0;
	}

	virtual CharacterRace* getNewInstance() = 0;

};

class Horde{};

class Alliance{};

class Human : public CharacterRace, public Alliance {
public:
	Human():
		CharacterRace("Human"){}
	std::string getRaceName() const override {
		return std::string("Human");
	}
	int healthPoints() override {
		return 1000;
	}
	int atackPoints() override {
		return 50;
	}

	CharacterRace* getNewInstance() override {
		return new Human();
	}
};

class Dwarf : public CharacterRace, public Alliance {
public:
	Dwarf():
		CharacterRace("Dwarf"){}
	std::string getRaceName() const override {
		return std::string("Dwarf");
	}
	int healthPoints() override {
		return 1500;
	}
	int atackPoints() override {
		return 25;
	}
	CharacterRace* getNewInstance() override {
		return new Dwarf();
	}
};

class Orc : public CharacterRace, public Horde {
public:
	Orc():
		CharacterRace("Orc"){}
	std::string getRaceName() const override {
		return std::string("Orc");
	}
	int healthPoints() override {
		return 1000;
	}
	int atackPoints() override {
		return 50;
	}
	CharacterRace* getNewInstance() override {
		return new Orc();
	}
};

class Undead : public CharacterRace, public Horde {
public:
	Undead() :
		CharacterRace("Undead"){}
	std::string getRaceName() const override {
		return std::string("Undead");
	}
	int healthPoints() override {
		return 750;
	}
	int atackPoints() override {
		return 100;
	}
	CharacterRace* getNewInstance() override {
		return new Undead();
	}
};
