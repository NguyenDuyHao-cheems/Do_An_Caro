
#pragma once 

#include <Windows.h>

void FixConsoleWindow(); // han che nguoi dung tu y dieu chinh kich thuoc cua so
void GotoXY(int x, int y); //di chuyen con tro toi toa do x,y
void txtColor(int k); // doi mau ki tu, mau nen khi in ra console
void SetConsoleSize(int width, int height); // dieu chinh kich thuoc console 

void SetFontSize(int width, int height); // dieu chinh kich thuoc font chu