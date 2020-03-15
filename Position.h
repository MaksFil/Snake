#pragma once

class Position
{

public: short _x, _y;
	  
	  Position(short x, short y)
		{
			_x = x;
			_y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ _x, _y });
		}
};


