#pragma once 

#define _CRT_SECURE_NO_WARNINGS
#define MAX_FILE_LENGTH 15
#define MAX_FILE_SAVE 10


#include "Board.h"
#include "Console.h"
extern bool isMusicOn;
extern int _COMMAND;
void AskContinue();
void Count_sumTime(TIME& time, int x, int y, int& k);

void CountTime_XO(TIME& time, int x, int y, int& k, int cnttime);

void PlayGame(int k, int& win_x, int& win_y, int cnttime);
bool checkWin(int row, int col, int winPositions[5][2]);
bool isFull(_POINT board[][BOARD_SIZE]);
int TestBoard(int row, int col, int winPositions[5][2]);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void StartGame(int k,int  cnttime);

void hideCursor();
void showCursor();
void cursorBot(int _X, int _Y, int& preX, int& preY);
void changeColorCursor(bool turn);
//load
void loadGameState(char filename[]);
void LoadGameSelection();
void LoadGame();
//play with bot
int evaluatePosition(int row, int col, int player);
void BotMove(int& pX, int& pY);

void PlaywithBot(int k, int& win_x, int& win_y, int cnttime);
void StartGamewithbot(int k, int cnttime);
void AskContinuePlaybot();

void nhapnhay(const int winPositions[5][2], char symbol); //hieu ung noi bat chuoi lien tiep

void ResumeGame(int gameOption);
void SaveGameName();
bool checkDuplicate(char filename[]);

SystemTime getSystemTime();
void writeSystemTime();
SystemTime readSystemTime(int numTimes);
void TimeMagToArray();

void getStats();
void writeSumOfTime();
Stats readSumOfTime(int numTimes);
void statsToArray();

int getNumSaveFile(char savefiles[][MAX_FILE_LENGTH + 1]);
bool isValidName(char filename[]);
void writeTempToSF();
void confirmMenu();
void deleteSaveFile(char* filename);
void overwriteSF();

void TableResult(int& win_x, int& win_y, int& run_x, int& run_y);
void drawTableResult();
void drawPhuthuy(int x, int y);

void drawStart(int x, int y);

void drawEnd(int x, int y);

void SmallMenu(int x, int y);
void drawPikachu(int x, int y);

