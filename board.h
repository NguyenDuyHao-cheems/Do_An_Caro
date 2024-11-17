#pragma once 

#include "Console.h"

#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1
#define menu1_x LEFT+41+43
#define menu1_y TOP+12+8
struct _POINT {
    int x, y, c;
};

extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;

extern int _X, _Y;

void ResetData();
void DrawBoard(int pSize);
int CheckBoard(int pX, int pY);

