#include "Shop.h"

Shop& Shop::getInstance()
{
	static Shop instance;
	return instance;
}
