#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include "board.h"
#include "game.h"
#include "menu.h"
using namespace std;
int curlang = 0;
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
        Setting();
        break;
    case menu1_y + 15:
        Exit();
        break;
    }
}
void DrawMenuOption(int x, int y, const char* text, int color) {
    txtColor(color);
    GotoXY(x, y); cout << text;
}
void MenuSelection() {
    if (curlang == 0) {
        int x = menu1_x, y = menu1_y, move;
        while (true) {
            move = _getch(); move = toupper(move);
            if (move == 80 || move == 'S') {
                txtColor((15 << 4) | 4);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 9, y); cout << "NEW GAME" << endl;
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "LOAD GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 5 + 6, y); cout << "HELP";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 5 + 6, y); cout << "ABOUT";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "SETTINGS";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "EXIT";
                    break;
                }
                if (y == menu1_y + 15) y = menu1_y;
                else y += 3;
                txtColor((0 << 4) | 14);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 9, y); cout << "NEW GAME";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "LOAD GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 5 + 6, y); cout << "HELP";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 5 + 6, y); cout << "ABOUT";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "SETTINGS";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "EXIT";
                    break;
                }
            }
            if (move == 72 || move == 'W') {
                txtColor((15 << 4) | 4);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 9, y); cout << "NEW GAME";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "LOAD GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 5 + 6, y); cout << "HELP";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 5 + 6, y); cout << "ABOUT";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "SETTINGS";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "EXIT";
                    break;
                }
                if (y == menu1_y) y = menu1_y + 15;
                else y -= 3;
                txtColor((0 << 4) | 14);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 9, y); cout << "NEW GAME";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "LOAD GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 5 + 6, y); cout << "HELP";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 5 + 6, y); cout << "ABOUT";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "SETTINGS";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "EXIT";
                    break;
                }
            }
            if (move == 13) {
                SelectMenu(y);
                break;
            }
        }
    }
    else {
        int x = menu1_x, y = menu1_y, move;
        while (true) {
            move = _getch(); move = toupper(move);
            if (move == 80 || move == 'S') {
                txtColor((15 << 4) | 4);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 7, y); cout << "TRO CHOI MOI" << endl;
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "TAI GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 3 + 6, y); cout << "HUONG DAN";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 3 + 6, y); cout << "THONG TIN";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "CAI DAT";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "THOAT";
                    break;
                }
                if (y == menu1_y + 15) y = menu1_y;
                else y += 3;
                txtColor((0 << 4) | 14);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 7, y); cout << "TRO CHOI MOI";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "TAI GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 3 + 6, y); cout << "HUONG DAN";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 3 + 6, y); cout << "THONG TIN";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "CAI DAT";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "THOAT";
                    break;
                }
            }
            if (move == 72 || move == 'W') {
                txtColor((15 << 4) | 4);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 7, y); cout << "TRO CHOI MOI";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "TAI GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 3 + 6, y); cout << "HUONG DAN";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 3 + 6, y); cout << "THONG TIN";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "CAI DAT";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "THOAT";
                    break;
                }
                if (y == menu1_y) y = menu1_y + 15;
                else y -= 3;
                txtColor((0 << 4) | 14);
                switch (y) {
                case menu1_y:
                    GotoXY(x + 7, y); cout << "TRO CHOI MOI";
                    break;
                case menu1_y + 3:
                    GotoXY(x + 9, y); cout << "TAI GAME";
                    break;
                case menu1_y + 6:
                    GotoXY(x + 3 + 6, y); cout << "HUONG DAN";
                    break;
                case  menu1_y + 9:
                    GotoXY(x + 3 + 6, y); cout << "THONG TIN";
                    break;
                case menu1_y + 12:
                    GotoXY(x + 4 + 6, y); cout << "CAI DAT";
                    break;
                case menu1_y + 15:
                    GotoXY(x + 6 + 5, y); cout << "THOAT";
                    break;
                }
            }
            if (move == 13) {
                SelectMenu(y);
                break;
            }
        }
    }

}
void printMenu() {
    system("cls");
    system("color F0");
    hideCursor();
    drawCaro();
    win_x = 0;
    win_y = 0;
    h = 0;
    drawBigCloud(25, 35);
    drawBigCloud(129, 35);
    drawSmallCloud(19, 7);
    drawSmallCloud(26, 10);
    drawSmallCloud(139, 5);
    drawSmallCloud(157, 13);
    drawpoke(131, 25);
    drawpoke2(28, 26);
    if (curlang == 0) {
        txtColor((15 << 4) | 4);
        Box(menu1_x + 3, menu1_y - 1, 19, 2);
        GotoXY(menu1_x + 5, menu1_y); cout << "    NEW GAME     " << endl;
        Box(menu1_x + 3, menu1_y + 2, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 3); cout << "    LOAD GAME    " << endl;
        Box(menu1_x + 3, menu1_y + 5, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 6); cout << "      HELP       " << endl;
        Box(menu1_x + 3, menu1_y + 8, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 9); cout << "      ABOUT      " << endl;
        Box(menu1_x + 3, menu1_y + 11, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 15); cout << "      EXIT       " << endl;
        Box(menu1_x + 3, menu1_y + 14, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 12); cout << "     SETTINGS    " << endl;
        txtColor((0 << 4) | 14);
        GotoXY(menu1_x + 5 + 4, menu1_y); cout << "NEW GAME";
        MenuSelection();
    }
    else {
        txtColor((15 << 4) | 4);
        Box(menu1_x + 3, menu1_y - 1, 19, 2);
        GotoXY(menu1_x + 5, menu1_y); cout << "  TRO CHOI MOI" << endl;
        Box(menu1_x + 3, menu1_y + 2, 19, 2);
        GotoXY(menu1_x + 7, menu1_y + 3); cout << "  TAI GAME    " << endl;
        Box(menu1_x + 3, menu1_y + 5, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 6); cout << "    HUONG DAN    " << endl;
        Box(menu1_x + 3, menu1_y + 8, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 9); cout << "    THONG TIN    " << endl;
        Box(menu1_x + 3, menu1_y + 11, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 15); cout << "      THOAT      " << endl;
        Box(menu1_x + 3, menu1_y + 14, 19, 2);
        GotoXY(menu1_x + 5, menu1_y + 12); cout << "     CAI DAT    " << endl;
        txtColor((0 << 4) | 14);
        GotoXY(menu1_x + 5 + 2, menu1_y); cout << "TRO CHOI MOI";
        MenuSelection();
    }

}
void DrawFull(int x, int y, int w, int h, int color, int ch) {
    txtColor(color);
    for (int i = x; i <= x + w; i++) {
        for (int j = y; j <= y + h; j++) {
            GotoXY(i, j); cout << char(ch);
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
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");

    des(140, 2);
    if (curlang == 0) {
        int x = menu1_x - 15, y = menu1_y, w = 103, h = 15;
        const int xRule = 50, yRule = 25;
        drawESC(130, 40);
        drawPinkBox(5, 2);
        drawHowtoPlay(10, 6);
        int xTable = -5, yTable = 1;
        drawTable(xTable + 10, yTable + 25);
        DrawFull(x + 2, y - 2, w + 1, h, 136, 32);
        DrawFull(x, y - 3, w, h, 195, 197);
        DrawFull(x + 2, y - 2, w - 4, h - 2, 119, 32);
        int i = 2;
        GotoXY(xTable + 20, yTable + y);
        txtColor((15 << 4) | 0); cout << "Control: ";
        GotoXY(xTable + 15, yTable + y + 1 - 2 + i); cout << "W A S D: Move";
        GotoXY(xTable + 15, yTable + y + 2 - 1 + i); cout << "Enter: choose";
        GotoXY(xTable + 15, yTable + y + 8 - 1 + i); cout << "Press Esc to turn back";
        GotoXY(xTable + 15, yTable + y + 4 - 1 + i); cout << "Esc: Pause game";
        GotoXY(xTable + 15, yTable + y + 6 + i - 1); cout << "U: undo move";
        txtColor((7 << 4) | 4);
        GotoXY(x + 30, y - 1); cout << " RULE ";
        GotoXY(x + 3, y + 2 - 1); cout << "Objective: Be the first player to align 5 of your symbols (X or O) in a row, column, or diagonal.";
        GotoXY(x + 3, y + 4 - 1); cout << "Players: Two players take turns placing their symbol (X or O) on the board.";
        GotoXY(x + 3, y + 6 - 1); cout << "The game ends when a player aligns 5 symbols consecutively.";
        GotoXY(x + 3, y + 8 - 1); cout << "If the board is full with no winner, the game is a draw.";
        GotoXY(x + 3, y + 10 - 1); cout << "Undo (Optional): Players can undo their last move";
        while (1) {
            if (_getch() == 27) printMenu();
        }
    }
    else {
        int x = menu1_x - 15, y = menu1_y, w = 103, h = 15;
        const int xRule = 50, yRule = 25;
        drawESC(130, 40);
        drawPinkBox(5, 2);
        huongdan(12, 4);
        int xTable = -5, yTable = 1;
        drawTable(xTable + 10, yTable + 25);
        DrawFull(x + 2, y - 2, w + 1, h, 136, 32);
        DrawFull(x, y - 3, w, h, 195, 197);
        DrawFull(x + 2, y - 2, w - 4, h - 2, 119, 32);
        int i = 2;
        GotoXY(xTable + 20, yTable + y);
        txtColor((15 << 4) | 0); cout << "Dieu khien: ";
        GotoXY(xTable + 15, yTable + y + 1 - 2 + i); cout << "W A S D: Di chuyen";
        GotoXY(xTable + 15, yTable + y + 2 - 1 + i); cout << "Enter: chon";
        GotoXY(xTable + 15, yTable + y + 8 - 1 + i); cout << "Nhan Esc de quay tro lai";
        GotoXY(xTable + 15, yTable + y + 4 - 1 + i); cout << "Esc: Dung game";
        GotoXY(xTable + 15, yTable + y + 6 + i - 1); cout << "U: quay lai nuoc di";
        txtColor((7 << 4) | 4);
        GotoXY(x + 30, y - 1); cout << " LUAT ";
        GotoXY(x + 3, y + 2 - 1); cout << "Muc tieu:Tro thanh nguoi dau tien danh duoc 5 dau X (O) lien tiep tren hang ngang, doc, cheo.";
        GotoXY(x + 3, y + 4 - 1); cout << "Nguoi choi:Hai nguoi choi lan luot dat bieu tuong X,O len bang.";
        GotoXY(x + 3, y + 6 - 1); cout << "Game ket thuc khi nguoi choi danh duoc 5 dau X(O)lien tiep.";
        GotoXY(x + 3, y + 8 - 1); cout << "Neu danh het bang khong ai thang, tro choi hoa.";
        GotoXY(x + 3, y + 10 - 1); cout << "Undo : Nguoi choi quay tro lai nuoc di.";
        while (1) {
            if (_getch() == 27) printMenu();
        }
    }

}
void Exit() {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    system("cls");
    system("color F0");
    if (curlang == 0) {
        drawPinkBox(30, 8);
        cha(1, 22);
        drawExit(65, 10);
        DrawFull(52, 28, 35, 7, 0, 219);
        Box(52, 28, 35, 7);
        drawtrueYes(60, 30);
        drawNo(110, 30, 0);
        int opt = 1;
        while (1) {
            char c = toupper(_getch());
            if (c == 'D' || c == 77) {
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                DrawFull(52, 28, 35, 7, 15, 219);
                txtColor((15 << 4) | 15);
                Box(52, 28, 35, 7);
                DrawFull(102, 28, 35, 7, 0, 219);
                Box(102, 28, 35, 7);
                drawNo(110, 30, 1);
                drawYes(60, 30);
                txtColor(7);
                opt = 0;
            }
            else if (c == 'A' || c == 75) {
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                opt = 1;
                DrawFull(102, 28, 35, 7, 15, 219);
                txtColor((15 << 4) | 15);
                Box(102, 28, 35, 7);
                txtColor(7);
                DrawFull(52, 28, 35, 7, 0, 219);
                Box(52, 28, 35, 7);
                drawNo(110, 30, 0);
                drawtrueYes(60, 30);
            }
            else if (c == 13) {
                if (opt == 1) {
                    system("cls");
                    exit(0);
                }
                else printMenu();
                break;
            }
        }
    }
    else {
        drawPinkBox(30, 8);
        cha(1, 22);
        thoat(65, 12);
        DrawFull(52, 30, 40, 12, 0, 219);
        Box(52, 30, 40, 12);
        co1(60, 30);
        drawkhong(110, 30, 0);
        int opt = 1;
        while (1) {
            char c = toupper(_getch());
            if (c == 'D' || c == 77) {
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                DrawFull(52, 30, 40, 12, 15, 219);
                txtColor((15 << 4) | 15);
                Box(52, 30, 40, 12);
                DrawFull(102, 30, 40, 12, 0, 219);
                Box(102, 30, 40, 12);
                drawkhong(110, 30, 1);
                co(60, 30);
                txtColor(7);
                opt = 0;
            }
            else if (c == 'A' || c == 75) {
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                opt = 1;
                DrawFull(102, 30, 40, 12, 15, 219);
                txtColor((15 << 4) | 15);
                Box(102, 30, 40, 12);
                txtColor(7);
                DrawFull(52, 30, 40, 12, 0, 219);
                Box(52, 30, 40, 12);
                drawkhong(110, 30, 0);
                co1(60, 30);
            }
            else if (c == 13) {
                if (opt == 1) {
                    system("cls");
                    exit(0);
                }
                else printMenu();
                break;
            }
        }
    }


}
void About() {
    system("cls");
    system("color F0");
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");


    drawSmallCloud(13, 25);
    drawBigCloud(21, 35);
    drawSmallCloud(134, 40);
    drawBigCloud(143, 25);
    drawPikachu(142, 2);
    if (curlang == 0) {
        drawPinkBox(5, 2);
        drawInformation(18, 6);
        int x = menu1_x - 12, y = menu1_y - 2, w = 50, h = 18;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 20, y + 1); cout << "Member:";
        GotoXY(x + 5, y + 3); cout << "1. MSSV: 24120306 - Nguyen Duy Hao";
        GotoXY(x + 5, y + 5); cout << "2. MSSV: 24120295 - Pham Xuan Duy";
        GotoXY(x + 5, y + 7); cout << "3. MSSV: 24120224 - Nguyen Anh Thai";
        GotoXY(x + 5, y + 9); cout << "4. MSSV: 24120289 - Nguyen Anh Duc";
        GotoXY(x + 5, y + 11); cout << "5. MSSV: 24120237 - Nguyen Dinh Tuan";
        GotoXY(x + 5, y + 13); cout << "GVDH: Truong Toan Thinh";
        GotoXY(x + 5, y + 15); cout << "Press Esc to turn back the main Menu...";
        while (1) {
            if (_getch() == 27) printMenu();
        }
    }
    else {
        drawPinkBox3(5, 2);
        thongtin(18, 6);
        int x = menu1_x - 12, y = menu1_y - 2, w = 50, h = 18;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 20, y + 1); cout << "THANH VIEN:";
        GotoXY(x + 5, y + 3); cout << "1. MSSV: 24120306 - Nguyen Duy Hao";
        GotoXY(x + 5, y + 5); cout << "2. MSSV: 24120295 - Pham Xuan Duy";
        GotoXY(x + 5, y + 7); cout << "3. MSSV: 24120224 - Nguyen Anh Thai";
        GotoXY(x + 5, y + 9); cout << "4. MSSV: 24120289 - Nguyen Anh Duc";
        GotoXY(x + 5, y + 11); cout << "5. MSSV: 24120237 - Nguyen Dinh Tuan";
        GotoXY(x + 5, y + 13); cout << "GVDH: Truong Toan Thinh";
        GotoXY(x + 5, y + 15); cout << "An ESC de quay lai menu...";
        while (1) {
            if (_getch() == 27) printMenu();
        }
    }

}
void Setting() {
    system("cls");
    system("color F0");
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    setg(140, 20);
    muiten(5, 37);
    int x = menu1_x - 15, y = menu1_y - 5, w = 50, h = 13;
    auto drawUI = [&](int lang) {
        DrawFull(x + 2, y - 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        if (lang == 0) {
            drawPinkBox(5, 2);
            Settingve(10, 6);
            GotoXY(x + 5, y + 2); cout << "MUSIC ";
            GotoXY(x + 5, y + 3); cout << "-----";
            GotoXY(x + 5, y + 5); cout << "F TO OFF MUSIC";
            GotoXY(x + 5, y + 6); cout << "O TO ON MUSIC";
            GotoXY(x + 5, y + 8); cout << "LANGUAGE ";
            GotoXY(x + 5, y + 9); cout << "--------";
            GotoXY(x + 5, y + 10); cout << "V. VIETNAMESE";
            GotoXY(x + 5, y + 11); cout << "E. ENGLISH";
        }
        else {
            drawPinkBox(5, 2);
            caidat(15, 4);
            GotoXY(x + 5, y + 2); cout << "AM NHAC ";
            GotoXY(x + 5, y + 3); cout << "------";
            GotoXY(x + 5, y + 5); cout << "F DE TAT NHAC";
            GotoXY(x + 5, y + 6); cout << "O DE BAT NHAC";
            GotoXY(x + 5, y + 8); cout << "NGON NGU ";
            GotoXY(x + 5, y + 9); cout << "--------";
            GotoXY(x + 5, y + 10); cout << "V. TIENG VIET";
            GotoXY(x + 5, y + 11); cout << "E. TIENG ANH";
        }
        };
    drawUI(curlang);
    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
    if (isMusicOn) {
        DrawFull(x + 16, y + 2, 12, 0, 10, 32);
        DrawFull(x + 27, y + 2, 1, 0, 136, 32);
    }
    else {
        DrawFull(x + 16, y + 2, 1, 0, 136, 32);
    }
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'F' || key == 'f') {
                if (isMusicOn) {
                    StopAllSounds();
                    isMusicOn = false;
                    DrawFull(x + 15, y + 1, 15, 3, 119, 32);
                    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
                    DrawFull(x + 16, y + 2, 1, 0, 136, 32);
                }
            }
            else if (key == 'O' || key == 'o') {
                if (!isMusicOn) {
                    PlayMusic("musicc.wav", L"music_bg");
                    isMusicOn = true;
                    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
                    DrawFull(x + 16, y + 2, 12, 0, 10, 32);
                    DrawFull(x + 27, y + 2, 1, 0, 136, 32);
                }
            }
            else if (key == 'V' || key == 'v') {
                curlang = 1;
                drawUI(curlang);

            }
            else if (key == 'E' || key == 'e') {
                curlang = 0;
                drawUI(curlang);
            }
            else if (key == 27) {
                printMenu();
                break;
            }
            DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
            if (isMusicOn) {
                DrawFull(x + 16, y + 2, 12, 0, 10, 32);
                DrawFull(x + 27, y + 2, 1, 0, 136, 32);
            }
            else {
                DrawFull(x + 16, y + 2, 1, 0, 136, 32);
            }
        }
    }
}


