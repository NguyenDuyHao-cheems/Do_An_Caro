#include "Console.h"
#include "Menu.h"
#include "Game.h"

int main() {
    PlayMusic("musicc.wav", L"music_bg");
    SetConsoleOutputCP(437);
    SetFontSize(8, 16);
    setConsoleWindow(1680, 900);
    FixConsoleWindow();
    printMenu();
    system("pause");
    return 0;
}
