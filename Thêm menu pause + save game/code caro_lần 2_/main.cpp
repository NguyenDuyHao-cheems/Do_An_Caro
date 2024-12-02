#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    PlayMusic("musicc.wav", L"music_bg");
    SetConsoleOutputCP(437);
    SetFontSize(16, 16);
    SetConsoleSize(146,39);
    FixConsoleWindow();

    printMenu();
    system("pause");
    return 0;
}
