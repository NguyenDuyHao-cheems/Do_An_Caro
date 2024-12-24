#pragma once 

#define _CRT_SECURE_NO_WARNINGS
#define MAX_FILE_LENGTH 15
#define MAX_FILE_SAVE 100
#define MAX_PAGE 10
#define MAX_SAVE_PER_PAGE 10

#include "Board.h"
#include "Console.h"
extern bool isMusicOn;
extern int _COMMAND;
extern int curlang; //ngon ngu hien tai 0-English
//xu li van dau
void StartGame(int k, int  cnttime);
void PlayGame(int k, int& win_x, int& win_y, int cnttime);
bool checkWin(int row, int col, int winPositions[5][2]);
bool isFull(_POINT board[][BOARD_SIZE]);
int TestBoard(int row, int col, int winPositions[5][2]);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void AskContinue();

//thoi gian
void Count_sumTime(TIME& time, int x, int y, int& k);
void CountTime_XO(TIME& time, int x, int y, int& k, int cnttime);
SystemTime getSystemTime();
void writeSystemTime();
SystemTime readSystemTime(int numTimes);
void TimeMagToArray();

//hieu ung tro choi 
void hideCursor();
void showCursor();
void cursorBot(int _X, int _Y, int& preX, int& preY);
void changeColorCursor(bool turn);
void LoadingEffect(int Lx, int Ly, int duration);
void nhapnhay(const int winPositions[5][2], char symbol); //hieu ung noi bat chuoi lien tiep
void TableResult(int& win_x, int& win_y, int& run_x, int& run_y);
void drawTableResult();

//load game
void loadGameState(char filename[]);
void LoadGameSelection(bool isNew);
void LoadGame();

//save game
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

//play with bot
int evaluatePosition(int row, int col, int player);
void BotMove(int& pX, int& pY);
void PlaywithBot(int k, int& win_x, int& win_y, int cnttime);
void StartGamewithbot(int k, int cnttime);
void AskContinuePlaybot();

//pause game
void ResumeGame(int gameOption);
void SaveGameName();
bool checkDuplicate(char filename[]);