// ve chu caro
void drawCaro() {
    int xc = 68, yc = 5, cyan = 3, pink = 13;
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
        GotoXY(i, y); cout << char(219);
    }
    txtColor(116);
}
// ve turn x o
void DrawLine(char a[120], int x, int x2, int y2) {
    for (int j = 0; j < x; j++) {
        if (a[j] >= 48 && a[j] <= 57) DrawSquare(x2 + 2 * j, y2, a[j] - '0');
        if (a[j] >= 65 && a[j] <= 70) DrawSquare(x2 + 2 * j, y2, a[j] - 55);
    }
}
void DrawNotX(int x, int y) {
    char NotX[20][20] = { " 0000     0000 ",
                          "066660   066660",
                          "066660   066660",
                          "0666660 0666660",
                          "046666606666640",
                          "044666666666440",
                          "004466666664400",
                          " 0044EEEEE4400 ",
                          "  00666666600F ",
                          "  06666666660  ",
                          " 0666664666660 ",
                          "066666444666660",
                          "066664404466660",
                          "044444000444440",
                          "0444400 0044440",
                          "000000   000000" };
    for (int i = 0; i <= 15; i++) {
        DrawLine(NotX[i], 15, x, y);
        y++;
    }
}
void DrawIsX(int x, int y) {
    char IsX[20][20] = { " 8888     8888 ",
                          "8EEEE8   8EEEE8",
                          "8EEEE8   8EEEE8",
                          "8EEEEE8 8EEEEE8",
                          "8CEEEEE8EEEEEC8",
                          "8CCEEEEEEEEECC8",
                          "88CCEEEEEEECC88",
                          " 88CCCCCCCCC88 ",
                          "  88EEEEEEE88F ",
                          "  8EEEEEEEEE8  ",
                          " 8EEEEECEEEEE8 ",
                          "8EEEEECCCEEEEE8",
                          "8EEEECC8CCEEEE8",
                          "8CCCCC888CCCCC8",
                          "8CCCC88 88CCCC8",
                          "888888   888888" };
    for (int i = 0; i <= 15; i++) {
        DrawLine(IsX[i], 15, x, y);
        y++;
    }
}
void DrawNotO(int x, int y) {
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
    for (int i = 0; i <= 15; i++) {
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
    int x = BOARD_SIZE * 5 + LEFT - 1, y = TOP - 3, w = 75, h = 21;
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
    int x = BOARD_SIZE * 5 + LEFT - 1, y = TOP - 3, w = 74, h = 21;
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
    int x = BOARD_SIZE * 5 + LEFT - 1, y = TOP - 3, w = 75, h = 21;
    DrawFull(x - 4, y - 2, w, h, 240, 32);
    char draw[9][35] = {
        "33333  44444    111   CCC   CCC",
        "111133 4CCC44  11311  C4     4C",
        "31  13 4C  C4 113 311 C4     4C",
        "31  13 4C  C4 13   31 C4  4  4C",
        "31  13 4CCCC4 13   31 C4 444 4C",
        "31  13 4C4C4  1333331 C444C444C",
        "31  13 4C4CC4 1311131 C44C C44C",
        "111133 4C 4C4 13   31 C4C   C4C",
        "33333  44  44 11   11 CC     CC"
    };
    for (int i = 0; i < 9; i++) {
        DrawLine(draw[i], 34, x, y);
        y++;
    }
}
// new game
void NewGameSelection() {
    //khai bao bien
    const int time1 = 15, time2 = 30, time3 = -1;
    int opt = 1; //opt dau 3, la play
    int gamemode = 1; // 1pvp 2 pve
    int cnttime = 1; // 1: 15, -1 la inf
    int c;
    while (1)
    {

        c = toupper(_getch());
        if (c == 'W' || c == 72) {
            //xoa vi tri cu
            switch (opt) {
            case 1:
                drawNotmuiten(18, 5);
                break;
            case 2:
                drawNotmuiten(18, 5 + 14);
                break;
            case 3:
                drawNotmuiten(18, 5 + 14 + 16);
                break;
            }
            if (opt == 1)
            {
                opt = 3;
            }
            else {
                opt--;
            }
            switch (opt) {
            case 1:
                drawmuiten(18, 5);
                break;
            case 2:
                drawmuiten(18, 5 + 14);
                break;
            case 3:
                drawmuiten(18, 5 + 14 + 16);
                break;
            }
        }
        else if (c == 'S' || c == 80)
        {
            switch (opt)
            {
            case 1:
                drawNotmuiten(18, 5);
                break;
            case 2:
                drawNotmuiten(18, 5 + 14);
                break;
            case 3:
                drawNotmuiten(18, 5 + 14 + 16);
                break;
            }

            if (opt == 3)
            {
                opt = 1;
            }
            else {
                opt++;
            }
            switch (opt) {
            case 1:
                drawmuiten(18, 5);
                break;
            case 2:
                drawmuiten(18, 5 + 14);
                break;
            case 3:
                drawmuiten(18, 5 + 14 + 16);
                break;
            }
        }
        else if (c == 'A' || c == 75) {
            switch (opt) {
            case 1:
                switch (gamemode) {
                case 1:
                    drawNot(140, 8);
                    break;
                case 2:
                    drawNot(140, 8);
                    break;
                }
                if (gamemode == 1) gamemode = 2;
                else if (gamemode == 2) gamemode--;
                switch (gamemode) {
                case 1:
                    drawPvP(141, 8);
                    break;
                case 2:
                    drawPvE(141, 8);
                    break;
                }
                break;
            case 2:
                switch (cnttime) {
                case 1:
                    drawNot(139, 22);
                    break;
                case 2:
                    drawNot(139, 22);
                    break;
                case 3:
                    drawNot(141, 22);
                    break;
                }
                if (cnttime > 1) cnttime--;
                else if (cnttime == 1) cnttime = 3;
                switch (cnttime) {
                case 1:
                    draw15s(139, 22);
                    break;
                case 2:
                    draw30s(139, 22);
                    break;
                case 3:
                    drawInf(143, 22);
                    break;
                }
                break;
            }
        }
        else if (c == 'D' || c == 77) {
            switch (opt) {
            case 1:
                switch (gamemode) {
                case 1:
                    drawNot(140, 8);
                    break;
                case 2:
                    drawNot(140, 8);
                    break;
                }
                if (gamemode == 1) gamemode++;
                else if (gamemode == 2) gamemode = 1;
                switch (gamemode) {
                case 1:
                    drawPvP(141, 8);
                    break;
                case 2:
                    drawPvE(141, 8);
                    break;
                }
                break;
            case 2:
                switch (cnttime) {
                case 1:
                    drawNot(139, 22);
                    break;
                case 2:
                    drawNot(139, 22);
                    break;
                case 3:
                    drawNot(141, 22);
                    break;
                }
                if (cnttime < 3) cnttime++;
                else if (cnttime == 3) cnttime = 1;
                switch (cnttime) {
                case 1:
                    draw15s(139, 22);
                    break;
                case 2:
                    draw30s(139, 22);
                    break;
                case 3:
                    drawInf(143, 22);
                    break;
                }
                break;
            }
        }
        else if (c == 13)
        {

            if (opt == 3)
            {
                if (gamemode == 1)
                {
                    newGameOpt = 1;
                    playerName_withPlayer();
                    hideCursor();
                    switch (cnttime)
                    {
                    case 1:
                        StartGame(0, time1);
                        break;
                    case 2:
                        StartGame(0, time2);
                        break;
                    case 3:
                        StartGame(0, time3);
                        break;
                    }

                }
                else {
                    newGameOpt = -1;
                    playerName_withBot();
                    switch (cnttime)
                    {
                    case 1:
                        StartGamewithbot(0, time1);
                        break;
                    case 2:
                        StartGamewithbot(0, time2);
                        break;
                    case 3:
                        StartGamewithbot(0, time3);
                        break;
                    }

                }
            }
        }
        else if (c == 27)
        {
            printMenu();
            break;
        }
    }
}
void NewGame() {
    system("cls");
    system("color F0");
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    if (curlang == 0) {
        //giao dien
        drawmuiten(18, 5);
        DrawFull(36, 6, 88, 8, (11 << 4) | 15, 32);
        drawGameMode(44, 8);
        txtColor((15 << 4) | 0);
        Box(135, 6, 32, 8);
        Box(137, 7, 28, 6);
        drawPvP(141, 8);
        DrawFull(36, 20, 88, 8, (11 << 4) | 15, 32);
        drawCountdown(38, 22);
        txtColor((15 << 4) | 0);
        Box(135, 20, 32, 8);
        Box(137, 21, 28, 6);
        draw15s(139, 22);
        DrawFull(36, 36, 132, 8, (12 << 4) | 15, 32);
        drawPlay(88, 38);
        NewGameSelection();

    }
    else {
        //giao dien
        drawmuiten(18, 5);
        DrawFull(36, 4, 88, 12, (11 << 4) | 15, 32);
        demnguoc(44, 5);
        txtColor((15 << 4) | 0);
        Box(135, 6, 32, 8);
        Box(137, 7, 28, 6);
        drawPvP(141, 8);
        DrawFull(31, 20, 98, 12, (11 << 4) | 15, 32);
        tv(32, 21);
        txtColor((15 << 4) | 0);
        Box(135, 20, 32, 8);
        Box(137, 21, 28, 6);
        draw15s(139, 22);
        DrawFull(36, 36, 132, 9, (12 << 4) | 15, 32);
        choi(88, 37);
        NewGameSelection();

    }
   
}
void DrawRoundedBox(int x, int y, int width, int height, int color) {
    GotoXY(x, y); cout << char(201);
    for (int i = 1; i < width - 1; i++) cout << char(205);
    cout << char(187);
    for (int i = 1; i < height - 1; i++) {
        GotoXY(x, y + i); cout << char(186);
        GotoXY(x + width - 1, y + i); cout << char(186);
    }
    GotoXY(x, y + height - 1); cout << char(200);
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
void PauseMenu() {
    if (curlang == 0) {
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int x = menu1_x - 15, y = menu1_y - 12, w = 50, h = 20;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 23, y + 6); cout << "RESUME";
        GotoXY(x + 23, y + 8); cout << "RESTART";
        GotoXY(x + 24, y + 10); cout << "SAVE";
        GotoXY(x + 23, y + 12); cout << "SETTING";
        GotoXY(x + 24, y + 14); cout << "EXIT";
        txtColor((0 << 4) | 15);
        GotoXY(x + 23, y + 6); cout << "RESUME";
        int move, option = 1, check = 1;
        while (check == 1) {
            move = _getch();
            move = toupper(move);
            if (move == 80 || move == 'S') {
                txtColor(116);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "RESUME";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "RESTART";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "SAVE";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "SETTING";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "EXIT";
                    break;
                }
                if (option == 5) {
                    y = menu1_y - 12;
                    option = 1;
                }
                else {
                    y += 2;
                    option++;
                }
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "RESUME";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "RESTART";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "SAVE";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "SETTING";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "EXIT";
                    break;
                }
            }
            if (move == 72 || move == 'W') {
                txtColor(116);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "RESUME";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "RESTART";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "SAVE";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "SETTING";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "EXIT";
                    break;
                }
                if (option == 1) {
                    y = menu1_y - 12 + 8;
                    option = 5;
                }
                else {
                    y -= 2;
                    option--;
                }
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "RESUME";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "RESTART";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "SAVE";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "SETTING";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "EXIT";
                    break;
                }
            }
            hideCursor();
            if (move == 13) {
                PauseSelection(option);
                check = 0;
            }
        }
    }
    else {
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int x = menu1_x - 15, y = menu1_y - 12, w = 50, h = 20;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 23, y + 6); cout << "TIEP TUC";
        GotoXY(x + 23, y + 8); cout << "CHOI LAI";
        GotoXY(x + 24, y + 10); cout << "LUU";
        GotoXY(x + 23, y + 12); cout << "CAI DAT";
        GotoXY(x + 24, y + 14); cout << "THOAT";
        txtColor((0 << 4) | 15);
        GotoXY(x + 23, y + 6); cout << "TIEP TUC";
        int move, option = 1, check = 1;
        while (check == 1) {
            move = _getch();
            move = toupper(move);
            if (move == 80 || move == 'S') {
                txtColor(116);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "TIEP TUC";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "CHOI LAI";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "LUU";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "CAI DAT";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "THOAT";
                    break;
                }
                if (option == 5) {
                    y = menu1_y - 12;
                    option = 1;
                }
                else {
                    y += 2;
                    option++;
                }
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "TIEP TUC";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "CHOI LAI";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "LUU";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "CAI DAT";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "THOAT";
                    break;
                }
            }
            if (move == 72 || move == 'W') {
                txtColor(116);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "TIEP TUC";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "CHOI LAI";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "LUU";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "CAI DAT";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "THOAT";
                    break;
                }
                if (option == 1) {
                    y = menu1_y - 12 + 8;
                    option = 5;
                }
                else {
                    y -= 2;
                    option--;
                }
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                switch (option) {
                case 1:
                    GotoXY(x + 23, menu1_y - 12 + 6); cout << "TIEP TUC";
                    break;
                case 2:
                    GotoXY(x + 23, menu1_y - 12 + 8); cout << "CHOI LAI";
                    break;
                case 3:
                    GotoXY(x + 24, menu1_y - 12 + 10); cout << "LUU";
                    break;
                case 4:
                    GotoXY(x + 23, menu1_y - 12 + 12); cout << "CAI DAT";
                    break;
                case 5:
                    GotoXY(x + 24, menu1_y - 12 + 14); cout << "THOAT";
                    break;
                }
            }
            hideCursor();
            if (move == 13) {
                PauseSelection(option);
                check = 0;
            }
        }
    }
}
void PauseSelection(int option) {
    switch (option) {
    case 1:
        ResumeGame(optionGame);
        break;
    case 2:
        if (newGameOpt == 1) StartGame(1, pretime);
        else StartGamewithbot(1, pretime);
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
void duplicateNameMenu() {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4); cout << "NAME'S ALREADY EXISTS!";
    GotoXY(x + 5, y + 5);
    txtColor(112); cout << "Press Esc to go back.";
    txtColor(116);
}
void SaveSuccessMenu() {
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4); cout << "FILE HAS BEEN SAVED!";
    GotoXY(x + 5, y + 5);
    txtColor(112); cout << "Press Esc to go back.";
    txtColor(116);
}
void maxNumSFMenu() {
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 5, y + 4); cout << "MAX SAVE FILES REACH!";
    GotoXY(x + 5, y + 5);
    txtColor(112); cout << "Press Esc to go back.";
    txtColor(116);
}
void SettingPause() {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    int x = menu1_x - 15, y = menu1_y - 5, w = 50, h = 13;
    auto drawUI = [&](int lang) {
        DrawFull(x + 2, y - 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        if (lang == 0) {
            GotoXY(x + 5, y + 2); cout << "MUSIC ";
            GotoXY(x + 5, y + 3); cout << "-----";
            GotoXY(x + 5, y + 5); cout << "F TO OFF MUSIC";
            GotoXY(x + 5, y + 6); cout << "O TO ON MUSIC";
            GotoXY(x + 5, y + 8); cout << "LANGUAGE ";
            GotoXY(x + 5, y + 9); cout << "--------";
            GotoXY(x + 5, y + 10); cout << "V. VIETNAMESE";
            GotoXY(x + 5, y + 11); cout << "E. ENGLISH";
        }
        else {
            GotoXY(x + 5, y + 2); cout << "AM NHAC ";
            GotoXY(x + 5, y + 3); cout << "------";
            GotoXY(x + 5, y + 5); cout << "F DE TAT NHAC";
            GotoXY(x + 5, y + 6); cout << "O DE BAT NHAC";
            GotoXY(x + 5, y + 8); cout << "NGON NGU ";
            GotoXY(x + 5, y + 9); cout << "--------";
            GotoXY(x + 5, y + 10); cout << "V. TIENG VIET";
            GotoXY(x + 5, y + 11); cout << "E. TIENG ANH";
        }
        };
    drawUI(curlang);
    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
    if (isMusicOn) {
        DrawFull(x + 16, y + 2, 12, 0, 10, 32);
        DrawFull(x + 27, y + 2, 1, 0, 136, 32);
    }
    else {
        DrawFull(x + 16, y + 2, 1, 0, 136, 32);
    }
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'F' || key == 'f') {
                if (isMusicOn) {
                    StopAllSounds();
                    isMusicOn = false;
                    DrawFull(x + 15, y + 1, 15, 3, 119, 32);
                    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
                    DrawFull(x + 16, y + 2, 1, 0, 136, 32);
                }
            }
            else if (key == 'O' || key == 'o') {
                if (!isMusicOn) {
                    PlayMusic("musicc.wav", L"music_bg");
                    isMusicOn = true;
                    DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
                    DrawFull(x + 16, y + 2, 12, 0, 10, 32);
                    DrawFull(x + 27, y + 2, 1, 0, 136, 32);
                }
            }
            else if (key == 'V' || key == 'v') {
                curlang = 1;
                drawUI(curlang);
            }
            else if (key == 'E' || key == 'e') {
                curlang = 0;
                drawUI(curlang);
            }
            else if (key == 27) {
                PauseMenu();
                break;
            }
            DrawRoundedBox(x + 15, y + 1, 15, 3, 10);
            if (isMusicOn) {
                DrawFull(x + 16, y + 2, 12, 0, 10, 32);
                DrawFull(x + 27, y + 2, 1, 0, 136, 32);
            }
            else {
                DrawFull(x + 16, y + 2, 1, 0, 136, 32);
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
    " 0CCCCCCCC0    04FFF0",
    "0CCCC 0CCC0    0FF1C0",
    "0CCCC00CCCC0   0F11C0",
    "0CCCC00CCCC0    0100 ",
    " 0CCCCCCCCCC0   0C0  ",
    "  00CCCCCCCCC0 0CC0  ",
    "    000CC0CCC00CC0   ",
    "     0EE0CCCCC0CC0   ",
    "     0EEE00CCC0C0    ",
    "    0F0EEECCCC00     ",
    "     000EECCC00      ",
    "        000CC0       ",
    "         0FCF0       ",
    "          0000       " };
    for (int i = 0; i <= 18; i++) {
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
        " 0AAA2AA22AA20FF0   ",
        "0AAA2AAA2A2A2000B0  ",
        "0AA2AAAAA22200BBB0  ",
        "02A2AAAAA2203BBBB0  ",
        " 022AAA2000B33B3BB0 ",
        " 0000A220BBBBBBBB300",
        " 033300030BBB3BBB300",
        " 0F3033333B33B3BBBB0",
        "  00033033FF40BBBBB0",
        "     033033F403BBB0 ",
        "     0333033333300  ",
        "     0F3F0000000    ",
        "      000           "
    };
    for (int i = 0; i <= 17; i++) {
        DrawLine(poke[i], 20, x, y);
        y++;
    }
}
void drawTable(int x, int y) {
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
    for (int i = 0; i <= 21; i++) {
        DrawLine(table[i], 25, x, y);
        y++;
    }
}
void drawHowtoPlay(int x, int y) {
    char howtoPlay[5][63] = {
        "F  F   FF   F   F    FFFFF   FF     FFFF   F      FFFF   F   F",
        "F  F  F  F  F F F      F    F  F    F   F  F     F    F  F   F",
        "FFFF  F  F  F F F      F    F  F    F   F  F     FFFFFF   F F ",
        "F  F  F  F  F F F      F    F  F    FFFF   F     F    F    F  ",
        "F  F   FF    F F       F     FF     F      FFFF  F    F    F  " };
    for (int i = 0; i <= 4; i++) {
        DrawLine(howtoPlay[i], 63, x, y);
        y++;
    }
}
void drawPinkBox(int x, int y) {
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
    for (int i = 0; i < 13; i++) {
        DrawLine(pinkBox[i], 67, x, y);
        y++;
    }
}
void drawPauseBox(int x, int y) {
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
    for (int i = 0; i < 15; i++) {
        DrawLine(pauseBox[i], 19, x, y);
        y++;
    }
}
void drawESC(int x, int y) {
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
    for (int i = 0; i < 8; i++) {
        DrawLine(esc[i], 27, x, y);
        y++;
    }
}
void drawExit(int x, int y) {
    char Exit[9][33] = {
        " 0000   00   00  000    00000  ",
        " 0000   F00 0F0  0F00  0FFFFF00",
        "0FFFF0  F0000F0  0F00  000F0000",
        "0F0000  0F00F00  0F00   00F0000",
        "0F0000  00FF000  0F00    0F00  ",
        "0FFFF0  0F00F00  0F00    0F00  ",
        "0F0000  F0000F0  0F00    0F00  ",
        "0FFFF0  F00 0F0  0000    0000  ",
        " 0000   00   00   000     000  ",
    };
    for (int i = 0; i < 9; i++) {
        DrawLine(Exit[i], 33, x, y);
        y++;
    }
    DrawFull(x + 16, y - 8, 0, 1, 0, 219);
    DrawFull(x + 16, y - 3, 0, 1, 0, 219);
    DrawFull(x + 18, y - 8, 0, 1, 15, 219);
    DrawFull(x + 18, y - 3, 0, 1, 15, 219);
}
void drawY(int x, int y) {
    char Y[5][4] = {
        "8 8",
        "8 8",
        " 8 ",
        " 8 ",
        " 8 "
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(Y[i], 4, x, y);
        y++;
    }
}
void drawE(int x, int y) {
    char E[5][4] = {
        "88 ",
        "8 ",
        "88",
        "8",
        "88"
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(E[i], 4, x, y);
        y++;
    }
}
void drawS(int x, int y) {
    char S[5][5] = {
        " 88",
        "8  ",
        " 88",
        "   8",
        " 88"
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(S[i], 5, x, y);
        y++;
    }
}
void drawYes(int x, int y) {
    drawY(x, y);
    drawE(x + 7, y);
    drawS(x + 12, y);
}
void drawtrueY(int x, int y) {
    char Y[5][4] = {
        "4 4",
        "4 4",
        " 4 ",
        " 4 ",
        " 4 "
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(Y[i], 4, x, y);
        y++;
    }
}
void drawtrueE(int x, int y) {
    char E[5][4] = {
        "44 ",
        "4 ",
        "44",
        "4",
        "44"
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(E[i], 4, x, y);
        y++;
    }
}
void drawtrueS(int x, int y) {
    char S[5][5] = {
        " 44",
        "4  ",
        " 44",
        "   4",
        " 44"
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(S[i], 5, x, y);
        y++;
    }
}
void drawtrueYes(int x, int y) {
    drawtrueY(x, y);
    drawtrueE(x + 7, y);
    drawtrueS(x + 12, y);
}
void drawNo(int x, int y) {
    char no[5][12] = {
        "8  8   88 ",
        "88 8  8888 ",
        "8 88  8888 ",
        "8  8  8888",
        "8  8   88 ",
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(no[i], 12, x, y);
        y++;
    }
}
void drawtrueno(int x, int y) {
    char no[5][12] = {
        "4  4   44 ",
        "44 4  4444 ",
        "4 44  4444 ",
        "4  4  4444",
        "4  4   44 ",
    };
    for (int i = 0; i < 5; i++) {
        DrawLine(no[i], 12, x, y);
        y++;
    }
}
void drawNo(int x, int y, int choose) {
    if (choose == 1) drawtrueno(x, y);
    else drawNo(x, y);
}
void cha(int x, int y) {
    char poke[40][40] = {
        "                    00      ",
        "                    0D0     ",
        "                   0DD0     ",
        "                   0DCC0    ",
        "                   0DCEC0   ",
        "          0      0  0EEC0   ",
        "         0C0    0C0 0C00",
        "         0C0    0C00CC0",
        "         0C000000C04C00",
        "         0CC0  0CC04C0",
        "      00 0CCCCCCCC0400",
        "    00C0 0CCCCCCCC040C00",
        "   0CCC00C7CCCCCC7C00CCC0",
        "  0C99940C79CCCC97C04999C0",
        " 0C999940CC0CCCC0CC049999C0",
        " 0C9999940CCCCCCCC0499999C0",
        "0CC99999904CCCCCC40999999CC0",
        "0C9999990404CCCC4040999999C0",
        "000999990C40444404C099999000",
        "    99 0CC04000040CC0  99   ",
        "       0700C4444C0070",
        "      04040CCCCCC04040",
        "      04440CCEECC04440",
        "      0CCC0CEEEEC0CCC0",
        "       0CCC0EEEE04CC0",
        "       07C70000007C70",
        "        000      000",
    };
    for (int i = 0; i <= 25; i++) {
        DrawLine(poke[i], 40, x, y);
        y++;
    }
}
void Settingve(int x, int y) {
    char howtoPlay[5][63] = {
        "     FFFF  FFFF  FFFFF  FFFFF  F  FFF  FFF  FFFFF",
        "     F     F       F      F    F  F  F   F  F    ",
        "     FFFF  FFFF    F      F    F  F   F  F  F FFF",
        "        F  F       F      F    F  F    F F  F   F",
        "     FFFF  FFFF    F      F    F  F     FF  FFFFF" };
    for (int i = 0; i <= 4; i++) {
        DrawLine(howtoPlay[i], 63, x, y);
        y++;
    }
}
void setg(int x, int y) {
    char poke[40][40] = {
        "       000000      ",
        "  00   088880  00",
        " 08800088888000880",
        " 088888888888888880",
        " 088888000000888880",
        "  08800      00880",
        " 0880          0880",
        "00880    00    08800",
        "08880   0  0   08880",
        "08880  0  880  08880",
        "08880  0 8880  08880",
        "08880   0880   08880",
        "00880    00    08800",
        "  0880        0880",
        "   08800    00880",
        "  0888880000888880",
        " 088880888888088880",
        "  0880 088880 0880",
        "   00   0880   00",
        "        0000",
    };
    for (int i = 0; i <= 25; i++) {
        DrawLine(poke[i], 30, x, y);
        y++;
    }
}
void muiten(int x, int y) {
    char poke[40][40] = {
        "    BB     ",
        "   BBB     ",
        "  BBBBBBBBBBBBBBBBB",
        " BBBBBCCBCCBCCBBBBB",
        "BBBBBBCBBCBBCBBBBBB",
        "BBBBBBCCBCCBCBBBBBB",
        "BBBBBBCBBBCBCBBBBBB",
        "BBBBBBCCBCCBCCBBBBB",
        " 9BBBBBBBBBBBBBBBBB",
        "  9BBB9999999999999",
        "   9BB9    ",
        "    99     ",
    };
    for (int i = 0; i <= 25; i++) {
        DrawLine(poke[i], 30, x, y);
        y++;
    }
}
void drawPinkBox2(int x, int y) {
    char pinkBox[13][90] = {
        "   0000000000000000000000000000000000000000000000000000000000000000000000   ",
        "  0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0  ",
        " 0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0 ",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        " 0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0 ",
        "  0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0  ",
        "   0000000000000000000000000000000000000000000000000000000000000000000000   " };
    for (int i = 0; i < 13; i++) {
        DrawLine(pinkBox[i], 90, x, y);
        y++;
    }
}
void load(int x, int y) {
    char load[15][80] = {
          "F       FF      FF     FFF       FFFF    FF    FF      FF  FFFFF",
          "F     FF  FF   F  F    F  F      F      F  F   F F    F F  F",
          "F     F    F   FFFF    F   F     F FF   FFFF   F  F  F  F  FFFFF",
          "F     FF  FF  F    F   F  F      F  F  F    F  F   FF   F  F",
          "FFFF    FF    F    F   FFF       FFFF  F    F  F        F  FFFFF" };
    for (int i = 0; i <= 4; i++) {
        DrawLine(load[i], 63, x, y);
        y++;
    }
}
void des(int x, int y) {
    char poke[40][40] = {
        "         00000      ",
        "        0222220     ",
        "       022222220",
        "      0222222222000 ",
        "   0  02226622222220",
        "  0200022666622222E0",
        "  020202267C722EEE0",
        "00022200227C7EEEE0",
        "0202220 02EEEEE00",
        "022260 0662EE00",
        "02226006626EE020",
        " 02226002220EE00",
        "  0022222200EE0",
        "    0222222EEE0",
        "     02222EEEE0",
        "      022EE0E0",
        "       00E0 00",
        "         00",
    };
    for (int i = 0; i <= 25; i++) {
        DrawLine(poke[i], 30, x, y);
        y++;
    }
}
void drawBigCloud(int x, int y) {
    char cloud[26][26] = {
        "           000           ",
        "          07770          ",
        "     000 0777770 00      ",
        "   00777077777770770     ",
        "  07777777777777777700   ",
        " 0777777777777777777770  ",
        " 07777777777777777777770 ",
        "0777777777777777777777770",
        "0777777777777777777777770",
        " 00000000000000000000000 "
    };
    for (int i = 0; i < 10; i++) {
        DrawLine(cloud[i], 25, x, y);
        y++;
    }
}
void drawSmallCloud(int x, int y) {
    char cloud[14][14] = {
        "      00     ",
        "   0 0770    ",
        "  070777700  ",
        " 07777777770 ",
        "0777777777770",
        " 00000000000 ",
    };
    for (int i = 0; i < 6; i++) {
        DrawLine(cloud[i], 13, x, y);
        y++;
    }
}
void drawInformation(int x, int y) {
    char information[5][54] = {
        "FFF F   F FFF  FF  FFF  F   F  FF  FFF FFF  FF  F   F",
        " F  FF  F F   F  F F  F FF FF F  F  F   F  F  F FF  F",
        " F  F F F FF  F  F FFF  F F F FFFF  F   F  F  F F F F",
        " F  F  FF F   F  F F  F F   F F  F  F   F  F  F F  FF",
        "FFF F   F F    FF  F  F F   F F  F  F  FFF  FF  F   F"
    };
    for (int i = 0; i <= 4; i++) {
        DrawLine(information[i], 53, x, y);
        y++;
    }
}
void inputname(int x, int y, char name[]) {
    GotoXY(x, y);
    int i = 0;
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) printMenu();
            else if (key == '\r') {
                name[i] = '\0';
                break;
            }
            else if (key == '\b') {
                if (i > 0) {
                    i--;
                    cout << "\b \b";
                }
            }
            else if (i < MAX_FILE_LENGTH - 2) {
                txtColor(15 * 16); cout << key;
                txtColor(15 * 16); name[i++] = key;
            }
            if (key == 13) break;
        }
    }
    if (!isValidName(name)) {
        i = 0;
        GotoXY(x - 1, y); cout << "  Invalid input!";
        Sleep(2000);
        GotoXY(x - 1, y); cout << "                ";
        GotoXY(x, y);
        inputname(x, y, name);
    }
}
void playerName_withPlayer() {
    if (curlang == 0) {
        showCursor();
        int x = menu1_x - 20, y = menu1_y - 20;
        DrawFull(x - 8, y - 3, 75, 44, 4 * 16, 32);
        DrawFull(x - 6, y - 2, 71, 42, 15 * 16, 32);
        drawPlayername(x, y);
        DrawFull(x, y, 59, 0, 3 * 16, 32);
        DrawFull(x, y + 15, 59, 0, 3 * 16, 32);
        DrawIsX(x, y + 23);
        DrawIsO(x + 34, y + 23);
        txtColor(15 * 16 + 4);
        GotoXY(x + 8, y + 17); cout << "PLAYER NAME X";
        Box(x + 4, y + 18, 20, 2);
        GotoXY(x + 40, y + 17);
        txtColor(15 * 16 + 1); cout << "PLAYER NAME O";
        Box(x + 36, y + 18, 20, 2);
        txtColor(15 * 16);
        GotoXY(x + 16, y + 21); cout << "    ( <=  13 characters )";
        inputname(x + 6, y + 19, name1);
        inputname(x + 38, y + 19, name2);
    }
    else {

        showCursor();
        int x = menu1_x - 20, y = menu1_y - 20;
        DrawFull(x - 8, y - 3, 75, 44, 4 * 16, 32);
        DrawFull(x - 6, y - 2, 71, 42, 15 * 16, 32);
        datten(x, y);
        DrawFull(x, y, 59, 0, 3 * 16, 32);
        DrawFull(x, y + 15, 59, 0, 3 * 16, 32);
        DrawIsX(x, y + 23);
        DrawIsO(x + 34, y + 23);
        txtColor(15 * 16 + 4);
        GotoXY(x + 8, y + 17); cout << "TEN NGUOI CHOI X";
        Box(x + 4, y + 18, 20, 2);
        GotoXY(x + 40, y + 17);
        txtColor(15 * 16 + 1); cout << "TEN NGUOI CHOI O";
        Box(x + 36, y + 18, 20, 2);
        txtColor(15 * 16);
        GotoXY(x + 16, y + 21); cout << "    ( <=  13 Ky tu )";
        inputname(x + 6, y + 19, name1);
        inputname(x + 38, y + 19, name2);
    }

}
void playerName_withBot() {
    if (curlang == 0) {
        showCursor();
        int x = menu1_x - 20, y = menu1_y - 20;
        DrawFull(x - 8, y - 3, 75, 44, 4 * 16, 32);
        DrawFull(x - 6, y - 2, 71, 42, 15 * 16, 32);
        drawPlayername(x, y);
        DrawFull(x, y, 59, 0, 3 * 16, 32);
        DrawFull(x, y + 15, 59, 0, 3 * 16, 32);
        DrawIsX(x, y + 23);
        DrawIsO(x + 34, y + 23);
        txtColor(15 * 16 + 4);
        GotoXY(x + 8, y + 17); cout << "PLAYER NAME X";
        Box(x + 4, y + 18, 20, 2);
        GotoXY(x + 40, y + 17);
        txtColor(15 * 16 + 1); cout << "PLAYER NAME O";
        Box(x + 36, y + 18, 20, 2);
        txtColor(15 * 16);
        GotoXY(x + 16, y + 21); cout << "    ( <=  13 characters )";
        inputname(x + 6, y + 19, name1);
        strcpy(name2, "Robot");
    }
    else {
        showCursor();
        int x = menu1_x - 20, y = menu1_y - 20;
        DrawFull(x - 8, y - 3, 75, 44, 4 * 16, 32);
        DrawFull(x - 6, y - 2, 71, 42, 15 * 16, 32);
        datten(x, y);
        DrawFull(x, y, 59, 0, 3 * 16, 32);
        DrawFull(x, y + 15, 59, 0, 3 * 16, 32);
        DrawIsX(x, y + 23);
        DrawIsO(x + 34, y + 23);
        txtColor(15 * 16 + 4);
        GotoXY(x + 8, y + 17); cout << "Ten nguoi choi X";
        Box(x + 4, y + 18, 20, 2);
        GotoXY(x + 40, y + 17);
        txtColor(15 * 16 + 1); cout << "Ten may O";
        Box(x + 36, y + 18, 20, 2);
        txtColor(15 * 16);
        GotoXY(x + 16, y + 21); cout << "    ( <=  13 ky tu )";
        inputname(x + 6, y + 19, name1);
        strcpy(name2, "Robot");
    }

}
void drawPlayername(int x, int y) {
    char Playername[16][31] = {
        "111111111111111111111111111111",
        "                              ",
        "  444  4    44  4 4 444 444   ",
        "  4  4 4   4  4 4 4 4   4  4  ",
        "  4  4 4   4  4 444 444 4  4  ",
        "  444  4   4444   4 4   444   ",
        "  4    444 4  4 444 444 4  4  ",
        "                              ",
        "                              ",
        "     4  4  44  4   4 444      ",
        "     44 4 4  4 44 44 4        ",
        "     4 44 4  4 4 4 4 444      ",
        "     4  4 4444 4   4 4        ",
        "     4  4 4  4 4   4 444      ",
        "                              ",
        "111111111111111111111111111111",
    };
    for (int i = 0; i < 16; i++) {
        DrawLine(Playername[i], 31, x, y);
        y++;
    }
}
void drawPikachu2(int x, int y) {
    char pika[20][20] = {
        "            000    ",
        "          004480   ",
        "         04448FF0  ",
        "        04448F22F0 ",
        "     0000448FF2FF0 ",
        "    06EF0488FFF2F0 ",
        "     0000000488FF0 ",
        "       0EEE0044880 ",
        "   0   0E0FEE04440 ",
        "  0E0 00E00E0E00000",
        "  0EE0044EEEEEEE440",
        "  0E6E004EEE0EEE400",
        "  0EE0E0EEFEEEFEE0 ",
        "   00E60181FEF1810 ",
        "     E0EF0B221B0FE0",
        "     00E0BB1A1BB0E0",
        "      001BB1A1BB100",
        "       0011E0E1100 ",
        "      0EF000 000FE0",
        "       000     000 "
    };
    for (int i = 0; i < 20; i++) {
        DrawLine(pika[i], 20, x, y);
        y++;
    }
}
void drawcharG(int x, int y)
{
    char G[5][4] = {
        "000",
        "0  ",
        "0  ",
        "0 0",
        "000"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(G[i], 3, x, y);
        y++;
    }
}
void drawcharA(int x, int y)
{
    char A[5][5] = {
        " 0 ",
        "0 0",
        "000",
        "0 0",
        "0 0"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(A[i], 3, x, y);
        y++;
    }
}
void drawcharM(int x, int y)
{
    const int r = 5;
    char M[r][6] = {
        " 0 0 ",
        "0 0 0",
        "0   0",
        "0   0",
        "0   0"

    };
    for (int i = 0; i < r; i++)
    {
        DrawLine(M[i], 6, x, y);
        y++;
    }
}
void drawcharE(int x, int y)
{
    const int row = 5;
    const int col = 3;
    char E[row][col] = {
        "00",
        "0",
        "00",
        "0",
        "00"


    };
    for (int i = 0; i < row; i++)
    {
        DrawLine(E[i], col, x, y);
        y++;
    }
}
void drawcharO(int x, int y)
{
    char O[5][5] = {
        " 00 ",
        "0  0",
        "0  0",
        "0  0",
        " 00 "

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(O[i], 5, x, y);
        y++;
    }
}
void drawcharD(int x, int y)
{
    char Y[5][5] = {
        "00  ",
        "0 0 ",
        "0 0 ",
        "0 0 ",
        "00 "

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(Y[i], 5, x, y);
        y++;

    }
}
void drawGameMode(int x, int y)
{
    drawcharG(x, y);
    drawcharA(x + 8, y);
    drawcharM(x + 8 + 8, y);
    drawcharE(x + 8 + 8 + 12, y);
    const int xMode = x + 8 + 8 + 12 + 5 + 4;
    drawcharM(xMode + 2, y);
    drawcharO(xMode + 2 + 12, y);
    drawcharD(xMode + 2 + 12 + 10, y);
    drawcharE(xMode + 2 + 12 + 10 + 8, y);
}

