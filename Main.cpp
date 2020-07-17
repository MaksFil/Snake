#include <iostream>
#include <conio.h>
#include <windows.h>
#include <future>  
#include <time.h>
#include <thread>
using namespace std;

#include "PlayerObject.h"
#include "Wall.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Position.h"
#include "Eat.h"

int random(int minValue, int maxValue) 
{ 
	return minValue + rand() % maxValue; 
}

void SpawnEat()
{
	while (true)
	{
		Sleep(random(3000, 15000));
		if (losing == false)
		{
			Eat(Position(short(random(1, 78)), short(random(1, 22))), char(35)); // #
		}
		else break;
	}
}

void InputDirection()
{
	while (true)
	{
		if (losing == false) _direction = PlayerObject::DirectionObject(_getch());
		else break;
	}
}

int main() 
{
		losing = false;
		system("cls");
		setlocale(LC_ALL, "Russian");

		HorizontalLine horizontalLine(79, char(95)); // _
		horizontalLine.DrawWall();

		VerticalLine verticalLine(23, char(33)); // !
		verticalLine.DrawWall();

		Position firstPositionSnake(10, 10);

		PlayerObject Snake(3, char(42)); // *
		Snake.DrawSnake(firstPositionSnake, "right");

		auto randomSpawnEat = async(SpawnEat);
		auto inputDirection = async(InputDirection);
		

		while (true)
		{
			if (losing)
			{
				system("pause");
				main();
			}
			else
			{
				Snake.Move(_direction);
			}
		}
		
	return 0;
}

