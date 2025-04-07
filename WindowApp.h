#pragma once
#include "Console.h"
#include "vector"
#include <iostream>
#include <conio.h>

class WindowApp
{
	Console console{};
	std::vector<std::string> tasks{};
	int position{};

public:
	void showWindow()
	{
		WindowConsole mainWin{ &console, 2, 5, 15, 52 };
		mainWin.Title() = "Task manager";
		mainWin.SetColors(Color::Blue, Color::Green, Color::Blue, Color::White);
		mainWin.Show();

		for (int i{}; i < tasks.size(); ++i)
		{
			std::string task = (i == position) ? '>' + tasks[i] : ' ' + tasks[i];
			mainWin.WriteGoto(i + 2, 3, task);
		}
		mainWin.WriteGoto(12, 3, "Add: a | Delete: d | Move: up/down | Quit: Esc");

		if (tasks.empty())
		{
			mainWin.WriteGoto(3, 3, "List is empty...");
		}
	}

	void run()
	{
		console.WriteGoto(0, 0, "Starting app...");

		tasks.push_back("Task1");
		tasks.push_back("Task2");
		tasks.push_back("Task3");

		bool running{ true };

		while (running)
		{
			showWindow();

			int key = _getch();
			if (key == 0 || key == 0xE0)
				key = _getch();

			switch (key)
			{
			case 27:
				running = false;
				break;
			case 72:
				if (position > 0)
					position--;
				break;
			case 80:
				if (!tasks.empty() && tasks.size() - 1 > position)
					position++;
				break;
			case 'a':
			case 'A':
			{
				WindowConsole inputWin{ &console, 8, 10, 5, 40 };
				inputWin.Title() = "New Task";
				inputWin.SetColors(Color::Blue, Color::Red, Color::Gray, Color::White);
				inputWin.Show();

				std::string result{};
				console.CursorGoto(10, 12);
				std::cout << "Enter task: ";
				std::getline(std::cin, result);

				if (!result.empty())
				{
					tasks.push_back(result);
					position = tasks.size() - 1;
				}
				break;
			}
			case 'd':
			case 'D':
				if (!tasks.empty())
				{
					tasks.erase(tasks.begin() + position);
				}
				break;
			}
		}
	}
};

