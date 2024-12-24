#include "Board.h"
#include <iostream>
#include "menu.h"

using namespace std;
int win_x, win_y;
char name1[14];
char name2[14];
int newGameOpt;
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _X, _Y;
int h;
void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2;
            _A[i][j].y = 2 * i + TOP + 1;
            _A[i][j].c = 0;
        }
    }
    _TURN = true;
    _X = _A[0][0].x;
    _Y = _A[0][0].y;
}

void DrawBoard(int pSize) {
    for (int i = 1; i <= pSize * 4 - 1; i++) {
        for (int j = 0; j <= pSize; j++) {
            GotoXY(LEFT + i, TOP + 2 * j);
            cout << char(205);
        }
    }
    for (int i = 1; i <= pSize - 1; i++) {
        for (int j = 1; j <= pSize - 1; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            cout << char(206);
        }
    }
    for (int i = 0; i <= pSize; i++) {
        for (int j = 1; j <= pSize; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j - 1);
            cout << char(186);
        }
    }

    int i, j;

    j = TOP;
    i = LEFT + 4;
    while (i <= (pSize + LEFT / 4) * 4) {
        GotoXY(i, j);
        cout << char(203);
        GotoXY(i, j + pSize * 2);
        cout << char(202);
        i = i + 4;
    }
    j = TOP + 2;
    i = LEFT;
    while (j <= (pSize + TOP / 2) * 2) {
        GotoXY(i, j);
        cout << char(204);
        GotoXY(i + pSize * 4, j);
        cout << char(185);
        j = j + 2;
    }

    GotoXY(LEFT, TOP); cout << char(201);
    GotoXY(LEFT, TOP + BOARD_SIZE * 2); cout << char(200);
    GotoXY(LEFT + pSize * 4, TOP + BOARD_SIZE * 2); cout << char(188);
    GotoXY(LEFT + pSize * 4, TOP); cout << char(187);
    system("color F4");
}

int CheckBoard(int pX, int pY) {
    int row = (pY - TOP - 1) / 2;
    int col = (pX - LEFT - 2) / 4;
    if (_A[row][col].c == 0) {
        _A[row][col].c = _TURN ? -1 : 1;
        return _A[row][col].c;
    }
    return 0;
}
