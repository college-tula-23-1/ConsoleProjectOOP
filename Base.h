#pragma once
#include <Windows.h>

struct Point
{
	int row;
	int column;
};

enum class ForeColor
{
	Black = 0b0000,
	Blue = 0b0001,
	Green = 0b0010,
	Cyan = 0b0011,
	Red = 0b0100,
	Magenta = 0b0101,
	Yellow = 0b0110,
	LightGray = 0b0111,

	Gray = 0b1000,
	LightBlue = 0b1001,
	LightGreen = 0b1010,
	LightCyan = 0b1011,
	LightRed = 0b1100,
	LightMagenta = 0b1101,
	LightYellow = 0b1110,
	White = 0b1111,
};

enum class BackColor
{
	Black = 0b00000000,
	Blue = 0b00010000,
	Green = 0b00100000,
	Cyan = 0b00110000,
	Red = 0b01000000,
	Magenta = 0b01010000,
	Yellow = 0b01100000,
	LightGray = 0b01110000,

	Gray = 0b10000000,
	LightBlue = 0b10010000,
	LightGreen = 0b10100000,
	LightCyan = 0b10110000,
	LightRed = 0b11000000,
	LightMagenta = 0b11010000,
	LightYellow = 0b11100000,
	White = 0b11110000,
};
