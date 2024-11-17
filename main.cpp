#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    PlayMusic(true);
    SetConsoleOutputCP(437);
    SetConsoleSize(1920, 1080);
    printMenu();
    system("pause");
    return 0;
}
