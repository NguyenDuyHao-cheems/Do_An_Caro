#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    SetConsoleOutputCP(437);
<<<<<<< Updated upstream
    SetFontSize(10, 20);
    SetConsoleSize(192, 54);
    FixConsoleWindow();
    printMenu();
    PlayMusic(true);
=======
    SetFontSize(16, 16);
    SetConsoleSize(146,39);
    FixConsoleWindow();
    // PlayMusic(true);
    printMenu();
>>>>>>> Stashed changes
    system("pause");
    return 0;
}
