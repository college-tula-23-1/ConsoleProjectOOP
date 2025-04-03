#pragma once
#include "Base.h"
#include <string>

enum class Color
{
	Gray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White
};

class Console
{
	HANDLE consoleOutput;
	HANDLE consoleInput;

	COORD coordinate{};
	CONSOLE_SCREEN_BUFFER_INFO info{};
	std::string title;

public:
	Console();
	Console(const char* title);
	Console(std::string title);

	HANDLE& getDescriptor();

	void SetBackColor(Color color, bool brightness);
	void SetForeColor(Color color, bool brightness);
	//void SetColor(BackColor backColor, ForeColor foreColor);

	void CursorGoto(int row, int column);
	void Write(std::string message);
	void Write(char symbol);
	void WriteGoto(int row, int column, std::string message);
	void WriteGoto(int row, int column, char symbol);
	void Rectangle(int row, int column, int height, int width, char pattern);
	void Rect(int row, int column, int height, int width, char pattern);
};
