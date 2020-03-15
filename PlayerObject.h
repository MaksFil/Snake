#pragma once

#include <iostream>
#include <conio.h>
#include <list>
#include <iterator>
using namespace std;

#include "Position.h"
#include "Eat.h"

static string _direction;
static bool losing;

class PlayerObject
{
public:
	  list <short> objectPositionX, objectPositionY;
	  short nextXPosition, nextYPosition;
	  char _material; int _width;
	  wchar_t buff;

	  
public: short _positionX, _positionY; LPDWORD dwReaden; PWSTR wAttrib;

public: PlayerObject(int width, char material)
	  {
		_width = width;
		_material = material;
	  }

	  int ReadPoint(short x, short y)
	  {
		  DWORD cbRead = 0;
		  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

		  Position(x, y); CONSOLE_SCREEN_BUFFER_INFO info;
		  GetConsoleScreenBufferInfo(hCon, &info);
		  COORD pos = { info.dwCursorPosition.X, info.dwCursorPosition.Y };
		  ReadConsoleOutputCharacter(hCon, &buff, 1, pos, &cbRead);

		  return buff;
	  }


	  void Move(string direction)
	  {

		  if (direction == "right")
		  {
			  nextXPosition = objectPositionX.back();
			  nextYPosition = objectPositionY.back();
			  if (ReadPoint(++nextXPosition, nextYPosition) == 32)
			  {
				  DellPoint();
				  AddPoint();
				  Sleep(100);
			  }

			  else if(ReadPoint(nextXPosition, nextYPosition) == 35)
			  {
				  AddPoint();
				  Sleep(100);
			  }

			  else 
			  {
				  system("cls");
				  Position(0, 0);
				  cout << "Game over! Игра окончена!\n";
				  losing = true;
				  
			  }
		  }

		  if (direction == "left")
		  {
			  nextXPosition = objectPositionX.back();
			  nextYPosition = objectPositionY.back();
			  if (ReadPoint(--nextXPosition, nextYPosition) == 32)
			  {
				  DellPoint();
				  AddPoint();
				  Sleep(100);
			  }

			  else if (ReadPoint(nextXPosition, nextYPosition) == 35)
			  {
				  AddPoint();
				  Sleep(100);
			  }

			  else
			  {
				  system("cls");
				  Position(0, 0);
				  cout << "Game over! Игра окончена!\n";
				  losing = true;
			  }
		  }
		  
		  if (direction == "top")
		  {
			  nextXPosition = objectPositionX.back();
			  nextYPosition = objectPositionY.back();
			  if (ReadPoint(nextXPosition, --nextYPosition) == 32)
			  {
				  DellPoint();
				  AddPoint();
				  Sleep(100);
			  }

			  else if (ReadPoint(nextXPosition, nextYPosition) == 35)
			  {
				  AddPoint();
				  Sleep(100);
			  }

			  else
			  {
				  system("cls");
				  Position(0, 0);
				  cout << "Game over! Игра окончена!\n";
				  losing = true;

			  }
		  }

		  if (direction == "bottom")
		  {
			  nextXPosition = objectPositionX.back();
			  nextYPosition = objectPositionY.back();
			  if (ReadPoint(nextXPosition, ++nextYPosition) == 32)
			  {
				  DellPoint();
				  AddPoint();
				  Sleep(100);
			  }

			  else if (ReadPoint(nextXPosition, nextYPosition) == 35)
			  {
				  AddPoint();
				  Sleep(100);
			  }

			  else
			  {
				  system("cls");
				  Position(0, 0);
				  cout << "Game over! Игра окончена!\n";
				  losing = true;
			  }
		  }
	  }

		static string DirectionObject(int _click)
		{
			switch(_click)
			{
			case 162: case 130: case 100: case 68: // в, В, d, D
				if (_direction != "left") return "right";
				else return "left";
				break;

			case 228: case 148: case 97: case 65: // ф, Ф, a, A
				if (_direction != "right") return "left";
				else return "right";
				break;

			case 230: case 119: case 150: case 87:  // ц, Ц, w, W
				if (_direction != "bottom") return "top";
				else return "bottom";
				break;

			case 235: case 155: case 63: case 115: case 83:  // ы, Ы, і/І, s, S
				if (_direction != "top") return "bottom";
				else return "top";
				break;

			default:
				return _direction;
				break;
			}
		}

		void DrawSnake(Position position, string directionSnake)
		{
			_direction = directionSnake;
			_positionX = position._x;
			_positionY = position._y;
			if (directionSnake == "right")
			{
				for (int i = 0; i < _width; i++)
				{
					Position(_positionX, position._y);

					objectPositionX.push_back(_positionX);
					objectPositionY.push_back(_positionY);

					++_positionX;
					cout << _material;
				}
			}

			if (directionSnake == "left")
			{
				for (int i = 0; i < _width; i++)
				{
					Position(_positionX, position._y);

					objectPositionX.push_back(_positionX);
					objectPositionY.push_back(_positionY);

					--_positionX;
					cout << _material;
				}
			}

			if (directionSnake == "top")
			{
				for (int i = 0; i < _width; i++)
				{
					Position(_positionX, position._y);

					objectPositionX.push_back(_positionX);
					objectPositionY.push_back(_positionY);

					--_positionY;
					cout << _material;
				}
			}

			if (directionSnake == "bottom")
			{
				for (int i = 0; i < _width; i++)
				{
					Position(_positionX, position._y);

					objectPositionX.push_back(_positionX);
					objectPositionY.push_back(_positionY);

					++_positionX;
					cout << _material;
				}
			}

		}

		void DellPoint()
		{
			Position(objectPositionX.front(), objectPositionY.front());
			cout << char(32);
			objectPositionX.pop_front();
			objectPositionY.pop_front();
		}

		void AddPoint()
		{

			Position(nextXPosition, nextYPosition);
			cout << _material;

			objectPositionX.push_back(nextXPosition);
			objectPositionY.push_back(nextYPosition);
		}

};
