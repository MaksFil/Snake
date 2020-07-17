#pragma once

class Position
{

public: 	
	 short _x, _y;
	  
	  Position(short x, short y)
		{
			_x = x;
			_y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ _x, _y });
		}

	  static int ReadPoint(short x, short y)
	  {
		  wchar_t buffer;
		  DWORD consoleRead = 0;
		  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		  Position(x, y); CONSOLE_SCREEN_BUFFER_INFO info;
		  GetConsoleScreenBufferInfo(console, &info);
		  COORD position = { info.dwCursorPosition.X, info.dwCursorPosition.Y };
		  ReadConsoleOutputCharacter(console, &buffer, 1, position, &consoleRead);

		  return buffer;
	  }
};


