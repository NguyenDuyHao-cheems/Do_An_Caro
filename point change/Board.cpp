#include "Board.h"
#include <iostream>
#include "menu.h"

using namespace std;

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _X, _Y;

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
    for (int i = 0; i < pSize; i++) {
        for (int j = 0; j < pSize; j++) {
            Box(LEFT + 4 * i, TOP + 2 * j, 4, 2);
        }
    }
    int i, j;
    j = TOP;
    i = LEFT + 4;
    while (i <= (pSize) * 4) {
        GotoXY(i, j);
        cout << char(194);
        i += 4; 
    }
    i = LEFT + 4;
    j = TOP + pSize * 2;
    while (i <= (pSize) * 4) {
        GotoXY(i, j);
        cout << char(193);
        i += 4;
    }
    j = TOP + 2;
    i = LEFT;
    while (j <= (pSize) * 2) {
        GotoXY(i, j);
        cout << char(195);
        j += 2;
    }
    j = TOP + 2;
    i = LEFT + pSize * 4;
    while (j <= (pSize) * 2) {
        GotoXY(i, j);
        cout << char(180);
        j += 2;
    }
    for (int i = 1; i <= pSize - 1; i++) {
        for (int j = 1; j <= pSize - 1; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            cout << char(197);
        }
    }
    system("color 74");
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
