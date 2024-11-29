#include "Console.h"
#include "Menu.h"
#include "Game.h"
//viet code vao day 
int main() {
    SetConsoleOutputCP(437);
    SetFontSize(7, 14);
    setConsoleWindow(1600, 900);
    FixConsoleWindow();
    // PlayMusic(true);
    printMenu();
    system("pause");
    return 0;
}
