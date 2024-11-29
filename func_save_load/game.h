#pragma once 

#define _CRT_SECURE_NO_WARNINGS

#include "Board.h"
#include "Console.h"
extern int _COMMAND;
void AskContinue();
void PlayGame();
bool checkWin(int row, int col, int winPositions[5][2]);
bool isFull(_POINT board[][BOARD_SIZE]);
int TestBoard(int row, int col, int winPositions[5][2]);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void StartGame();

void hideCursor();
void showCursor();

//load
void loadGameState(char filename[]);
void LoadGameSelection();
void LoadGame();
//play with bot
int evaluatePosition(int row, int col, int player);
void BotMove(int& pX, int& pY);
void PlaywithBot();
void StartGamewithbot();
void AskContinuePlaybot();
void nhapnhay(const int winPositions[5][2], char symbol); //hieu ung noi bat chuoi lien tiep

