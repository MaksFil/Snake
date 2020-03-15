#pragma once
#include "Wall.h"

class HorizontalLine : public Wall
{
public: int _x, _y, _width;
	   char _material;

	HorizontalLine(int width, char material)
	{
		_width = width;
		_material = material;
	}
	void DrawWall()
	{
		Position(0, 0);
		for (int i = 0; i < _width; ++i)
		{
			cout << _material;
			++_x;
		}

		Position(0, 23);
		for (int i = 0; i < _width; ++i)
		{
			cout << _material;
			++_x;
		}
	}
};

