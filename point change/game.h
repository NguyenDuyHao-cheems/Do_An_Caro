#pragma once 

#define _CRT_SECURE_NO_WARNINGS
<<<<<<< Updated upstream
=======
#define MAX_FILE_LENGTH 15
#define MAX_FILE_SAVE 10
>>>>>>> Stashed changes

#include "Board.h"
#include "Console.h"
extern int _COMMAND;
void AskContinue();
<<<<<<< Updated upstream
void PlayGame();
=======
void PlayGame(int k);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
void PlaywithBot();
void StartGamewithbot();
void AskContinuePlaybot();
void nhapnhay(const int winPositions[5][2], char symbol); //hieu ung noi bat chuoi lien tiep

=======
void PlaywithBot(int k);
void StartGamewithbot();
void AskContinuePlaybot();

void nhapnhay(const int winPositions[5][2], char symbol); //hieu ung noi bat chuoi lien tiep

void ResumeGame(int gameOption);
void SaveGameName();
bool checkDuplicate(char filename[]);
int getNumSaveFile(char savefiles[][MAX_FILE_LENGTH + 1]);
bool isValidName(char filename[]);
void writeTempToSF();
>>>>>>> Stashed changes
