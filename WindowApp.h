#pragma once
#include <vector>
#include "Console.h"

class WindowApp {
private:
    Console console;
    std::vector<std::string> tasks;
    int selectedIndex = 0;

    void showWindow()
    {
        WindowConsole mainWin(&console, 2, 5, 15, 50);
        mainWin.Title() = "Task Manager";
        mainWin.SetColors(Color::Blue, Color::White, Color::Blue, Color::White);
        mainWin.Show();

        for (int i = 0; i < tasks.size(); i++)
        {
            std::string task = (i == selectedIndex) ? "> " + tasks[i] : "  " + tasks[i];
            mainWin.WriteGoto(i + 2, 3, task);
        }
        mainWin.WriteGoto(12, 3, "Add: A | Delete: D | Move: Up/Down | Exit: Esc");
    }
};