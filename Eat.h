#pragma once

#include <iostream>

#include "Position.h"

using namespace std;

static bool eatenUp = true;

class Eat
{
public: 
	Eat(Position position, char material)
	{
		Position(position._x, position._y);
		cout << material;
	}
};

