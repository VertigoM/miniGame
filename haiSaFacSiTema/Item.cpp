#include "Item.h"

Item::Item(std::string n):
	itemName(std::move(n)){}

std::ostream& operator<<(std::ostream& os, const Item& i) {
	os << i.itemName << '\n';
	return os;
}