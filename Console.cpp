#include "Console.h"
#include <iostream>

Console::Console()
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleInput = GetStdHandle(STD_INPUT_HANDLE);
}

Console::Console(const char* title)
	: Console()
{
	this->title = title;
	SetConsoleTitleA(this->title.c_str());
}

Console::Console(std::string title)
	: Console(title.c_str()) {
}

void Console::SetBackColor(BackColor color)
{
	SetConsoleTextAttribute(consoleOutput, (int)color);
}

void Console::SetForeColor(ForeColor color)
{
	SetConsoleTextAttribute(consoleOutput, (int)color);
}

void Console::SetColor(BackColor backColor, ForeColor foreColor)
{
	SetConsoleTextAttribute(consoleOutput, (int)backColor | (int)foreColor);
}

void Console::CursorGoto(int row, int column)
{
	coordinate.X = column;
	coordinate.Y = row;
	SetConsoleCursorPosition(consoleOutput, coordinate);
	
}

void Console::Write(std::string message)
{
	std::cout << message;
}

void Console::Write(char symbol)
{
	std::cout << symbol;
}

void Console::WriteGoto(int row, int column, std::string message)
{
	CursorGoto(row, column);
	Write(message);
}

void Console::WriteGoto(int row, int column, char symbol)
{
	CursorGoto(row, column);
	Write(symbol);
}

void Console::Rectangle(int row, int column, int height, int width, char pattern)
{
	for (int r = 0; r < height; r++)
		for (int c = 0; c < width; c++)
			WriteGoto(row + r, column + c, pattern);
}