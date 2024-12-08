﻿#include "menu.h"
#include "game.h"
#include "board.h"
#include <iostream>
#include <conio.h>
extern int win_x = 0, win_y = 0;
int run_x = 0, run_y = 0;
using namespace std;
bool isMusicOn = true;
int _COMMAND = 0;
int xUndo, yUndo;
int result;
char savefiles[MAX_FILE_SAVE][MAX_FILE_LENGTH + 1] = { "" };
int numSaveFile = getNumSaveFile(savefiles);
char filename[MAX_FILE_LENGTH + 1] = "";
FILE* tempFile;
FILE* allSaveFiles;
int optionSF = 1;
int newGame = -1;

void AskContinue() {
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int currentOpt = 0;
    int x = menu1_x , y = menu1_y , w = 50, h = 8;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2); cout << "Do you want to play again?";
    txtColor(112);
    GotoXY(x + 18, y + 5); cout << "Yes";
    GotoXY(x + 32, y + 5); cout << "No";
    txtColor(116);
    GotoXY(x + 18-3, y + 5); cout << "->";
    GotoXY(x + 18+4, y + 5); cout << "<-";
    while (1) {
        char c = toupper(_getch());
        if ( c == 'D')
        {
            GotoXY(x + 18-3, y + 5); cout << "  ";
            GotoXY(x + 18+4, y + 5); cout << "  ";
            currentOpt = -1;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 32-3, y + 5); cout << "->";
            GotoXY(x + 32+4, y + 5); cout << "<-";
        }
        if (c == 'A') {
            GotoXY(x + 32 - 3, y + 5); cout << "  ";
            GotoXY(x + 32 + 4, y + 5); cout << "  ";
            currentOpt = 1;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 18 - 3, y + 5); cout << "->";
            GotoXY(x + 18 + 4, y + 5); cout << "<-";
        }
        else if (c == 13)
        {
            if (currentOpt==1)
            {
                StartGame();
            }
            else 
            {
                printMenu();
            }
            break;
        }
    }
    
}
void AskContinuePlaybot() {
    hideCursor();
    if (isMusicOn) {
        PlayMo("mo.wav", L"mo_sound");
    }
    int currentOpt = 0;
    int x = menu1_x, y = menu1_y, w = 50, h = 8;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2); cout << "Do you want to play again?";
    txtColor(112);
    GotoXY(x + 18, y + 5); cout << "Yes";
    GotoXY(x + 32, y + 5); cout << "No";
    txtColor(116);
    GotoXY(x + 18 - 3, y + 5); cout << "->";
    GotoXY(x + 18 + 4, y + 5); cout << "<-";
    while (1) {
        char c = toupper(_getch());
        if (c == 'D')
        {
            GotoXY(x + 18 - 3, y + 5); cout << "  ";
            GotoXY(x + 18 + 4, y + 5); cout << "  ";
            currentOpt = -1;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 32 - 3, y + 5); cout << "->";
            GotoXY(x + 32 + 4, y + 5); cout << "<-";
        }
        if (c == 'A') {
            GotoXY(x + 32 - 3, y + 5); cout << "  ";
            GotoXY(x + 32 + 4, y + 5); cout << "  ";
            currentOpt = 1;
            if (isMusicOn) {
                PlayTick("tick.wav", L"tick_sound");
            }
            GotoXY(x + 18 - 3, y + 5); cout << "->";
            GotoXY(x + 18 + 4, y + 5); cout << "<-";
        }
        else if (c == 13)
        {
            if (currentOpt == 1)
            {
                StartGamewithbot();
            }
            else
            {
                printMenu();
            }
            break;
        }
    }
}
void changeColorCursor(bool turn)
{
    txtColor((15 << 4) | (turn ? 4 : 1)); 
    cout << "[";                         
    GotoXY(_X + 1, _Y);                  
    cout << "]";                         
    txtColor(7);
}
void PlayGame(int k) 
{    
    int kt = 1;
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    drawTableResult();
    TableResult(win_x, win_y, run_x, run_y);
    if (k == 0)
    {
        tempFile = fopen("Temporary.txt", "w");
        fprintf(tempFile, "p ");
    }
    else tempFile = fopen("Temporary.txt", "a");

    int prevX = _X, prevY = _Y;
    while (kt == 1) {
        if (!_TURN)
        {
            DrawNotX(BOARD_SIZE * 5 + 3, TOP - 1);
            DrawIsO(BOARD_SIZE * 5 + 38, TOP - 1);
        }
        else
        {

            DrawIsX(BOARD_SIZE * 5 + 3, TOP - 1);
            DrawNotO(BOARD_SIZE * 5 + 38, TOP - 1);
        }
        int prevRow = (prevY - TOP - 1) / 2;
        int prevCol = (prevX - LEFT - 2) / 4;
        if (prevX != _X || prevY != _Y)
        {
            GotoXY(prevX - 1, prevY);
            if (_A[prevRow][prevCol].c == -1) {
                txtColor((15 << 4) | 4);
                cout << " X ";
                txtColor(7);
            }
            else if (_A[prevRow][prevCol].c == 1) {
                txtColor((15 << 4) | 1);
                cout << " O ";
                txtColor(7);
            }
            else {
                txtColor((15 << 4) | 1);
                cout << "   ";
            }
            txtColor(7);
        }
        
        GotoXY(_X - 1, _Y);
        changeColorCursor(_TURN);
        
        GotoXY(_X, _Y);
       
        prevX = _X;
        prevY = _Y;
            
        _COMMAND = toupper(_getch());
        if (_COMMAND == 'A'|| _COMMAND == 75) {
            MoveLeft();
            if (isMusicOn) {
                PlayMove("move.wav", L"move_sound");
            }
        }
        else if (_COMMAND == 'D'|| _COMMAND == 77) {
            MoveRight();
            if (isMusicOn) {
                PlayMove("move.wav", L"move_sound");
            }
        }
        else if (_COMMAND == 'W'|| _COMMAND == 72) {
            MoveUp();
            if (isMusicOn) {
                PlayMove("move.wav", L"move_sound");
            }
        }
        else if (_COMMAND == 'S'|| _COMMAND == 80) {
            MoveDown();
            if (isMusicOn) {
                PlayMove("move.wav", L"move_sound");
            }
        }
        else if (_COMMAND == 13) {
            int row = (_Y - TOP - 1) / 2;
            int col = (_X - LEFT - 2) / 4;
            result = CheckBoard(_X, _Y);
                if (result != 0) {
                    result == -1 ? run_x++ : run_y++;
                    GotoXY(_X, _Y);
                    if (result == -1) {
                        txtColor((15 << 4) | 4);
                        cout << "X";
                        _A[row][col].c = -1;
                        fprintf(tempFile, "X(%d,%d) ", _X, _Y);
                    }
                    else {
                        txtColor((15 << 4) | 1);
                        cout << "O";
                        _A[row][col].c = 1;
                        fprintf(tempFile, "O(%d,%d) ", _X, _Y);
                    }
                    fflush(tempFile);
                    xUndo = _X;
                    yUndo = _Y;
                    int winPositions[5][2];
                    int gameResult = TestBoard(row, col, winPositions);
                    if (gameResult != 2) {
                        txtColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                        GotoXY(0, BOARD_SIZE * 2 + 2);
                        if (gameResult == 0) {
                            if (isMusicOn) {
                                PlayWin("win.wav", L"win_sound");
                            }
                            TableResult(win_x, win_y, run_x, run_y);
                            ve3();
                        }
                        else if (gameResult == -1) {
                            if (isMusicOn) {
                                PlayWin("win.wav", L"win_sound");
                            }
                            win_x++;
                            TableResult(win_x, win_y, run_x, run_y);
                            nhapnhay(winPositions, 'X');
                            ve();

                        }
                        else {
                            if (isMusicOn) {
                                PlayWin("win.wav", L"win_sound");
                            }
                            win_y++;
                            TableResult(win_x, win_y, run_x, run_y);
                            nhapnhay(winPositions, 'O');
                            ve2();
                        }
                        AskContinue();
                    }
                    _TURN = !_TURN;
                }
            
        }
        else if (_COMMAND == 'R')
        {
            if (result == -1 || result == 1)
            {
                if (result == 1) {
                    run_y--;
                }
                else if (result == -1) {
                    run_x--;
                }
                GotoXY(xUndo, yUndo);
                txtColor((15<<4)|4);
                cout << " ";
                txtColor(7);
                _TURN = !_TURN;
                int row = (yUndo - TOP - 1) / 2;
                int col = (xUndo - LEFT - 2) / 4;
                
                TableResult(win_x, win_y, run_x, run_y);
                _A[row][col].c = 0;
                result = 0;
                fprintf(tempFile, "U(%d,%d) ", xUndo, yUndo);
                fflush(tempFile);
            }
            GotoXY(_X, _Y);
        }
        else if (_COMMAND == 27)
        {
            PauseMenu();
            kt = 0;
        }
        TableResult(win_x, win_y, run_x, run_y);
    }
    fclose(tempFile);
}
// pause function
void ResumeGame(int gameOption)
{
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    char playMode, posXO;
    int posX = 0, posY = 0;
    FILE* tempFileRead = fopen("Temporary.txt", "rt");
    if (!tempFileRead) {
        cerr << "Error opening temporary save files!";
        return;
    }
    if (fscanf(tempFileRead, "%c ", &playMode) != 1) {
        fclose(tempFileRead);
        cerr << "Error reading play mode!";
        return;
    }
    int xCount = 0, oCount = 0;
    while (fscanf(tempFileRead, "%c(%d,%d) ", &posXO, &posX, &posY) != EOF) {
        int row = (posY - TOP - 1) / 2;
        int col = (posX - LEFT - 2) / 4;
        GotoXY(posX, posY);
        if (posXO == 'X') {
            txtColor((7 << 4) | 4); cout << "X";
            _A[row][col].c = -1;
            xCount++;
            xUndo = posX; yUndo = posY;
        }
        else if (posXO == 'O') {
            txtColor(FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            cout << "O";
            _A[row][col].c = 1;
            oCount++;
            xUndo = posX; yUndo = posY;
        }
        else if (posXO == 'U') {
            cout << " ";
            _A[row][col].c = 0;
        }
    }
    fclose(tempFileRead);
    _TURN = (xCount > oCount) ? false : true;
    if (playMode == 'p') PlayGame(1);
    else if (playMode == 'b') PlaywithBot(1);
    else if (gameOption == 1) PlayGame(0);
    else if (gameOption == 2) PlaywithBot(0);
}
void SaveGameName()
{
    int x = menu1_x - 5, y = menu1_y - 7;
    GotoXY(x + 7, y + 6);
    int i = 0;
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) {
                PauseMenu();
                return;
            }
            if (key == '\r') {
                filename[i] = '\0';
                break;
            }
            if (key == '\b' && i > 0) {
                i--;
                cout << "\b \b";
                continue;
            }
            if (i < MAX_FILE_LENGTH - 1 && key != '\b') {
                txtColor(14);
                cout << key;
                txtColor(116);
                filename[i++] = key;
            }
        }
    }
    if (!isValidName(filename)) {
        GotoXY(x + 9, y + 8);
        cout << "Invalid input!";
        GotoXY(x + 7, y + 6);
        cout << string(MAX_FILE_LENGTH, ' ');
        return;
    }
    if (checkDuplicate(filename)) {
        duplicateNameMenu();
        while (true) {
            char command = _getch();
            if (command == 27) {
                SaveGameMenu();
                return;
            }
        }
    }
    if (numSaveFile < MAX_FILE_SAVE) {
        SaveSuccessMenu();
        strcpy(savefiles[numSaveFile++ - 1], filename);
        writeTempToSF();
        numSaveFile = getNumSaveFile(savefiles);
        while (true) {
            char command = _getch();
            if (command == 27) {
                PauseMenu();
                return;
            }
        }
    }
    else {
        maxNumSFMenu();
        while (true) {
            char command = _getch();
            if (command == 27) {
                PauseMenu();
                return;
            }
        }
    }
}
int getNumSaveFile(char savefiles[][MAX_FILE_LENGTH + 1])
{
    int count = 0;
    char buffer[2000];
    char ch[20];
    allSaveFiles = fopen("allSaveFiles.txt", "rt");
    
    while (fgets(ch, MAX_FILE_LENGTH + 1, allSaveFiles) != NULL)
    {
        ch[strcspn(ch, "\n")] = '\0';
        strcpy(savefiles[count++], ch);
        fgets(buffer, sizeof(buffer), allSaveFiles);
    }
    fclose(allSaveFiles);
    return count;
}
bool checkDuplicate(char filename[]) {
    for (int i = 0; i < MAX_FILE_SAVE; i++) {
        if (strcmp(filename, savefiles[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidName(char filename[]) {
    if (filename[0] == '\0') return false;
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] != ' ') {
            return true;
        }
    }
    return false;
}
void writeTempToSF() {
        allSaveFiles = fopen("allSaveFiles.txt", "a");
        if (!allSaveFiles) {
            perror("Failed to open allSaveFiles.txt");
            return;
        }
        tempFile = fopen("Temporary.txt", "r");
        if (!tempFile) {
            perror("Failed to open Temporary.txt");
            fclose(allSaveFiles);
            return;
        }
        fprintf(allSaveFiles, "%s\n", filename);
        char ch;
        while ((ch = fgetc(tempFile)) != EOF) {
            fputc(ch, allSaveFiles);
        }
        fputc('\n', allSaveFiles);
        fclose(allSaveFiles);
        fclose(tempFile);
    }
void SaveGameMenu()
{
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    if (newGame)
    {
        GotoXY(x + 6, y + 2); cout << "NAME YOUR SAVE FILE:";
        txtColor(112);
        GotoXY(x + 6, y + 3); cout << "( <= 14 characters )";
        GotoXY(x + 5, y + 9); cout << "Press Esc to go back.";
        txtColor(116);
        DrawRoundedBox(x + 3, y + 5, 25, 3, 0);
        while (true)
        {
            SaveGameName();
            if (toupper(_getch()) == 27) break;
        }
    }
    else confirmOverwrite();
}
void confirmOverwrite()
{
    int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7;
    int kt = 1;
    txtColor(112);
    GotoXY(x + 8, y + 8); cout << "Yes";
    GotoXY(x + 24, y + 8); cout << "No";
    GotoXY(x + 10, y + 4); cout << "THIS ACTION IS";
    GotoXY(x + 11, y + 5); cout << "IRREVERSIBLE!";
    txtColor(116);
    GotoXY(x + 13, y + 3); cout << "WARNINGS:";
    GotoXY(x + 5, y + 8); cout << "->";
    GotoXY(x + 13, y + 8); cout << "<-";
    while (kt == 1) {
        char c = toupper(_getch());
        if (c == 'A' || c == 'D' || c == 75 || c == 77) {
            GotoXY(x + 5, y + 8); cout << "  ";
            GotoXY(x + 13, y + 8); cout << "  ";
            if (x == menu1_x - 7) x = menu1_x + 8;
            else if (x == menu1_x + 8) x = menu1_x - 7;
            if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
            GotoXY(x + 5, y + 8); cout << "->";
            GotoXY(x + 13, y + 8); cout << "<-";
        }
        else if (c == 27) {
            PauseMenu();
            kt = 0;
        }
        else if (c == 13) 
        {
            if (x == menu1_x - 7) {
                overwriteSF();
                PauseMenu();
                break;
            }
            else if (x == menu1_x + 8) {
                PauseMenu();
                break;
            }
        }
    }
}
void overwriteSF()
{
    strcpy(filename, savefiles[optionSF - 1]);
    writeTempToSF();
    char* buffer = new char[2000];
    tempFile = fopen("Temporary.txt", "r");
    if (!tempFile) {
        if (tempFile) fclose(tempFile);
        cerr << "Error opening file.";
        return;
    }
    fgets(buffer, 2000, tempFile);
    fclose(tempFile);
    deleteSaveFile(savefiles[optionSF - 1]);
    numSaveFile = getNumSaveFile(savefiles);
    optionSF = numSaveFile;
    tempFile = fopen("Temporary.txt", "w");
    fputs(buffer, tempFile);
    fclose(tempFile);
    delete[] buffer;
}
bool checkWin(int row, int col, int winPositions[5][2]) {
    int current = _A[row][col].c;
    if (current == 0) return false;

    int count, startRow, startCol;
    count = 1; startCol = col;
    for (int j = col - 1; j >= 0 && _A[row][j].c == current; j--) { count++; startCol = j; }
    for (int j = col + 1; j < BOARD_SIZE && _A[row][j].c == current; j++) count++;
    if (count >= 5) {
        for (int i = 0; i < 5; i++) {
            winPositions[i][0] = row;
            winPositions[i][1] = startCol + i;
        }
        return true;
    }
    count = 1; startRow = row;
    for (int i = row - 1; i >= 0 && _A[i][col].c == current; i--) { count++; startRow = i; }
    for (int i = row + 1; i < BOARD_SIZE && _A[i][col].c == current; i++) count++;
    if (count >= 5) {
        for (int i = 0; i < 5; i++) {
            winPositions[i][0] = startRow + i;
            winPositions[i][1] = col;
        }
        return true;
    }
    count = 1; startRow = row; startCol = col;
    for (int i = 1; row - i >= 0 && col - i >= 0 && _A[row - i][col - i].c == current; i++) {
        count++; startRow = row - i; startCol = col - i;
    }
    for (int i = 1; row + i < BOARD_SIZE && col + i < BOARD_SIZE && _A[row + i][col + i].c == current; i++) count++;
    if (count >= 5) {
        for (int i = 0; i < 5; i++) {
            winPositions[i][0] = startRow + i;
            winPositions[i][1] = startCol + i;
        }
        return true;
    }
    count = 1; startRow = row; startCol = col;
    for (int i = 1; row + i < BOARD_SIZE && col - i >= 0 && _A[row + i][col - i].c == current; i++) {
        count++; startRow = row + i; startCol = col - i;
    }
    for (int i = 1; row - i >= 0 && col + i < BOARD_SIZE && _A[row - i][col + i].c == current; i++) count++;
    if (count >= 5) {
        for (int i = 0; i < 5; i++) {
            winPositions[i][0] = startRow - i;
            winPositions[i][1] = startCol + i;
        }
        return true;
    }

    return false;
}
bool isFull(_POINT board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].c == 0) {
                return false;
            }
        }
    }
    return true;
}
int TestBoard(int row, int col, int winPositions[5][2]) {
    if (isFull(_A)) return 0;
    else {
        if (checkWin(row, col, winPositions)) {
            return (_TURN ? -1 : 1);
        }
        else return 2;
    }
}
void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;
        GotoXY(_X, _Y);
    }
}
void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;
        GotoXY(_X, _Y);
    }
}
void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;
        GotoXY(_X, _Y);
    }
}
void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;
        GotoXY(_X, _Y);
    }
}
void StartGame() {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    newGame = true;
    PlayGame(0);
}
void StartGamewithbot() {
    system("cls");
    showCursor();
    ResetData();
    DrawBoard(BOARD_SIZE);
    newGame = true;
    PlaywithBot(0);
}
// hide, unhide cursor
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void showCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
//------------------
// load game
void loadGameState(char filename[])
{
    system("cls");
    ResetData();
    showCursor();
    DrawBoard(BOARD_SIZE);

    allSaveFiles = fopen("allSaveFiles.txt", "rt");
    tempFile = fopen("Temporary.txt", "wt");
    if (!allSaveFiles)
    {
        cerr << "Error opening save files!";
        return;
    }
    char saveName[MAX_FILE_LENGTH + 1], posXO, gameMode;
    char* saveMove = new char[5000];
    int posX = 0, posY = 0, buffer;

    while (fgets(saveName, MAX_FILE_LENGTH + 1, allSaveFiles) != NULL)
    {
        saveName[strcspn(saveName, "\n")] = '\0';
        if (strcmp(saveName, filename) == 0) break;
        fgets(saveMove, 5000, allSaveFiles);
        saveMove[strcspn(saveMove, "\n")] = '\0';
    }
    buffer = fscanf(allSaveFiles, "\n%c ", &gameMode);
    fprintf(tempFile, "%c ", gameMode);
    while (fscanf(allSaveFiles, "%c(%d,%d) ", &posXO, &posX, &posY) != EOF)
    {
        if (posXO != 'X' && posXO != 'O' && posXO != 'U') break;
        fprintf(tempFile, "%c(%d,%d) ", posXO, posX, posY);
        int row = (posY - TOP - 1) / 2;
        int col = (posX - LEFT - 2) / 4;
        GotoXY(posX, posY);
        if (posXO == 'X')
        {
            txtColor((7 << 4) | 4);
            cout << "X";
            _A[row][col].c = -1;
            xUndo = posX;
            yUndo = posY;
        }
        else if (posXO == 'O')
        {
            txtColor(FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            cout << "O";
            _A[row][col].c = 1;
            xUndo = posX;
            yUndo = posY;
        }
        else if (posXO == 'U')
        {
            cout << " ";
            _A[row][col].c = 0;
        }
    }
    fclose(allSaveFiles);
    fclose(tempFile);

    int xCount = 0, oCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (_A[i][j].c == -1) xCount++;
            else if (_A[i][j].c == 1) oCount++;
        }
    }
    _TURN = (xCount > oCount) ? false : true;
    newGame = false;
    delete[] saveMove;
    if (gameMode == 'p') PlayGame(1);
    else if (gameMode == 'b') PlaywithBot(1);
}
void deleteSaveFile(char* filename)
{
    tempFile = fopen("Temporary.txt", "w+");
    allSaveFiles = fopen("allSaveFiles.txt", "r");
    char *buffer = new char [2000];
    char ch;
    if (!tempFile || !allSaveFiles) {
        cerr << "Error opening file.";
        fclose(tempFile);
        fclose(allSaveFiles);
        delete[] buffer;
        return;
    }
    for (int i = 0; i < 2 * (optionSF - 1); i++) {
        if (fgets(buffer, 2000, allSaveFiles)) fputs(buffer, tempFile);
    }
    fgets(buffer, 2000, allSaveFiles);
    fgets(buffer, 2000, allSaveFiles);
    while (fgets(buffer, 2000, allSaveFiles)) fputs(buffer, tempFile);
    allSaveFiles = fopen("allSaveFiles.txt", "w+");
    rewind(tempFile);
    while (fgets(buffer, 2000, tempFile)) fputs(buffer, allSaveFiles);
    fflush(tempFile);
    fflush(allSaveFiles);
    fclose(tempFile);
    fclose(allSaveFiles);
    delete[] buffer;
    numSaveFile = getNumSaveFile(savefiles);
}
void confirmMenu()
{
    int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    txtColor(112);
    GotoXY(x + 7, y + 5); cout << "Yes";
    GotoXY(x + 25, y + 5); cout << "No";
    GotoXY(x + 4, y + 3); cout << "THIS ACTION IS IRREVERSIBLE!";
    txtColor(116);
    GotoXY(x + 13, y + 2); cout << "WARNINGS:";
    GotoXY(x + 4, y + 5); cout << "->";
    GotoXY(x + 11, y + 5); cout << "<-";
    while (kt == 1) {
        char c = toupper(_getch());
        if (c == 'A' || c == 'D' || c == 75 || c == 77) {
            GotoXY(x + 4, y + 5); cout << "  ";
            GotoXY(x + 11, y + 5); cout << "  ";
            if (x == menu1_x - 7) x = menu1_x + 11;
            else if (x == menu1_x + 11) x = menu1_x - 7;
            if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
            GotoXY(x + 4, y + 5); cout << "->";
            GotoXY(x + 11, y + 5); cout << "<-";
        }
        else if (c == 27) {
            loadOrDeleteMenu();
            kt = 0;
        }
        else if (c == 13) {
            if (x == menu1_x - 7) {
                deleteSaveFile(savefiles[optionSF - 1]);
                LoadGame();
                break;
            }
            else if (x == menu1_x + 11) {
                loadOrDeleteMenu();
                break;
            }
        }
    }
}
void loadOrDeleteMenu()
{
    int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7;
    int kt = 1;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    txtColor(112);
    GotoXY(x + 8, y + 3); cout << "Load";
    GotoXY(x + 22, y + 3); cout << "Delete";
    txtColor(116);
    GotoXY(x + 8, y + 5); cout << "Press Esc to go back.";
    GotoXY(x + 4, y + 3); cout << "->";
    GotoXY(x + 14, y + 3); cout << "<-";
    while (kt == 1) {
        char c = toupper(_getch());
        if (c == 'A' || c == 'D' || c == 75 || c == 77) {
            GotoXY(x + 4, y + 3); cout << "  ";
            GotoXY(x + 14, y + 3); cout << "  ";
            if (x == menu1_x - 7) x = menu1_x + 8;
            else if (x == menu1_x + 8) x = menu1_x - 7;
            if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
            GotoXY(x + 4, y + 3); cout << "->";
            GotoXY(x + 14, y + 3); cout << "<-";
        }
        else if (c == 27) {
            LoadGame();
            kt = 0;
        }
        else if (c == 13) {
            if (x == menu1_x - 7) {
                loadGameState(savefiles[optionSF - 1]);
                break;
            }
            else if (x == menu1_x + 8) {
                confirmMenu();
                break;
            }
        }
    }
}
void LoadGameSelection()
{
    numSaveFile = getNumSaveFile(savefiles);
    int x = menu1_x - 15, y = menu1_y - 15;
    int move, kt = 1;
    optionSF = 1;
    while (kt == 1)
    {
        GotoXY(x + 11, y + 5);
        std::cout << "--->";
        GotoXY(x + 34, y + 5);
        std::cout << "<---";

        move = _getch();
        move = toupper(move);

        if (move == 80 || move == 'S')
        {
            GotoXY(x + 11, y + 5);
            cout << "    ";
            GotoXY(x + 34, y + 5);
            cout << "    ";
            y = (y == menu1_y - 15 + numSaveFile - 1) ? menu1_y - 15 : y + 1;
            optionSF = (optionSF == numSaveFile) ? 1 : optionSF + 1;
        }
        else if (move == 72 || move == 'W')
        {
            GotoXY(x + 11, y + 5);
            cout << "    ";
            GotoXY(x + 34, y + 5);
            cout << "    ";
            y = (y == menu1_y - 15) ? menu1_y - 15 + numSaveFile - 1: y - 1;
            optionSF = (optionSF == 1) ? numSaveFile : optionSF - 1;
        }
        else if (move == 13)
        {
            loadOrDeleteMenu();
            kt = 0;
        }
        else if (move == 27)
        {
            printMenu();
            kt = 0;
        }
    }
}
void LoadGame()
{
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    int x = menu1_x - 15, y = menu1_y - 15, w = 50, h = 18;
    numSaveFile = getNumSaveFile(savefiles);
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);

    GotoXY(x + 16, y + 2);
    cout << "Choose a Save File:";
    GotoXY(x + 5, y + 16);
    cout << "Press Esc to turn back to the main Menu...";
    if (numSaveFile == 0)
    {
        GotoXY(x + 16, y + 5); 
        txtColor(112);
        cout << "No save file yet.";
        txtColor(116);
        while (char command = _getch())
        {
            if (command == 27) printMenu();
        }
    }
    else
    {
        for (int i = 0; i < numSaveFile; i++)
        {
            GotoXY(x + 16, y + 5 + i);
            txtColor(112);
            cout << savefiles[i];
            txtColor(116);
        }
    }
    LoadGameSelection();
}
// play with bot
int evaluatePosition(int row, int col, int player) {
    int score = 0;
    int dx[] = { 0, 1, 1, 1 };
    int dy[] = { 1, 0, 1, -1 };

    for (int dir = 0; dir < 4; ++dir) {
        int count = 1;
        int block = 0;
        for (int step = 1; step <= 4; ++step) {
            int nx = row + step * dx[dir];
            int ny = col + step * dy[dir];
            if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != player) {
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != 0)
                    block++;
                break;
            }
            count++;
        }

        for (int step = 1; step <= 4; ++step) {
            int nx = row - step * dx[dir];
            int ny = col - step * dy[dir];
            if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != player) {
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != 0)
                    block++;
                break;
            }
            count++;
        }
        if (count >= 5) {
            score += 10000;
        }
        else if (block == 0) {
            score += count * count;
        }
        else if (block == 1) {
            score += count;
        }
    }
    return score;
}
void BotMove(int& pX, int& pY) {
    int bestScore = -1;
    pX = pY = -1;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0) {
                int score = evaluatePosition(i, j, 1);
                score += evaluatePosition(i, j, -1);
                if (score > bestScore) {
                    bestScore = score;
                    pX = i; pY = j;
                }
            }
        }
    }
    int temp = pX;
    pX = 4 * pY + LEFT + 2;
    pY = 2 * temp + TOP + 1;
}
void PlaywithBot(int k) {
    int xUndo, yUndo, kt = 1;
    result = 0;
    bool validEnter = true;

    if (k == 0)
    {
        tempFile = fopen("Temporary.txt", "w");
        fprintf(tempFile, "b ");
    }
    else tempFile = fopen("Temporary.txt", "a");

    while (kt == 1) {
        if (!_TURN)
        {
            DrawNotX(55, 1);
            DrawIsO(91, 1);
        }
        else
        {
            DrawIsX(55, 1);
            DrawNotO(91, 1);
        }
        GotoXY(_X, _Y);
        while (_TURN == true) {
            _COMMAND = toupper(_getch());
            if (_COMMAND == 27) {
                PauseMenu();
                kt = 0;
            }
            else if (_COMMAND == 'A') {
                MoveLeft();
                if (isMusicOn) {
                    PlayMove("move.wav", L"move_sound");
                }
            }
            else if (_COMMAND == 'D') {
                MoveRight();
                if (isMusicOn) {
                    PlayMove("move.wav", L"move_sound");
                }
            }
            else if (_COMMAND == 'W') {
                MoveUp();
                if (isMusicOn) {
                    PlayMove("move.wav", L"move_sound");
                }
            }
            else if (_COMMAND == 'S') {
                MoveDown();
                if (isMusicOn) {
                    PlayMove("move.wav", L"move_sound");
                }
            }
            else if (_COMMAND == 13) {
                result = CheckBoard(_X, _Y);
                if (result != 0) {
                    GotoXY(_X, _Y);
                    txtColor(FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    cout << 'X';
                    fprintf(tempFile, "X(%d,%d) ", _X, _Y);
                    fflush(tempFile);
                    xUndo = _X;
                    yUndo = _Y;
                    int row = (_Y - TOP - 1) / 2;
                    int col = (_X - LEFT - 2) / 4;
                    int winPositions[5][2];
                    int gameResult = TestBoard(row, col, winPositions);
                    if (gameResult != 2) {
                        GotoXY(0, BOARD_SIZE * 2 + 2);
                        if (gameResult == 0) {
                            ve3();
                        }
                        else {
                            if (gameResult == -1) {
                                cout << "Nguoi choi thang";
                                nhapnhay(winPositions, 'X');
                                ve();
                            }
                            else {
                                cout << "May thang";
                                nhapnhay(winPositions, 'O');
                                ve2();
                            }
                        }
                        AskContinuePlaybot();
                    }
                    _TURN = !_TURN;
                }
            }
        }
        while (!_TURN)
        {
            int delayMiliSecs = 2000;
            int shortSecs = 0;
            while (shortSecs < delayMiliSecs)
            {
                Sleep(100);
                shortSecs += 100;
                if (_kbhit())
                {
                    _COMMAND = toupper(_getch());
                    if (_COMMAND == 'R')
                    {
                        if (result == -1 || result == 1)
                        {
                            GotoXY(xUndo, yUndo);
                            std::cout << " ";
                            int row = (yUndo - TOP - 1) / 2;
                            int col = (xUndo - LEFT - 2) / 4;
                            _A[row][col].c = 0;
                            result = 0;
                            fprintf(tempFile, "U(%d,%d) ", xUndo, yUndo);
                            fflush(tempFile);
                        }
                        GotoXY(_X, _Y);
                        _TURN = !_TURN;
                        break;
                    }
                }
            }
            if (!_TURN) {
                int pX, pY;
                BotMove(pX, pY);
                result = CheckBoard(pX, pY);
                if (result != 0) {
                    GotoXY(pX, pY);
                    txtColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    cout << 'O';
                    fprintf(tempFile, "O(%d,%d) ", pX, pY);
                    fflush(tempFile);
                    int row = (pY - TOP - 1) / 2;
                    int col = (pX - LEFT - 2) / 4;
                    int winPositions[5][2];

                    int gameResult = TestBoard(row, col, winPositions);
                    if (gameResult != 2) {
                        GotoXY(0, BOARD_SIZE * 2 + 2);
                        if (gameResult == 0) { 
                            ve3();
                            cout << "Hoa nhau"; }
                        else {
                            if (gameResult == -1) {
                                if (isMusicOn) {
                                    PlayWin("win.wav", L"win_sound");
                                }
                                
                                nhapnhay(winPositions, 'X');
                                ve();
                            }
                            else {
                                if (isMusicOn) {
                                    PlayWin("win.wav", L"win_sound");
                                }
                                nhapnhay(winPositions, 'O');
                                ve2();
                            }
                        }
                        AskContinuePlaybot();
                    }
                    _TURN = !_TURN;
                }
            }
        }
    }
    fclose(tempFile);
}
// hieu ung noi bat chuoi x hoac o
void nhapnhay(const int winPositions[5][2], char symbol) {
    int blinkTime = 500;
    int duration = 3000;
    int elapsed = 0;
    const int blackBold = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;

    while (elapsed < duration) {
        txtColor(blackBold);
        for (int i = 0; i < 5; ++i) {
            int x = LEFT + 2 + winPositions[i][1] * 4;
            int y = TOP + 1 + winPositions[i][0] * 2;
            GotoXY(x, y);
            cout << symbol;
        }
        Sleep(blinkTime);
        txtColor(7);
        for (int i = 0; i < 5; ++i) {
            int x = LEFT + 2 + winPositions[i][1] * 4;
            int y = TOP + 1 + winPositions[i][0] * 2;
            GotoXY(x, y);
            cout << ' ';
        }
        Sleep(blinkTime);

        elapsed += 2 * blinkTime;
    }
    txtColor(blackBold);
    for (int i = 0; i < 5; ++i) {
        int x = LEFT + 2 + winPositions[i][1] * 4;
        int y = TOP + 1 + winPositions[i][0] * 2;
        GotoXY(x, y);
        cout << symbol;
    }
    txtColor(7);
}
void TableResult(int& win_x, int& win_y, int& run_x, int& run_y)
{
    int move_x = 0, move_y = 0;
    int N = BOARD_SIZE * 5 + 7, M = TOP + 18;
    if (_TURN) move_x++;
    else move_y++;
    txtColor(116);
    GotoXY(N + 9, M + 3);
    cout << move_x;
    GotoXY(N + 9, M + 5);
    cout << run_x;
    GotoXY(N + 9, M + 7);
    cout << win_x;

    txtColor(121);
    GotoXY(N + 48, M + 3);
    cout << move_y;
    GotoXY(N + 48, M + 5);
    cout << run_y;
    GotoXY(N + 48, M + 7);
    cout << win_y;
}
void drawTableResult()
{
    int t = 219, t2 = 219, t3 = 205, t4 = 179, N = BOARD_SIZE * 5 + 7, M = TOP + 18;
    txtColor(124);
    for (int i = LEFT - 2; i <= 4 * BOARD_SIZE + LEFT + 2; i++) {
        GotoXY(i, TOP - 1);
        cout << char(t2);
        GotoXY(i, BOARD_SIZE * 2 + TOP + 1);
        cout << char(t2);
    }
    for (int i = TOP; i <= BOARD_SIZE * 2 + TOP; i++) {
        GotoXY(LEFT - 1, i);
        cout << char(t);
        GotoXY(LEFT - 2, i);
        cout << char(t);
        GotoXY(4 * BOARD_SIZE + LEFT + 1, i);
        cout << char(t);
        GotoXY(4 * BOARD_SIZE + LEFT + 2, i);
        cout << char(t);
    }

    txtColor(116);
    int w = 20, h = 10;
    DrawFull(N - 2, M, w, h, 135, 32);
    DrawFull(N - 4, M - 1, w, h, 68, 32);
    DrawFull(N - 2, M, w - 4, h - 2, 121, 32);
    GotoXY(N - 1, M + 1);
    cout << " PLAYER 1: X";
    GotoXY(N - 1, M + 3);
    cout << "    Turn: ";
    GotoXY(N - 1, M + 5);
    cout << "    Run: ";
    GotoXY(N - 1, M + 7);
    cout << "    Win: ";

    txtColor(121);
    DrawFull(N + 37, M, w, h, 136, 32);
    DrawFull(N + 35, M - 1, w, h, 151, 32);
    DrawFull(N + 37, M, w - 4, h - 2, 119, 32);
    GotoXY(N + 38, M + 1);
    txtColor(121);
    cout << " PLAYER 2: O";
    GotoXY(N + 38, M + 3);
    cout << "    Turn: ";
    GotoXY(N + 38, M + 5);
    cout << "    Run: ";
    GotoXY(N + 38, M + 7);
    cout << "    Win: ";
}
