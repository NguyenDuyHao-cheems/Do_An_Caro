#pragma once 

#include "Console.h"

#define BOARD_SIZE 15 // kich thuoc ban co
#define LEFT 40
#define TOP 11
#define menu1_x 3+41+17+26 // toa do menu
#define menu1_y 4+12+10
struct _POINT { //kieu du lieu luu vi tri tren ban co va xac dinh vi tri da duoc danh hay chua
    int x, y, c;
};

extern _POINT _A[BOARD_SIZE][BOARD_SIZE]; //ban co 
extern bool _TURN; //bien luot choi

extern int _X, _Y; //bien toa do ban co

void ResetData(); //ham xoa du lieu ban co
void DrawBoard(int pSize); //ve ban co
int CheckBoard(int pX, int pY); // kiem tra vi tri tren ban co da duoc danh hay chua
struct TIME {

    int minutes = 0, seconds = 0;

};



extern int win_x;

extern int win_y;

extern char name1[13 + 1];

extern char name2[13 + 1];

extern int newGameOpt;