void drawcharN(int x, int y)
{
    char N[5][5] = {
        "0  0",
        "00 0",
        "0 00",
        "0  0",
        "0  0"
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(N[i], 5, x, y);
        y++;
    }
}
void drawcharU(int x, int y)
{
    char U[5][5] = {
        "0  0",
        "0  0",
        "0  0",
        "0  0",
        "0000"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(U[i], 5, x, y);
        y++;
    }
}
void drawcharC(int x, int y)
{
    char C[5][4] = {
        " 00",
        "0",
        "0",
        "0",
        " 00"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(C[i], 4, x, y);
        y++;
    }
}
void drawcharT(int x, int y)
{
    char T[5][5] = {
        "000",
        " 0",
        " 0",
        " 0",
        " 0"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(T[i], 4, x, y);
        y++;
    }
}
void drawcharW(int x, int y)
{
    char W[5][6] = {
        "0   0",
        "0   0",
        "0 0 0",
        "0 0 0",
        " 0 0 ",

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(W[i], 6, x, y);
        y++;
    }

}

void drawCountdown(int x, int y) {
    char count[5][43] = {
        " 00  00  0  0 0  0 000 00   00  0   0 0  0",
        "0   0  0 0  0 00 0  0  0 0 0  0 0   0 00 0",
        "0   0  0 0  0 0 00  0  0 0 0  0 0 0 0 0 00",
        "0   0  0 0  0 0  0  0  0 0 0  0 0 0 0 0  0",
        " 00  00  0000 0  0  0  00   00   0 0  0  0"
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(count[i], 42, x, y);
        y++;
    }
}

