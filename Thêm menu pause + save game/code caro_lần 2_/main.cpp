#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    SetConsoleOutputCP(437);
    SetFontSize(16, 16);
    SetConsoleSize(146,39);
    FixConsoleWindow();
    // PlayMusic(true);
    printMenu();
    system("pause");
    return 0;
}
