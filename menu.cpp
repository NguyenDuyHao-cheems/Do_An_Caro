#include "Menu.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include "board.h"
#include "game.h"
using namespace std;

void SelectMenu(int k) {
    switch (k) {
    case menu1_y:
        NewGame();
        break;
    case menu1_y+2:
        LoadGame();
        break;
    case menu1_y + 4:
        Help();
        break;
    case menu1_y + 6:
        About();
        break;
    case menu1_y + 8:
        Exit();
        break;
    case menu1_y + 10:
        Setting();
        break;
    }
}

void MenuSelection() {
    int x = menu1_x, y = menu1_y;
    int move;
    while (true) {
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S') {
            GotoXY(x - 4, y); cout << "    ";
            GotoXY(x + 25, y); cout << "    ";
            if (y == menu1_y + 10) y = menu1_y;
            else y += 2;
            GotoXY(x - 4, y); cout << "--->";
            GotoXY(x + 25, y); cout << "<---";
        }
        if (move == 72 || move == 'W') {
            GotoXY(x - 4, y); cout << "    ";
            GotoXY(x + 25, y); cout << "    ";
            if (y == menu1_y) y = menu1_y + 10;
            else y -= 2;
            GotoXY(x - 4, y); cout << "--->";
            GotoXY(x + 25, y); cout << "<---";
        }
        if (move == 13) {
            SelectMenu(y);
            break;
        }
    }
}

void printMenu() {
    system("cls");
    system("color B0");
    hideCursor();
    drawCaro();
    txtColor((11 << 4) | 4);
    Box(menu1_x + 3, menu1_y - 1, 19, 2);
    GotoXY(menu1_x + 5, menu1_y);
    cout << "    NEW GAME     " << endl;
    Box(menu1_x + 3, menu1_y + 1, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 1);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 1);
    cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 2);
    cout << "    LOAD GAME    " << endl;
    Box(menu1_x + 3, menu1_y + 3, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 3);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 3);
    cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 4);
    cout << "      HELP       " << endl;
    Box(menu1_x + 3, menu1_y + 5, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 5);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 5);
    cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 6);
    cout << "      ABOUT      " << endl;
    Box(menu1_x + 3, menu1_y + 7, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 7);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 7);
    cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 8);
    cout << "      EXIT       " << endl;
    Box(menu1_x + 3, menu1_y + 9, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 9);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 9);
    cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 10);
    cout << "     SETTINGS    " << endl;
    GotoXY(menu1_x - 4, menu1_y);
    cout << "--->";
    GotoXY(menu1_x + 25, menu1_y);
    cout << "<---";
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
        GotoXY(ix, y); cout << char(196);
        GotoXY(ix, y + h); cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++) {
        GotoXY(x, iy); cout << char(179);
        GotoXY(x + w, iy); cout << char(179);
    }
    GotoXY(x, y); cout << char(218);
    GotoXY(x + w, y); cout << char(191);
    GotoXY(x, y + h); cout << char(192);
    GotoXY(x + w, y + h); cout << char(217);
}

void Help() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    int i = 2;
    GotoXY(x + 20, y + 2);
    cout << "Control: ";
    GotoXY(x + 5, y + 3 + i);
    cout << "W A S D: Move";
    GotoXY(x + 5, y + 4 + i);
    cout << "Enter: choose";
    GotoXY(x + 5, y + 5 + i);
    cout << "L: Save Game";
    GotoXY(x + 5, y + 6 + i);
    cout << "Esc: Exit Game without saving";
    GotoXY(x + 5, y + 8 + i);
    cout << "Press Enter to turn back the main Menu...";
    while (1 > 0) {
        if (_getch() == 13) printMenu();
    }
}

void Exit() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2);
    cout << "Do you want to exit game.";
    GotoXY(x + 10, y + 5);
    cout << "Yes";
    GotoXY(x + 40, y + 5);
    cout << "No";
    GotoXY(x + 7, y + 10);
    cout << "Press y to exit, n to back to menu.";
    char c;
    while (1) {
        c = _getch();
        if (c == 121 || c == 89) { 
            system("cls");
            exit(0);
        }
        else if (c == 110 || c== 78) {
            printMenu();

        }
    }
}

void About() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
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
    cout << "Press Enter to turn back the main Menu...";
    while (1 > 0) {
        if (_getch() == 13) printMenu();
    }
}

void Setting() {

    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    int centerXOn = x + 27;
    int centerXOff = x + 16;
    int centerY = y + 4;
    bool isMusicOn = true;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4);
    cout << "Music ";
    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
    DrawFull(x + 16, y + 4, 12, 0.95, 10, 32);
    DrawFull(x + 27, y + 4, 1, 0.95, 136, 32);

    GotoXY(x + 5, y + 7);
    cout << "F to OFF music";
    GotoXY(x + 5, y + 8);
    cout << "O to ON music";
    GotoXY(x + 5, y + 9);
    cout << "Press Enter to turn back to the main Menu...";

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'F' || key == 'f') {
                if (isMusicOn) {
                    PlayMusic(false);
                    isMusicOn = false;
                    DrawFull(x + 16, y + 4, 12, 0.95, 119, 32);
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 10);
                    DrawFull(x + 16, y + 4, 1, 0.95, 136, 32);

                }
            }
            else if (key == 'O' || key == 'o') {
                if (!isMusicOn) {
                    PlayMusic(true);
                    isMusicOn = true;
                    DrawRoundedBox(x + 15, y + 3, 15, 3, 12);
                    DrawFull(x + 16, y + 4, 12, 0.95, 10, 32);
                    DrawFull(x + 27, y + 4, 1, 0.95, 136, 32);
                }
            }
            else if (key == 13) {
                printMenu();
                break;
            }
        }
    }
}

