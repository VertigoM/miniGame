#pragma once
#include <string>
#include <iostream>
class Item
{
public:
	Item(std::string);
	friend std::ostream& operator<<(std::ostream&, const Item&);
protected:
	std::string itemName;
};

