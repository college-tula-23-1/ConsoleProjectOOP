#include "Console.h"
#include <iostream>

Console::Console()
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleInput = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
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


HANDLE& Console::getDescriptor()
{
	return consoleOutput;
}

void Console::SetBackColor(Color color, bool brightness)
{
	GetConsoleScreenBufferInfo(consoleOutput, &info);
	BYTE colorFore = info.wAttributes & (0b1111);
	BYTE colorBack = (static_cast<BYTE>(color) + (brightness ? 8 : 0)) << 4;
	SetConsoleTextAttribute(consoleOutput, colorBack | colorFore);
}

void Console::SetForeColor(Color color, bool brightness)
{
	GetConsoleScreenBufferInfo(consoleOutput, &info);
	BYTE colorBack = info.wAttributes & (0b1111 << 4);
	BYTE colorFore = static_cast<BYTE>(color) + (brightness ? 8 : 0);
	SetConsoleTextAttribute(consoleOutput, colorBack | colorFore);
}

//void Console::SetColor(BackColor backColor, ForeColor foreColor)
//{
//	SetConsoleTextAttribute(consoleOutput, (int)backColor | (int)foreColor);
//}

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

void Console::Rect(int row, int column, int height, int width, char pattern)
{
	CHAR_INFO* bufferRect = new CHAR_INFO[height * width];
	GetConsoleScreenBufferInfo(consoleOutput, &info);
	BYTE colorFore = info.wAttributes & 0b1111;
	BYTE colorBack = info.wAttributes & (0b1111 << 4);

	BYTE attributes = colorFore | colorBack;
	for (int i{ 0 }; i < height * width; ++i)
	{
		bufferRect[i].Char.UnicodeChar = pattern;
		bufferRect[i].Attributes = attributes;
	}

	COORD bufferSize{ width, height };
	COORD bufferPosition{ 0, 0 };
	SMALL_RECT rect{ column, row, column + width, row + height };
	
	WriteConsoleOutput(consoleOutput, bufferRect, bufferSize, bufferPosition, &rect);
	delete[] bufferRect;
}


