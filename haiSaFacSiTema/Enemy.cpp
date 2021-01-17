#include "Enemy.h"

std::vector<Item> Enemy::droppedItems() const
{
    return std::vector<Item>();
}

std::string Enemy::getEnemyName() const
{
    return std::string("");
}

std::vector<Item> Kobold::droppedItems() const
{
    return std::vector<Item>{ {"Gold nugget"}, { "pickaxe" }};
}

std::unique_ptr<Enemy> Kobold::getNewInstance() const
{
    return std::make_unique<Kobold>(*this);
}

std::string Kobold::getEnemyName() const
{
    return std::string("Kobold");
}

std::vector<Item> Wolf::droppedItems() const
{
    return std::vector<Item>{ {"Wolf pelt"}, { "Wolf tooth" }};
}

std::unique_ptr<Enemy> Wolf::getNewInstance() const
{
    return std::make_unique<Wolf>(*this);
}

std::string Wolf::getEnemyName() const
{
    return std::string("Wolf");
}