void drawcharsmallL(int x, int y)
{
    char L[5][2] = {
        "0",
        "0",
        "0",
        "0",
        "0"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(L[i], 2, x, y);
        y++;
    }
}
void drawcharsmallA(int x, int y)
{
    char a[5][6] = {
        "    ",
        " 0000",
        "0   0",
        "0   0",
        " 0000"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(a[i], 6, x, y);
        y++;
    }
}
void drawcharsmallY(int x, int y)
{
    char smally[7][5] = {
        "    ",
        "0  0",
        "0  0",
        "0  0",
        " 000",
        "   0",
        " 00"

    };
    for (int i = 0; i < 7; i++)
    {
        DrawLine(smally[i], 5, x, y);
        y++;
    }
}

void drawcharP(int x, int y)
{
    char P[5][4] = {
        "000",
        "0 0",
        "000",
        "0",
        "0"

    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(P[i], 4, x, y);
        y++;
    }
}
void drawcharsmallV(int x, int y)
{
    char v[2][4] = {
        "0 0",
        " 0"
    };
    for (int i = 0; i < 2; i++)
    {
        DrawLine(v[i], 4, x, y);
        y++;
    }
}

void draw15s(int x, int y) {
    char fif[5][13] = {
        "00 0000     ",
        " 0 0     000",
        " 0  000 00  ",
        " 0    0   00",
        " 0 000  000 "
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(fif[i], 12, x, y);
        y++;
    }
}

