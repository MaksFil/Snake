#pragma once
#include "Wall.h"
class VerticalLine : public Wall
{
public: int _width;
	  short _y;
	  char _material;

	VerticalLine(int width, char material)
	{
		_width = width;
		_material = material;
	}
	void DrawWall()
	{
		Position(0, 1);
		for (int i = 0; i < _width; ++i)
		{
			cout << _material << "\n";
		}

		_y = 1;
		Position(78, _y);
		for (int i = 0; i < _width; ++i)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 78, _y++});
			cout << _material;
		}
	}
};

