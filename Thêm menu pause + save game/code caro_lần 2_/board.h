#pragma once 

#include "Console.h"

#define BOARD_SIZE 15 // kich thuoc ban co
#define LEFT 3
#define TOP 4
#define menu1_x LEFT+41+17+20 // toa do menu
#define menu1_y TOP+12+8
struct _POINT { //kieu du lieu luu vi tri tren ban co va xac dinh vi tri da duoc danh hay chua
    int x, y, c;
};

struct TIME {
    int minutes = 0, seconds = 0;
};

extern _POINT _A[BOARD_SIZE][BOARD_SIZE]; //ban co 
extern bool _TURN; //bien luot choi

extern int _X, _Y; //bien toa do ban co

void ResetData(); //ham xoa du lieu ban co
void DrawBoard(int pSize); //ve ban co
int CheckBoard(int pX, int pY); // kiem tra vi tri tren ban co da duoc danh hay chua