// ve chu caro
void drawCaro()
{
    int xc = 45;
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
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    DrawFull(30, 8, w + 12, 10, 31, 32);
    float i = 32;
    for (int j = 10; j < 18; j++) {
        DrawFull(i, j, 1, 0.5, 255, 32);
        i += 1;
    }
    for (int j = 10; j < 18; j++) {
        DrawFull(i, j, 1, 0.5, 255, 32);
        i -= 1;
    }
    float i1 = 48;
    for (int j = 10; j < 18; j++) {
        DrawFull(i1, j, 1, 0.5, 255, 32);
        i1 += 0.5;
    }
    for (int j = 17; j > 12; j--) {
        DrawFull(i1, j, 1, 0.5, 255, 32);
        i1 += 1;
    }
    int h1 = i1;
    for (int j = 13; j < 18; j++) {
        DrawFull(h1, j, 1, 0.5, 255, 32);
        h1 += 1;
    }
    float h2 = 65;
    for (int j = 11; j < 18; j++) {
        DrawFull(h2, j, 1, 0.5, 255, 32);
        h2 -= 0.5;
    }
    DrawFull(65.5, 10, 1, 0.5, 255, 32);
    for (int j = 10; j < 18; j++) {
        DrawFull(69.5, j, 1, 0.5, 255, 32);
    }
    for (int j = 10; j < 18; j++) {
        DrawFull(73.5, j, 1, 0.5, 255, 32);
    }
    float m = 74.5;
    for (int j = 10; j < 18; j++) {
        DrawFull(m, j, 1, 0.5, 255, 32);
        m += 2;
    }
    for (int j = 10; j < 18; j++) {
        DrawFull(89.5, j, 1, 0.5, 255, 32);
    }


    cout << endl;
}
void ve2() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    DrawFull(30, 8, w + 12, 10, 31, 32);

    for (int h = 37; h < 41; h++) {
        DrawFull(h, 10, 1, 0.5, 255, 32);
    }
    for (int h2 = 36; h2 < 41; h2++) {
        DrawFull(h2, 17, 1, 0.5, 255, 32);
    }
    for (int hn = 12; hn < 16; hn++) {
        DrawFull(33, hn, 1, 0.5, 255, 32);
    }
    for (int hn = 12; hn < 16; hn++) {
        DrawFull(43, hn, 1, 0.5, 255, 32);
    }
    int hj = 10;
    for (float h = 36.75; h > 35; h--) {
        DrawFull(h, hj, 1, 0.5, 255, 32);
        hj++;
    }
    int hl = 10;
    for (float h = 40.75; h < 42; h++) {
        DrawFull(h, hl, 1, 0.5, 255, 32);
        hl++;
    }
    float i1 = 48;
    for (int j = 10; j < 18; j++) {
        DrawFull(i1, j, 1, 0.5, 255, 32);
        i1 += 0.5;
    }
    for (int j = 17; j > 12; j--) {
        DrawFull(i1, j, 1, 0.5, 255, 32);
        i1 += 1;
    }
    int h1 = i1;
    for (int j = 13; j < 18; j++) {
        DrawFull(h1, j, 1, 0.5, 255, 32);
        h1 += 1;
    }
    float h2 = 65;
    for (int j = 11; j < 18; j++) {
        DrawFull(h2, j, 1, 0.5, 255, 32);
        h2 -= 0.5;
    }
    DrawFull(65.5, 10, 1, 0.5, 255, 32);
    for (int j = 10; j < 18; j++) {
        DrawFull(69.5, j, 1, 0.5, 255, 32);
    }
    for (int j = 10; j < 18; j++) {
        DrawFull(73.5, j, 1, 0.5, 255, 32);
    }
    float m = 74.5;
    for (int j = 10; j < 18; j++) {
        DrawFull(m, j, 1, 0.5, 255, 32);
        m += 2;
    }
    for (int j = 10; j < 18; j++) {
        DrawFull(89.5, j, 1, 0.5, 255, 32);
    }

    DrawFull(34, 16, 1, 0.5, 255, 32);
    DrawFull(42, 16, 1, 0.5, 255, 32);

}

// new game
void NewGameSelection() {
    int x = menu1_x - 15, y = menu1_y - 8;
    int move;
    int kt = 1;
    int option = 1;
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
            GotoXY(x + 10, y + 6);
            cout << "--->";
            GotoXY(x + 36, y + 6);
            cout << "<---";
            if (option == 2) option == 1;
            else option++;
        }
        if (move == 72 || move == 'W') {
            GotoXY(x + 10, y + 6);
            cout << "    ";
            GotoXY(x + 36, y + 6);
            cout << "    ";
            if (y == menu1_y - 8) y = menu1_y - 6;
            else y -= 2;
            GotoXY(x + 10, y + 6);
            cout << "--->";
            GotoXY(x + 36, y + 6);
            cout << "<---";
            if (option == 1) option = 2;
            else option--;
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

bool isMusicPlaying = false;
void PlayMusic(bool isPlaying) {
    if (isPlaying) {
        PlaySound(TEXT("musicc.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        isMusicPlaying = true;

    }
    else {
        PlaySound(NULL, NULL, 0);
        isMusicPlaying = false;
    }
}