void draw30s(int x, int y) {
    char ba[5][13] = {
        "000  0      ",
        "  0 0 0  000",
        " 00 0 0 00  ",
        "  0 0 0   00",
        "000  0  000 "
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(ba[i], 12, x, y);
        y++;
    }
}

void drawInf(int x, int y) {
    char inf[5][10] = {
        " 00   00 ",
        "0  0 0  0",
        "0   0   0",
        "0  0 0  0",
        " 00   00 "
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(inf[i], 9, x, y);
        y++;
    }
}

void drawmuiten(int x, int y) {
    char muiten[11][7] = {
        "0     ",
        "00    ",
        "0 0   ",
        "0  0  ",
        "0   0 ",
        "0    0",
        "0   0 ",
        "0  0  ",
        "0 0   ",
        "00    ",
        "0     "
    };
    for (int i = 0; i < 11; i++)
    {
        DrawLine(muiten[i], 6, x, y);
        y++;
    }
}
void drawPlay(int x, int y) {
    drawcharP(x, y);
    drawcharsmallL(x + 7, y);
    drawcharsmallA(x + 7 + 3, y);
    drawcharsmallY(x + 7 + +4 + 11, y);
}

void drawPvP(int x, int y) {
    drawcharP(x, y);
    drawcharsmallV(x + 8, y + 3);
    drawcharP(x + 8 + 8, y);
}

