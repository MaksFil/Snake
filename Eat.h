#pragma once

#include <iostream>

#include "Position.h"
#include "PlayerObject.h"

using namespace std;

class Eat
{
public: 
	Eat(Position position, char material)
	{
		if (Position::ReadPoint(position._x, position._y) == 32)
		{
			Position(position._x, position._y);
			cout << material;
		}
	}
};

