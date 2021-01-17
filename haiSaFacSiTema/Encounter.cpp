#include "Encounter.h"
#include "progressbar.hpp"
#include <random>

void Encounter::fight(Character* c)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 2);

	std::unique_ptr<Enemy> e;
	switch (distrib(gen)) {
	case 1: {
		e = std::make_unique<Kobold>();
		break;
	}
	case 2: {
		e = std::make_unique<Wolf>();
		break;
	}
	default:
		break;
	}


	std::cout << "In his journey, " << c->getCharacterName() << " meets an " << e->getEnemyName() << "!\n"
			  << "They start fighting!\n";
	progressbar bar(100);
	bar.set_todo_char("*");
	bar.set_done_char("#");
	for (int i = 0; i < 100; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		bar.update();
	}
	std::cout << '\n';
	for (auto& i : e->droppedItems()) {
		try {
			if (c->getInventorySize() >= 20) {
				throw(Exception("Inventory is full!"));
				c->sellItem(1);
			}
			else {
				c->addItem(i);
			}
		}
		catch (Exception& e) {
			std::cout << e.what();
			break;
		}
	}
}
