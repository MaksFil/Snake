#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "Position.h"

class Wall
{
	public: 
		int _width;
		char _material;
		short _positionX, _positionY;

	public:
		void DrawWall(Position position, string direction)
		{
			_positionX = position._x;
			_positionY = position._y;
			Position(_positionX, _positionY);
			
			if(direction == "right")
			{
				for(int i = 0; i < _width; ++i)
				{
					cout << _material;
					Position(++_positionX, _positionY);
				}
			}

			if (direction == "left")
			{

				for (int i = 0; i < _width; ++i)
				{
					cout << _material;
					Position(--_positionX, _positionY);
				}
			}

			if (direction == "top")
			{

				for (int i = 0; i < _width; ++i)
				{
					cout << _material;
					Position(_positionX, --_positionY);
				}
			}

			if (direction == "bottom")
			{

				for (int i = 0; i < _width; ++i)
				{
					cout << _material;
					Position(_positionX, ++_positionY);
				}
			}
		}

	Wall(int width, char material)
	{
		_width = width;
		_material = material;
	}

	Wall() {}
};