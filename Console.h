#pragma once
#include "Base.h"
#include <string>

class Console
{
	HANDLE consoleOutput;
	HANDLE consoleInput;

	COORD coordinate{};

	std::string title;

public:
	Console();
	Console(const char* title);
	Console(std::string title);

	void SetBackColor(BackColor color);
	void SetForeColor(ForeColor color);
	void SetColor(BackColor backColor, ForeColor foreColor);

	void CursorGoto(int row, int column);
	void Write(std::string message);
	void Write(char symbol);
	void WriteGoto(int row, int column, std::string message);
	void WriteGoto(int row, int column, char symbol);
	void Rectangle(int row, int column, int height, int width, char pattern);
};
