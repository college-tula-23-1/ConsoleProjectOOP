#include <iostream>
#include "Console.h"

int main()
{
	Console console{ "Ny console" };
	console.SetForeColor(Color::Green, 1);
	console.SetBackColor(Color::Gray, 0);

	console.Rectangle(1, 1, 5, 10, 'q');

	console.Rect(1, 1, 5, 10, 'Я');
	std::cin.get();
}
