#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include "board.h"
#include "game.h"
#include "menu.h"
using namespace std;

int optionGame;
//bool isMusicOn = true;
void SelectMenu(int k) {
    switch (k) {
    case menu1_y:
        NewGame();
        break;
    case menu1_y + 3:
        LoadGame();
        break;
    case menu1_y + 6:
        Help();
        break;
    case menu1_y + 9:
        About();
        break;
    case menu1_y + 12:
        Exit();
        break;
    case menu1_y + 15:
        Setting();
        break;
    }
}
void DrawMenuOption(int x, int y, const char* text, int color)
{
    txtColor(color);
    GotoXY(x, y);
    cout << text;
}
void MenuSelection() {
    const int menuCount = 6;
    const char* menuOptions[menuCount] = { "NEW GAME", "LOAD GAME", "HELP", "ABOUT", "EXIT", "SETTINGS" };
    const int menuYOffset = 3;
    int menuPositions[menuCount] = { menu1_y, menu1_y + 3, menu1_y + 6, menu1_y + 9, menu1_y + 12, menu1_y + 15 };
    int x = menu1_x;
    int currentIndex = 0;
    int locate;
    while (true) {
        int move = _getch();
        move = toupper(move);
        if (currentIndex == 4) locate = 11;
        else if (currentIndex == 2 || currentIndex == 3) locate = 5 + 6;
        else if (currentIndex == 5) locate = 10;
        else locate = 9;
        DrawMenuOption(x + locate, menuPositions[currentIndex], menuOptions[currentIndex], (15 << 4) | 4);

        if (move == 80 || move == 'S') {
            currentIndex = (currentIndex + 1) % menuCount;
        }
        else if (move == 72 || move == 'W') {
            currentIndex = (currentIndex - 1 + menuCount) % menuCount;
        }
        else if (move == 13) {
            SelectMenu(menuPositions[currentIndex]);
            break;
        }

        if (isMusicOn) {
            PlayTick("tick.wav", L"tick_sound");
        }
        if (currentIndex == 4) locate = 11;
        else if (currentIndex == 2 || currentIndex == 3) locate = 5 + 6;
        else if (currentIndex == 5) locate = 10;
        else locate = 9;
        DrawMenuOption(x + locate, menuPositions[currentIndex], menuOptions[currentIndex], (0 << 4) | 14);
    }
}
void printMenu() {
    system("cls");
    system("color F0");
    hideCursor();
    drawCaro();
    drawpoke(118, 22);
    drawpoke2(25, 22);


    txtColor((15 << 4) | 4);
    Box(menu1_x + 3, menu1_y - 1, 19, 2);
    GotoXY(menu1_x + 5, menu1_y);
    cout << "    NEW GAME     " << endl;
    Box(menu1_x + 3, menu1_y + 2, 19, 2);
    GotoXY(menu1_x + 5, menu1_y + 3);
    cout << "    LOAD GAME    " << endl;
    Box(menu1_x + 3, menu1_y + 5, 19, 2);
    GotoXY(menu1_x + 5, menu1_y + 6);
    cout << "      HELP       " << endl;
    Box(menu1_x + 3, menu1_y + 8, 19, 2);
    GotoXY(menu1_x + 5, menu1_y + 9);
    cout << "      ABOUT      " << endl;
    Box(menu1_x + 3, menu1_y + 11, 19, 2);
    GotoXY(menu1_x + 5, menu1_y + 12);
    cout << "      EXIT       " << endl;
    Box(menu1_x + 3, menu1_y + 14, 19, 2);
    GotoXY(menu1_x + 5, menu1_y + 15);
    cout << "     SETTINGS    " << endl;
    txtColor((0 << 4) | 14);
    GotoXY(menu1_x + 5 + 4, menu1_y);
    cout << "NEW GAME";
    MenuSelection();
}
void DrawFull(int x, int y, int w, int h, int color, int ch) {
    txtColor(color);
    for (int i = x; i <= x + w; i++) {
        for (int j = y; j <= y + h; j++) {
            GotoXY(i, j);
            cout << char(ch);
        }
    }
    txtColor(116);
}
void Box(int x, int y, int w, int h) {
    if (w <= 1 || h <= 1) return;
    for (int ix = x; ix <= x + w; ix++) {
        GotoXY(ix, y); cout << char(205);
        GotoXY(ix, y + h); cout << char(205);
    }
    for (int iy = y; iy <= y + h; iy++) {
        GotoXY(x, iy); cout << char(186);
        GotoXY(x + w, iy); cout << char(186);
    }
    GotoXY(x, y); cout << char(201);
    GotoXY(x + w, y); cout << char(187);
    GotoXY(x, y + h); cout << char(200);
    GotoXY(x + w, y + h); cout << char(188);

}
void Help() {
    system("cls");
    system("color F0");
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y , w = 103, h = 15;
    drawESC(130, 40);
    drawPinkBox(5, 2);
    drawHowtoPlay(10, 6);
    int xTable = -5, yTable = 1;
    drawTable(xTable+10, yTable+25);
    DrawFull(x + 2, y , w + 1, h, 136, 32);
    DrawFull(x, y-1, w, h, 195, 197);
    DrawFull(x + 2, y , w - 4, h - 2, 119, 32);
    drawpoke(140, 2);
    int i = 2;
    GotoXY(xTable+20,yTable+ y + 2);
    txtColor((15 << 4) | 0);
    cout << "Control: ";
    GotoXY( xTable+15,yTable+ y + 3-2 + i);
    cout << "W A S D: Move";
    GotoXY(xTable+ 15,yTable+ y + 4 -1+ i);
    cout << "Enter: choose";
    GotoXY( xTable+15,yTable+ y + 10 -1+ i);
    cout << "Press Esc to turn back";
    GotoXY(xTable+ 15, yTable+ y + 6 -1+ i);
    cout << "Esc: Pause game";
    GotoXY(xTable +15,yTable+  y + 8 + i-1);
    cout << "U: undo move";
    txtColor((7<<4)|4);
    GotoXY(x +30 , y + 2-1);
    cout << " RULE ";
    GotoXY(x+3, y + 4-1);
    cout << "Objective: Be the first player to align 5 of your symbols (X or O) in a row, column, or diagonal.";
    GotoXY(x +3, y + 6-1);
    cout << "Players: Two players take turns placing their symbol (X or O) on the board.";
    GotoXY(x+3 , y + 8-1);
    cout << "The game ends when a player aligns 5 symbols consecutively.";
    GotoXY(x +3, y + 10-1);
    cout << "If the board is full with no winner, the game is a draw.";
    GotoXY(x+3 , y + 12-1);
    cout << "Undo (Optional): Players can undo their last move";
    while (1) {
        if (_getch() == 27) printMenu();
    }
}
void Exit() {
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 3, y = menu1_y - 5, w = 30, h = 8;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 11, y + 2); cout << "Exit game?";
    txtColor(112);
    GotoXY(x + 8, y + 5); cout << "Yes";
    GotoXY(x + 22, y + 5); cout << "No";
    txtColor(116);
    GotoXY(x + 5, y + 5); cout << "->";
    GotoXY(x + 12, y + 5); cout << "<-";
    while (1) {
        char c = toupper(_getch());
        if (c == 'A' || c == 'D')
        {
            GotoXY(x + 5, y + 5); cout << "  ";
            GotoXY(x + 12, y + 5); cout << "  ";
            if (x == menu1_x - 3) x = menu1_x + 10;
            else if (x == menu1_x + 10) x = menu1_x - 3;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 5, y + 5); cout << "->";
            GotoXY(x + 12, y + 5); cout << "<-";
        }
        else if (c == 13)
        {
            if (x == menu1_x - 3)
            {
                system("cls");
                exit(0);
            }
            else if (x == menu1_x + 10)
            {
                printMenu();
            }
        }
    }
}
void About() {
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 18;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 20, y + 1);
    cout << "Member:";
    GotoXY(x + 5, y + 3);
    cout << "1. MSSV: 24120306 - Nguyen Duy Hao";
    GotoXY(x + 5, y + 5);
    cout << "2. MSSV: 24120295 - Pham Xuan Duy";
    GotoXY(x + 5, y + 7);
    cout << "3. MSSV: 24120224 - Nguyen Anh Thai";
    GotoXY(x + 5, y + 9);
    cout << "4. MSSV: 24120289 - Nguyen Anh Duc";
    GotoXY(x + 5, y + 11);
    cout << "5. MSSV: 24120237 - Nguyen Dinh Tuan";
    GotoXY(x + 5, y + 13);
    cout << "GVDH: Truong Toan Thinh";
    GotoXY(x + 5, y + 15);
    cout << "Press Esc to turn back the main Menu...";

    while (1) {
        if (_getch() == 27) printMenu();
    }
}
void Setting() {
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    int centerXOn = x + 27;
    int centerXOff = x + 16;
    int centerY = y + 4;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "Music ";
    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
    if (isMusicOn) {
        DrawFull(x + 16, y + 4, 12, 0, 10, 32);
        DrawFull(x + 27, y + 4, 1, 0, 136, 32);
    }
    else {
        DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
        DrawFull(x + 16, y + 4, 1, 0, 136, 32);
    }

    GotoXY(x + 5, y + 7);
    cout << "F to OFF music";
    GotoXY(x + 5, y + 8);
    cout << "O to ON music";
    GotoXY(x + 5, y + 9);
    cout << "Press Esc to turn back to the main Menu...";

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'F' || key == 'f') {
                if (isMusicOn) {
                    StopAllSounds();
                    isMusicOn = false;
                    DrawFull(x + 16, y + 4, 12, 0, 119, 32);
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
                    DrawFull(x + 16, y + 4, 1, 0, 136, 32);

                }
            }
            else if (key == 'O' || key == 'o') {
                if (!isMusicOn) {
                    PlayMusic("musicc.wav", L"music_bg");
                    isMusicOn = true;
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 12);
                    DrawFull(x + 16, y + 4, 12, 0, 10, 32);
                    DrawFull(x + 27, y + 4, 1, 0, 136, 32);
                }
            }
            else if (key == 27) {
                printMenu();
                break;
            }
        }
    }
}
// ve chu caro
void drawCaro()
{
    int xc = 68;
    int yc = 5;
    int cyan = 3;
    int pink = 13;
    //c
    DrawFull(xc + 5, yc + 2, 5, 0, 0, 219);
    DrawFull(xc + 3, yc + 3, 3, 5, 0, 219);
    DrawFull(xc + 5, yc + 9, 5, 0, 0, 219);
    DrawFull(xc + 10, yc + 3, 2, 0, 0, 219);
    DrawFull(xc + 10, yc + 8, 2, 0, 0, 219);

    //glow right
    DrawFull(xc + 11, yc + 2, 0, 0, cyan, 219);
    DrawFull(xc + 13, yc + 3, 0, 0, cyan, 219);
    DrawFull(xc + 11, yc + 9, 0, 0, cyan, 219);
    DrawFull(xc + 13, yc + 8, 0, 0, cyan, 219);
    DrawFull(xc + 7, yc + 3, 0, 5, cyan, 219);
    //glow left
    DrawFull(xc + 9, yc + 3, 0, 0, 13, 219);
    DrawFull(xc + 9, yc + 8, 0, 0, 13, 219);
    DrawFull(xc + 4, yc + 2, 0, 0, 13, 219);
    DrawFull(xc + 4, yc + 9, 0, 0, 13, 219);
    DrawFull(xc + 2, yc + 3, 0, 5, 13, 219);
    //a
    DrawFull(xc + 19, yc + 2, 5, 0, 0, 219);
    DrawFull(xc + 17, yc + 3, 3, 0, 0, 219);
    DrawFull(xc + 16, yc + 4, 2, 5, 0, 219);
    DrawFull(xc + 24, yc + 3, 2, 6, 0, 219);
    DrawFull(xc + 19, yc + 6, 4, 0, 0, 219);

    //glow r
    DrawFull(xc + 25, yc + 2, 0, 0, cyan, 219);
    DrawFull(xc + 27, yc + 3, 0, 6, cyan, 219);
    DrawFull(xc + 21, yc + 3, 0, 0, cyan, 219);
    DrawFull(xc + 19, yc + 4, 0, 1, cyan, 219);
    DrawFull(xc + 19, yc + 7, 0, 2, cyan, 219);
    //glow l
    DrawFull(xc + 23, yc + 3, 0, 2, pink, 219);
    DrawFull(xc + 23, yc + 7, 0, 2, pink, 219);
    DrawFull(xc + 15, yc + 4, 0, 5, pink, 219);
    DrawFull(xc + 18, yc + 2, 0, 0, pink, 219);
    DrawFull(xc + 16, yc + 3, 0, 0, pink, 219);
    //r
    DrawFull(xc + 30, yc + 2, 8, 0, 0, 219);
    DrawFull(xc + 30, yc + 2, 1, 7, 0, 219);
    DrawFull(xc + 37, yc + 2, 1, 7, 0, 219);
    DrawFull(xc + 39, yc + 3, 1, 1, 0, 219);
    DrawFull(xc + 39, yc + 7, 1, 2, 0, 219);

    DrawFull(xc + 32, yc + 5, 4, 0, 0, 219);
    DrawFull(xc + 35, yc + 6, 1, 0, 0, 219);
    //glow r
    DrawFull(xc + 26 + 13, yc + 2, 0, 0, cyan, 219);
    DrawFull(xc + 26 + 15, yc + 3, 0, 1, cyan, 219);
    DrawFull(xc + 26 + 13, yc + 5, 0, 1, cyan, 219);
    DrawFull(xc + 26 + 15, yc + 7, 0, 2, cyan, 219);

    DrawFull(xc + 26 + 6, yc + 3, 0, 1, cyan, 219);
    DrawFull(xc + 26 + 6, yc + 6, 0, 3, cyan, 219);
    //glow l
    DrawFull(xc + 26 + 10, yc + 3, 0, 1, pink, 219);
    DrawFull(xc + 26 + 8, yc + 6, 0, 0, pink, 219);
    DrawFull(xc + 26 + 10, yc + 7, 0, 2, pink, 219);
    DrawFull(xc + 26 + 3, yc + 2, 0, 7, pink, 219);
    //o
    DrawFull(xc + 26 + 20, yc + 2, 7, 0, 0, 219);
    DrawFull(xc + 26 + 20, yc + 9, 7, 0, 0, 219);
    DrawFull(xc + 26 + 18, yc + 3, 3, 5, 0, 219);
    DrawFull(xc + 26 + 26, yc + 3, 3, 5, 0, 219);
    //glow r
    DrawFull(xc + 52 + 2, yc + 2, 0, 0, cyan, 219);
    DrawFull(xc + 52 + 4, yc + 3, 0, 5, cyan, 219);
    DrawFull(xc + 52 + 2, yc + 9, 0, 0, cyan, 219);
    DrawFull(xc + 26 + 22, yc + 3, 0, 5, cyan, 219);


    //glow l
    DrawFull(xc + 26 + 19, yc + 2, 0, 0, pink, 219);
    DrawFull(xc + 26 + 19, yc + 9, 0, 0, pink, 219);
    DrawFull(xc + 26 + 17, yc + 3, 0, 5, pink, 219);
    DrawFull(xc + 26 + 25, yc + 3, 0, 5, pink, 219);



}
// draw pixel
void DrawSquare(int x, int y, int color) {
    txtColor(color);

    for (int i = x; i < x + 2; i++) {
        GotoXY(i, y);
        cout << char(219);

    }
    txtColor(116);
}
// ve turn x o
void DrawLine(char a[120], int x, int x2, int y2)
{
    for (int j = 0; j < x; j++)
    {
        if (a[j] == '0') DrawSquare(x2 + 2 * j, y2, 0);
        else if (a[j] == '1') DrawSquare(x2 + 2 * j, y2, 1);
        else if (a[j] == '2') DrawSquare(x2 + 2 * j, y2, 2);
        else if (a[j] == '3') DrawSquare(x2 + 2 * j, y2, 3);
        else if (a[j] == '4') DrawSquare(x2 + 2 * j, y2, 4);
        else if (a[j] == '5') DrawSquare(x2 + 2 * j, y2, 5);
        else if (a[j] == '6') DrawSquare(x2 + 2 * j, y2, 6);
        else if (a[j] == '7') DrawSquare(x2 + 2 * j, y2, 7);
        else if (a[j] == '8') DrawSquare(x2 + 2 * j, y2, 8);
        else if (a[j] == '9') DrawSquare(x2 + 2 * j, y2, 9);
        else if (a[j] == 'A') DrawSquare(x2 + 2 * j, y2, 10);
        else if (a[j] == 'B') DrawSquare(x2 + 2 * j, y2, 11);
        else if (a[j] == 'C') DrawSquare(x2 + 2 * j, y2, 12);
        else if (a[j] == 'D') DrawSquare(x2 + 2 * j, y2, 13);
        else if (a[j] == 'E') DrawSquare(x2 + 2 * j, y2, 14);
        else if (a[j] == 'F') DrawSquare(x2 + 2 * j, y2, 15);
    }
}
void DrawNotX(int x, int y)
{
    char NotX[20][20] = { " 0000     0000 ",
                          "066660   066660",
                          "066660   066660",
                          "0666660 0666660",
                          "046666606666640",
                          "044666666666440",
                          "004466666664400",
                          " 0044EEEEE4400 ",
                          "  006666666600 ",
                          "  06666666660  ",
                          " 0666664666660 ",
                          "066666444666660",
                          "066664404466660",
                          "044444000444440",
                          "0444400 0044440",
                          "000000   000000" };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(NotX[i], 15, x, y);
        y++;
    }
}
void DrawIsX(int x, int y)
{
    char IsX[20][20] = { " 8888     8888 ",
                          "8EEEE8   8EEEE8",
                          "8EEEE8   8EEEE8",
                          "8EEEEE8 8EEEEE8",
                          "8CEEEEE8EEEEEC8",
                          "8CCEEEEEEEEECC8",
                          "88CCEEEEEEECC88",
                          " 88CCCCCCCCC88 ",
                          "  88EEEEEEEE88 ",
                          "  8EEEEEEEEE8  ",
                          " 8EEEEECEEEEE8 ",
                          "8EEEEECCCEEEEE8",
                          "8EEEECC8CCEEEE8",
                          "8CCCCC888CCCCC8",
                          "8CCCC88 88CCCC8",
                          "888888   888888" };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(IsX[i], 15, x, y);
        y++;
    }
}
void DrawNotO(int x, int y)
{
    char NotO[20][20] = {
        "   0000000   ",
        "  011111110  ",
        " 01111111110 ",
        "0111111111110",
        "01111BBB11110",
        "01111BBB11110",
        "0111100011110",
        "088880 088880",
        "033330 033330",
        "0333300033330",
        "0333333333330",
        "0B333333333B0",
        "0BB3333333BB0",
        "00BBBBBBBBB00",
        " 00BBBBBBB00 ",
        "  000000000  "
    };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(NotO[i], 13, x, y);
        y++;
    }
}
void DrawIsO(int x, int y)
{
    char IsO[20][20] = {
        "   0000000   ",
        "  033333330  ",
        " 03333333330 ",
        "0333333333330",
        "03333FFF33330",
        "03333FFF33330",
        "0333300033330",
        "077770 077770",
        "0BBBB0 0BBBB0",
        "0BBBB000BBBB0",
        "0BBBBBBBBBBB0",
        "0FBBBBBBBBBF0",
        "0FFBBBBBBBFF0",
        "00FFFFFFFFF00",
        " 00FFFFFFF00 ",
        "  000000000  "
    };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(IsO[i], 13, x, y);
        y++;
    }
    
}
// ve x win hoac o win
void ve() {
    int x = 40, y = menu1_y + 8;
    int w = 75, h = 12;
    DrawFull(x - 4, y - 2, w, h, 240, 32);
    char win_X[9][35] = {
        "CC     CC    EEE   444 EE 44    EE",
        "CE6   6EC    4C     C4 C4 4C4   C4",
        " 6E6 6E6     CC     CC C4 CCC4  CC",
        "  6E6E6      CC  4  CC C4 CCCC4 CC",
        "   6E6    6  CC CCC CC C4 CC4CC4CC",
        "  6E6E6      CCCC4CCCC C4 CC 4CCCC",
        " 6E6 6E6     4CC4 4CC4 C4 4C  4CC4",
        "CE6   6EC    4C4   4C4 C4 4C   4C4",
        "CC     CC    44     44 44 44    44"
    };
    for (int i = 0; i < 9; i++) {
        DrawLine(win_X[i], 34, x, y);
        y++;
    }
}
void ve2() {
    int x = 40, y = menu1_y + 8;
    int w = 74, h = 12;
    DrawFull(x - 4, y - 2, w, h, 240, 32);
    char win_Y[9][34] = {
        "  111       BBB   111 BB 11    BB",
        " 13331      13     31 31 131   31",
        "133 331     13     33 31 3331  33",
        "13   31     33  1  33 31 33331 33",
        "13 B 31  B  33 333 33 31 33133133",
        "13   31     333313333 31 33 13333",
        "133 331     1331 1331 31 13  1331",
        " 13331      131   131 31 13   131",
        "  111       11     11 11 11    11"
    };
    for (int i = 0; i < 9; i++) {
        DrawLine(win_Y[i], 34, x, y);
        y++;
    }
}
void ve3() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    DrawFull(30, 8, w + 12, 10, 31, 32);
    for (int j = 10; j < 18; j++) {
        DrawFull(32, j, 1, 0, 255, 32);
    }
    for (int j1 = 12; j1 < 16; j1++) {
        DrawFull(39, j1, 1, 0, 255, 32);
    }
    for (int j2 = 32; j2 < 37; j2++) {
        DrawFull(j2, 10, 1, 0, 255, 32);
    }
    for (int j3 = 32; j3 < 37; j3++) {
        DrawFull(j3, 17, 1, 0, 255, 32);
    }
    DrawFull(37, 11, 1, 0, 255, 32);
    DrawFull(37, 16, 1, 0, 255, 32);
    for (int j4 = 10; j4 < 18; j4++) {
        DrawFull(44, j4, 1, 0, 255, 32);
    }
    DrawFull(50, 12, 1, 0, 255, 32);
    for (int j2 = 44; j2 < 48; j2++) {
        DrawFull(j2, 10, 1, 0, 255, 32);
    }
    for (int j2 = 44; j2 < 48; j2++) {
        DrawFull(j2, 14, 1, 0, 255, 32);
    }
    DrawFull(48, 11, 1, 0, 255, 32);
    DrawFull(48, 13, 1, 0, 255, 32);
    int h4 = 47;
    for (int j2 = 14; j2 < 18; j2++) {
        DrawFull(h4, j2, 1, 0, 255, 32);
        h4 += 1;
    }
    int h5 = 54;
    for (int j2 = 17; j2 > 9; j2--) {
        DrawFull(h5, j2, 1, 0, 255, 32);
        h5 += 1;
    }
    for (int j2 = 10; j2 < 18; j2++) {
        DrawFull(h5, j2, 1, 0, 255, 32);
        h5 += 1;
    }
    for (int j2 = 58; j2 < 65; j2++) {
        DrawFull(j2, 14, 1, 0, 255, 32);
    }
    float i1 = 70;
    for (int j = 10; j < 18; j++) {
        DrawFull(i1, j, 1, 0, 255, 32);
        i1 += 0.5;
    }
    int i11 = 74;
    for (int j = 17; j > 12; j--) {
        DrawFull(i11, j, 1, 0, 255, 32);
        i11 += 1;
    }

    int h1 = i11;
    for (int j = 13; j < 18; j++) {
        DrawFull(h1, j, 1, 0, 255, 32);
        h1 += 1;
    }
    float h2 = 87;
    for (int j = 11; j < 18; j++) {
        DrawFull(h2, j, 1, 0, 255, 32);
        h2 -= 0.5;
    }
    DrawFull(87, 10, 1, 0, 255, 32);
}
// new game
void NewGameSelection() {
    int x = menu1_x - 15, y = menu1_y - 8;
    int move;
    int kt = 1;
    optionGame = 1;
    while (kt == 1) {
        GotoXY(x + 10, y + 6);
        cout << "--->";
        GotoXY(x + 36, y + 6);
        cout << "<---";
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S') {
            GotoXY(x + 10, y + 6);
            cout << "    ";
            GotoXY(x + 36, y + 6);
            cout << "    ";
            if (y == menu1_y - 6) y = menu1_y - 8;
            else y += 2;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 10, y + 6);
            cout << "--->";
            GotoXY(x + 36, y + 6);
            cout << "<---";
            if (optionGame == 2) optionGame = 1;
            else optionGame++;
        }
        if (move == 72 || move == 'W') {
            GotoXY(x + 10, y + 6);
            cout << "    ";
            GotoXY(x + 36, y + 6);
            cout << "    ";
            if (y == menu1_y - 8) y = menu1_y - 6;
            else y -= 2;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 10, y + 6);
            cout << "--->";
            GotoXY(x + 36, y + 6);
            cout << "<---";
            if (optionGame == 1) optionGame = 2;
            else optionGame--;
        }
        if (move == 13) {
            switch (y) {
            case menu1_y - 8:
                StartGame();
                break;
            case menu1_y - 6:
                StartGamewithbot();
                break;
            }
            kt = 0;
        }
        if (move == 27) {
            printMenu();
            kt = 0;
        }
    }
}
void NewGame() {
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2);
    cout << "Choose one mode to play";
    GotoXY(x + 17, y + 6);
    cout << "Player with Player";
    GotoXY(x + 18, y + 8);
    cout << "Player with Bot";
    GotoXY(x + 7, y + 12);
    cout << "Press Esc to turn back the main menu...";
    NewGameSelection();
}
void DrawRoundedBox(int x, int y, int width, int height, int color) {
    GotoXY(x, y);
    cout << char(201);
    for (int i = 1; i < width - 1; i++) cout << char(205);
    cout << char(187);
    for (int i = 1; i < height - 1; i++) {
        GotoXY(x, y + i);
        cout << char(186);
        GotoXY(x + width - 1, y + i);
        cout << char(186);
    }
    GotoXY(x, y + height - 1);
    cout << char(200);
    for (int i = 1; i < width - 1; i++) cout << char(205);
    cout << char(188);
}
void CharToWChar(const char* charArray, wchar_t* wcharArray, int size) {
    mbstowcs(wcharArray, charArray, size);
}
void PlayMusic(const char* filePath, const wchar_t* alias) {
    wchar_t command[1024];
    wchar_t wFilePath[512];
    CharToWChar(filePath, wFilePath, 512);
    swprintf(command, 1024, L"close %s", alias);
    mciSendString(command, NULL, 0, NULL);
    swprintf(command, 1024, L"open \"%s\" type mpegvideo alias %s", wFilePath, alias);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to open music file: " << wFilePath << endl;
        return;
    }
    swprintf(command, 1024, L"play %s repeat", alias);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to play music: " << wFilePath << endl;
    }
}
void PlayTick(const char* filePath, const wchar_t* alias) {
    wchar_t command[512];
    wchar_t wFilePath[512];
    CharToWChar(filePath, wFilePath, 512);
    swprintf(command, 512, L"close tick_sound");
    mciSendString(command, NULL, 0, NULL);
    swprintf(command, 512, L"open \"%s\" type waveaudio alias tick_sound", wFilePath);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to open tick sound file: " << wFilePath << endl;
        return;
    }
    swprintf(command, 512, L"play tick_sound");
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to play tick sound: " << wFilePath << endl;
    }
}
void PlayWin(const char* filePath, const wchar_t* alias) {
    wchar_t command[512];
    wchar_t wFilePath[512];
    CharToWChar(filePath, wFilePath, 512);
    swprintf(command, 512, L"close win_sound");
    mciSendString(command, NULL, 0, NULL);
    swprintf(command, 512, L"open \"%s\" type waveaudio alias win_sound", wFilePath);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        // wcerr << L"Failed to open win sound file: " << wFilePath << endl;
        return;
    }
    swprintf(command, 512, L"play win_sound");
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to play win sound: " << wFilePath << endl;
    }
}
void PlayMove(const char* filePath, const wchar_t* alias) {
    wchar_t command[512];
    wchar_t wFilePath[512];
    CharToWChar(filePath, wFilePath, 512);
    swprintf(command, 512, L"close move_sound");
    mciSendString(command, NULL, 0, NULL);
    swprintf(command, 512, L"open \"%s\" type waveaudio alias move_sound", wFilePath);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to open  sound file: " << wFilePath << endl;
        return;
    }
    swprintf(command, 512, L"play move_sound");
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to play move sound: " << wFilePath << endl;
    }
}
void PlayMo(const char* filePath, const wchar_t* alias) {
    wchar_t command[512];
    wchar_t wFilePath[512];
    CharToWChar(filePath, wFilePath, 512);
    swprintf(command, 512, L"close mo_sound");
    mciSendString(command, NULL, 0, NULL);
    swprintf(command, 512, L"open \"%s\" type waveaudio alias mo_sound", wFilePath);
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to open  sound file: " << wFilePath << endl;
        return;
    }
    swprintf(command, 512, L"play mo_sound");
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        //wcerr << L"Failed to play mo sound: " << wFilePath << endl;
    }
}
void StopAllSounds() {
    mciSendString(L"stop music_bg", NULL, 0, NULL);
    mciSendString(L"close music_bg", NULL, 0, NULL);
    mciSendString(L"stop tick_sound", NULL, 0, NULL);
    mciSendString(L"close tick_sound", NULL, 0, NULL);
    mciSendString(L"stop win_sound", NULL, 0, NULL);
    mciSendString(L"close win_sound", NULL, 0, NULL);
    mciSendString(L"stop move_sound", NULL, 0, NULL);
    mciSendString(L"close move_sound", NULL, 0, NULL);
    mciSendString(L"stop mo_sound", NULL, 0, NULL);
    mciSendString(L"close mo_sound", NULL, 0, NULL);
}

