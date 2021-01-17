#pragma once
#include "Item.h"
#include <vector>
class Shop
{
public:
	Shop(){}
	static Shop& getInstance();
	Shop(Shop const&) = delete;
	Shop& operator=(Shop const&) = delete;

	std::vector<Item> soldItems() const;
};