void drawPvE(int x, int y) {
    drawcharP(x, y);
    drawcharsmallV(x + 8, y + 3);
    drawcharE(x + 8 + 8, y);
}

void drawNotmuiten(int x, int y) {
    char notmuiten[11][7] = {
        "F     ",
        "FF    ",
        "F F   ",
        "F  F  ",
        "F   F ",
        "F    F",
        "F   F ",
        "F  F  ",
        "F F   ",
        "FF    ",
        "F     "
    };
    for (int i = 0; i < 11; i++)
    {
        DrawLine(notmuiten[i], 6, x, y);
        y++;
    }
}

void drawNot(int x, int y) {
    char nott[5][13] = {
        "FFFFFFFFFFFF",
        "FFFFFFFFFFFF",
        "FFFFFFFFFFFF",
        "FFFFFFFFFFFF",
        "FFFFFFFFFFFF",
    };
    for (int i = 0; i < 5; i++)
    {
        DrawLine(nott[i], 13, x, y);
        y++;
    }
}
void drawPinkBox3(int x, int y) {
    char pinkBox[19][67] = {
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
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        "0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0",
        " 0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0 ",
        "  0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0  ",
        "   000000000000000000000000000000000000000000000000000000000000   " };
    for (int i = 0; i < 19; i++) {
        DrawLine(pinkBox[i], 67, x, y);
        y++;
    }
}
void huongdan(int x, int y) {
    char how[7][63] = {
        "           FA                              ",
        "          FA                               FFA  ",
        "                                            FA",
        "FFFFA   FF    FFFF  FA FA   FFFF  FA FA FFFFA FA",
        "FA     FA F   FA    FA FA   FA    FA FA FA FA FA",
        "FA     FFFF   FA    FFFFA   FA    FFFFA FA FA FA",
        "FFFFA FFA FF  FFFFA FA FA   FFFFA FA FA FFFFA FA" };
    for (int i = 0; i <= 6; i++) {
        DrawLine(how[i], 63, x, y);
        y++;
    }
}
void thoat(int x, int y) {
    char Play2[12][63] = {
        "                        FC",
        "                               ",
        "FFFFFC FC FC  FFFFC     FC   FFFFFC ",
        "  FC   FC FC  FC FC    FCFC    FC",
        "  FC   FFFFC  FC FC   FFFFFC   FC",
        "  FC   FC FC  FC FC   FC  FC   FC",
        "  FC   FC FC  FFFFC  FFC  FFC  FC" };
    for (int i = 0; i <= 11; i++) {
        DrawLine(Play2[i], 63, x, y);
        y++;
    }
}
void khong(int x, int y) {
    char no[8][30] = {
        "            8",
        "           8 8",
        "",
        "8  8  8 8  888  8  8  888",
        "8 8   8 8  8 8  88 8  8",
        "88    888  8 8  8 88  8 8",
        "8 8   8 8  8 8  8  8  8 8",
        "8  8  8 8  888  8  8  888",
    };
    for (int i = 0; i < 8; i++) {
        DrawLine(no[i], 30, x, y);
        y++;
    }
}
void khong1(int x, int y) {
    char no[8][30] = {
        "            4",
        "           4 4",
        "",
        "4  4  4 4  444  4  4  444",
        "4 4   4 4  4 4  44 4  4",
        "44    444  4 4  4 44  4 4",
        "4 4   4 4  4 4  4  4  4 4",
        "4  4  4 4  444  4  4  444",
    };
    for (int i = 0; i < 8; i++) {
        DrawLine(no[i], 30, x, y);
        y++;
    }
}
void drawkhong(int x, int y, int choose) {
    if (choose == 1) khong1(x, y);
    else khong(x, y);
}
void co(int x, int y) {
    char no[8][30] = {
        "         8",
        "        8",
        "",
        "88888 88888",
        "8     8   8",
        "8     8   8 ",
        "8     8   8",
        "88888 88888",
    };
    for (int i = 0; i < 8; i++) {
        DrawLine(no[i], 30, x, y);
        y++;
    }
}
void drawco(int x, int y, int choose) {
    if (choose == 1) co1(x, y);
    else co(x, y);
}
void co1(int x, int y) {
    char no[8][30] = {
        "         4",
        "        4",
        "",
        "44444 44444",
        "4     4   4",
        "4     4   4 ",
        "4     4   4",
        "44444 44444",
    };
    for (int i = 0; i < 8; i++) {
        DrawLine(no[i], 30, x, y);
        y++;
    }
}
void caidat(int x, int y) {
    char howto[9][63] = {
        "         FFA                   FFFFA   ",
        "                                       ",
        "FFFFA    FF     FA   FFFF      FF    FFFFFA",
        "FA      FA F    FA   FA  F    FA F     FA",
        "FA     FFFFFF   FA   FFA FF  FFFFFF    FA",
        "FA     FA   F   FA   FA  F   FA   F    FA",
        "FFFFA FFA   FF  FA   FFFF   FFA   FF   FA",
        "",
        "                               FFA       " };
    for (int i = 0; i <= 8; i++) {
        DrawLine(howto[i], 63, x, y);
        y++;
    }
}
void taigame(int x, int y) {
    char loa[15][50] = {
          "         FFA",
          "          FA",
          "          ",
          "FFFFFA   FF     FA",
          "  FA    FA F    FA",
          "  FA   FAFFFF   FA",
          "  FA  FFA   FF  FA" };
    for (int i = 0; i <= 14; i++) {
        DrawLine(loa[i], 50, x, y);
        y++;
    }
}
void thongtin(int x, int y) {
    char inf[8][54] = {
        "               FE                                ",
        "              FE F                                ",
        "                                                ",
        "FFFFFE FE FE  FFFFE F   FE  FFFFE  FFFFFE  FE  F   FE",
        "  FE   FE FE  FE FE FF  FE  FE       FE    FE  FF  FE",
        "  FE   FFFFE  FE FE FEF FE  FEFFE    FE    FE  FEF FE",
        "  FE   FE FE  FE FE FE FFE  FE FE    FE    FE  FE FFE",
        "  FE   FE FE  FFFFE FE  FE  FFFFE    FE    FE  FE  FE"
    };
    for (int i = 0; i <= 7; i++) {
        DrawLine(inf[i], 54, x, y);
        y++;
    }
}
void datten(int x, int y) {
    char Playername[17][32] = {
        "111111111111111111111111111111",
        "",
        "              4C",
        "             4C 4",
          "                           ",
        " 444444444C 444444  44     4C",
        "     4C     4C      4C4    4C",
        "     4C     4C      4C 4   4C",
        "     4C     444444  4C  4  4C",
        "     4C     4C      4C   4 4C",
        "     4C     4C      4C    44C",
        "     4C     444444  4C    44C",
        "",
        "",

        " ",
        "111111111111111111111111111111",
    };
    for (int i = 0; i < 16; i++) {
        DrawLine(Playername[i], 32, x, y);
        y++;
    }
}
void demnguoc(int x, int y) {
    char count[9][43] = {
        "               0F   0         0F",
        "              0 0F 0         0 0F",
        "",
        " 00F 0F  0F  0000F   0000    0000F",
        "0F   0F  0F  0F      0F  0   0F 0F",
        "0F   00000F  0000F  000F 00  0F 0F",
        "0F   0F  0F  0F      0F  0   0F 0F",
        " 00F 0F  0F  0000F   0000    0000F",
        "                               0F"
    };
    for (int i = 0; i < 9; i++)
    {
        DrawLine(count[i], 42, x, y);
        y++;
    }
}
void tv(int x, int y) {
    char count[9][52  ] = {
        "          0   0",
        "         0 0 0                      00   00",
        "                                     0    0",
        " 0000   0000 00  00  00   0 0000 0  0 0000 0000",
        " 0   0  0    0 00 0  0 0  0 0    0  0 0  0 0",
        "000   0 0000 0 00 0  0  0 0 0 00 0  0 0  0 0",
        " 0   0  0    0    0  0   00 0  0 0  0 0  0 0",
        " 0000   0000 0    0  0   00 0000 0000 0000 0000",
      
        "                                       00"
    };
    for (int i = 0; i < 9; i++)
    {
        DrawLine(count[i], 52, x, y);
        y++;
    }
}
void choi(int x, int y) {
    char count[9][52] = {
        "                 0008",
        "                   08",
        "000008 08   08 000008 08  ",
        "08     08   08 08  08 08",
        "08     08   08 08  08 08",
        "08     0000008 08  08 08",
        "08     08   08 08  08 08 ",
        "000008 08   08 000008 08",
    };
    for (int i = 0; i < 9; i++)
    {
        DrawLine(count[i], 52, x, y);
        y++;
    }
}

// NEW
void loadMenuPlus() {
    int x = menu1_x + 14, y = menu1_y - 9, w = 28, h = 4;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 3, y + 2); cout << "FIND: ";
    txtColor(112);
    GotoXY(x + 9, y + 2); cout << "Press F to find";
    txtColor(116);
    DrawFull(x + 33, y + 1, w + 2, h, 136, 32);
    DrawFull(x + 31, y, w + 1, h, 195, 197);
    DrawFull(x + 33, y + 1, w - 3, h - 2, 119, 32);
    txtColor(112);
    GotoXY(x + 34, y + 2); cout << "Number of Save Files: ";
    txtColor(116);
}
// NEW