void PauseMenu()
{
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y - 12, w = 50, h = 20;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 23, y + 6);
    cout << "RESUME";
    GotoXY(x + 23, y + 8);
    cout << "RESTART";
    GotoXY(x + 24, y + 10);
    cout << "SAVE";
    GotoXY(x + 23, y + 12);
    cout << "SETTING";
    GotoXY(x + 24, y + 14);
    cout << "EXIT";
    GotoXY(x + 17, y + 6); cout << "--->";
    GotoXY(x + 32, y + 6); cout << "<---";

    int move, option = 1, check = 1;
    while (check == 1) {
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S') {
            GotoXY(x + 17, y + 6); cout << "    ";
            GotoXY(x + 32, y + 6); cout << "    ";
            if (option == 5)
            {
                y = menu1_y - 12;
                option = 1;
            }
            else
            {
                y += 2;
                option++;
            }
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 17, y + 6); cout << "--->";
            GotoXY(x + 32, y + 6); cout << "<---";
        }
        if (move == 72 || move == 'W') {
            GotoXY(x + 17, y + 6); cout << "    ";
            GotoXY(x + 32, y + 6); cout << "    ";
            if (option == 1)
            {
                y = menu1_y - 12 + 8;
                option = 5;
            }
            else
            {
                y -= 2;
                option--;
            }
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 17, y + 6); cout << "--->";
            GotoXY(x + 32, y + 6); cout << "<---";
        }
        hideCursor();
        if (move == 13)
        {
            PauseSelection(option);
            check = 0;
        }
    }
}
void PauseSelection(int option)
{
    switch (option)
    {
    case 1:
        ResumeGame(optionGame);
        break;
    case 2:
        StartGame();
        break;
    case 3:
        SaveGameMenu();
        break;
    case 4:
        SettingPause();
        break;
    case 5:
        printMenu();
        break;
    default:
        PauseSelection(option);
    }
}
void duplicateNameMenu()
{
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "NAME'S ALREADY EXISTS!";
    GotoXY(x + 5, y + 5);
    txtColor(112);
    cout << "Press Esc to go back.";
    txtColor(116);
}
void SaveSuccessMenu()
{

    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "FILE HAS BEEN SAVED!";
    GotoXY(x + 5, y + 5);
    txtColor(112);
    cout << "Press Esc to go back.";
    txtColor(116);
}
void maxNumSFMenu()
{
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "MAX SAVE FILES REACH!";
    GotoXY(x + 5, y + 5);
    txtColor(112);
    cout << "Press Esc to go back.";
    txtColor(116);
}
void SettingPause() 
{
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    int centerXOn = x + 27;
    int centerXOff = x + 16;
    int centerY = y + 4;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "Music ";
    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
    if (isMusicOn) {
        DrawFull(x + 16, y + 4, 12, 0, 10, 32);
        DrawFull(x + 27, y + 4, 1, 0, 136, 32);
    }
    else {
        DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
        DrawFull(x + 16, y + 4, 1, 0, 136, 32);
    }

    GotoXY(x + 5, y + 7);
    cout << "F to OFF music";
    GotoXY(x + 5, y + 8);
    cout << "O to ON music";
    GotoXY(x + 5, y + 9);
    txtColor(112);
    cout << "Press Esc to go back.";
    txtColor(116);

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'F' || key == 'f') {
                if (isMusicOn) {
                    StopAllSounds();
                    isMusicOn = false;
                    DrawFull(x + 16, y + 4, 12, 0, 119, 32);
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
                    DrawFull(x + 16, y + 4, 1, 0, 136, 32);

                }
            }
            else if (key == 'O' || key == 'o') {
                if (!isMusicOn) {
                    PlayMusic("musicc.wav", L"music_bg");
                    isMusicOn = true;
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 12);
                    DrawFull(x + 16, y + 4, 12, 0, 10, 32);
                    DrawFull(x + 27, y + 4, 1, 0, 136, 32);
                }
            }
            else if (key == 27) {
                PauseMenu();
                break;
            }
        }
    }
}
void drawpoke(int x, int y) {
    char poke[22][22] = {
    "    0000         0   ",
    "   0CCCC0       040  ",
    "  0CCCCCC0      0440 ",
    "  0CCCCCC0      0440 ",
    " 0CCCCCCCC0    04   0",
    "0CCCC 0CCC0    0  1C0",
    "0CCCC00CCCC0   0 11C0",
    "0CCCC00CCCC0    0100 ",
    " 0CCCCCCCCCC0   0C0  ",
    "  00CCCCCCCCC0 0CC0  ",
    "    000CC0CCC00CC0   ",
    "     0EE0CCCCC0CC0   ",
    "     0EEE00CCC0C0    ",
    "    0 0EEECCCC00     ",
    "     000EECCC00      ",
    "        000CC0       ",
    "         0 C 0       ",
    "          0000       " };
    for (int i = 0; i <= 18; i++)
    {
        DrawLine(poke[i], 21, x, y);
        y++;
    }
}

