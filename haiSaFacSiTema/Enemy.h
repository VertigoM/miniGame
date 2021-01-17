#pragma once
#include <vector>
#include "Item.h"

class Enemy
{
public:
	virtual std::vector<Item> droppedItems() const;
	virtual std::unique_ptr<Enemy> getNewInstance() const = 0;

	virtual std::string getEnemyName() const;
};

class Kobold : public Enemy {
	std::vector <Item> droppedItems() const override;
	std::unique_ptr<Enemy> getNewInstance() const override;

	std::string getEnemyName() const override;
};

class Wolf : public Enemy {
	std::vector <Item> droppedItems() const override;
	std::unique_ptr <Enemy> getNewInstance() const override;

	std::string getEnemyName() const override;
};

