#pragma once
#include <chrono>
#include <thread>

#include "Exception.h"
#include "Character.h"
#include "Enemy.h"

class Encounter
{
public:
	static void fight(Character*);
};