void drawpoke2(int x, int y) {
    char poke[21][21] = {
        "     000            ",
        "    0AAA0           ",
        "    0AAA000         ",
        "  00A2AA2AA00       ",
        " 0AAA2AA22AA20  0   ",
        "0AAA2AAA2A2A2000B0  ",
        "0AA2AAAAA22200BBB0  ",
        "02A2AAAAA2203BBBB0  ",
        " 022AAA2000B33B3BB0 ",
        " 0000A220BBBBBBBB300",
        " 033300030BBB3BBB300",
        " 0 3033333B33B3BBBB0",
        "  00033033  40BBBBB0",
        "     033033 403BBB0 ",
        "     0333033333300  ",
        "     0 3 0000000    ",
        "      000           "
    };
    for (int i = 0; i <= 17; i++)
    {
        DrawLine(poke[i], 20, x, y);
        y++;
    }
}
void drawTable(int x, int y)
{
    char table[22][25] = {
        "0000000000000000000     ",
        "0FFFFFFFFFFFFFFFFFF0    ",
        "0FFFFFFFFFFFFFFFFFFF0   ",
        "0FFFFFFFFFFFFFFFFFFFF0  ",
        "0FFFFFFFFFFFFFFFFFFFFF0 ",
        "0FFFFFFFFFFFFFFFFFFFFFF0",
        "0FFFFFFFFFFFFFFFFFFFFFF0",
        "0FFFFFFFFFFFFFFFFFFFFFF0",
        "0FFFFFFFFFFFFFFFFFFFFF0 ",
        "0FFFFFFFFFFFFFFFFFFFF0  ",
        "0FFFFFFFFFFFFFFFFFFF0   ",
        "0FFFFFFFFFFFFFFFFFF0    ",
        "0000000000000000000     ",
        "       00               ",
        "       00               ",
        "       00               ",
        "       00               ",
        "       00               ",
        "       00               ",
        "       00               ",
        "       00               " };
    for (int i = 0; i <= 21; i++)
    {
        DrawLine(table[i], 25, x, y);
        y++;
    }
}
void drawHowtoPlay(int x, int y)
{
    char howtoPlay[5][63] = {
        "F  F   FF   F   F    FFFFF   FF     FFFF   F      FFFF   F   F",
        "F  F  F  F  F F F      F    F  F    F   F  F     F    F  F   F",
        "FFFF  F  F  F F F      F    F  F    F   F  F     FFFFFF   F F ",
        "F  F  F  F  F F F      F    F  F    FFFF   F     F    F    F  ",
        "F  F   FF    F F       F     FF     F      FFFF  F    F    F  " };
    for (int i = 0; i <= 4; i++)
    {
        DrawLine(howtoPlay[i], 63, x, y);
        y++;
    }


}
void drawPinkBox(int x, int y)
{
    char pinkBox[13][67] = {
        "   000000000000000000000000000000000000000000000000000000000000   ",
        "  0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0  ",
        " 0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0 ",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        " 0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0 ",
        "  0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0  ",
        "   000000000000000000000000000000000000000000000000000000000000   " };
    for (int i = 0; i < 13; i++)
    {
        DrawLine(pinkBox[i], 67, x, y);
        y++;
    }
        
    
}

void drawPauseBox(int x, int y)
{
    char pauseBox[15][19] = {
        "    000000000   ",
        "   08888888880  ",
        "  0888888888880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        " 08880F080F08880 ",
        "  0888888888880 ",
        "   08888888880  ",
        "    000000000   "

    };
    for (int i = 0; i < 15; i++)
    {
        DrawLine(pauseBox[i], 19, x, y);
        y++;
    }
} 
void drawESC(int x, int y)
{
    char esc[8][27] = {
        " 0000     000     0000  ",
        "0FFFF0   0FFF0   0FFFF0 ",
        "0F0000  0F0000  0F00000",
        "0F0000  0F0000  0F00000",
        "0FFFF0  00FFF0  0F00000 ",
        "0F0000  0000F0  0F00000 ",
        "0FFFF0  0FFFF0  0FFFFF0 ",
        " 0000   000000   000000 ",

    };
    for (int i = 0; i < 8; i++)
    {
        DrawLine(esc[i], 27, x, y);
        y++;
    }

}