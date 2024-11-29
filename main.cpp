#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    SetConsoleOutputCP(437);
    SetFontSize(10, 20);
    SetConsoleSize(192, 54);
    FixConsoleWindow();
    printMenu();
    PlayMusic(true);
    system("pause");
    return 0;
}
