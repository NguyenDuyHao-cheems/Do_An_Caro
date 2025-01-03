#include "menu.h"
#include "game.h"
#include "board.h"
#include <iostream>
#include <conio.h>
#include <time.h>
int run_x = 0, run_y = 0;
int turn_x = 0, turn_y = 0;

TIME sum, XO;
int  N = BOARD_SIZE * 5 + LEFT + 4, M = TOP + 18;
SystemTime systemtime[MAX_FILE_SAVE];
using namespace std;
bool isMusicOn = true;
int _COMMAND = 0;
int xUndo, yUndo;
int result;
char savefiles[MAX_FILE_SAVE][MAX_FILE_LENGTH + 1] = { "" };
char playModeGame[MAX_FILE_SAVE] = {};
int numSaveFile = getNumSaveFile(savefiles);
char filename[MAX_FILE_LENGTH + 1] = "";
FILE* tempFile;
FILE* allSaveFiles;
int optionSF = 1;
int newGame = -1;
int pretime;
Stats TempStat, statsSF[MAX_FILE_SAVE];
int value = 0; //ref cua sumtime
int kXO = 0; //ref cua counttime XO
int pageMax = 1;
int pageNumber = 1;
string currentSaveFile = "";
void AskContinue() {
    if (curlang == 0) {
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int currentOpt = 1;
        int x = BOARD_SIZE * 5 + 3 + 3 + LEFT, y = TOP + 7, w = 50, h = 8;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 15, y + 2); cout << "Do you want to play again?";
        txtColor(112);
        GotoXY(x + 18, y + 5); cout << "Yes";
        GotoXY(x + 32, y + 5); cout << "No";
        txtColor((0 << 4) | 15);
        GotoXY(x + 18, y + 5);
        cout << "Yes";
        while (1) {
            char c = toupper(_getch());
            if (c == 'D') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
                currentOpt = -1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
            }
            if (c == 'A') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
                currentOpt = 1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
            }
            else if (c == 13) {
                if (currentOpt == 1) {
                    tempFile = fopen("Temporary.txt", "w");
                    fprintf(tempFile, "p ");
                    fclose(tempFile);
                    StartGame(1, pretime);
                }
                else if (currentOpt == -1) printMenu();
                break;
            }
        }
    }
    else {
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int currentOpt = 1;
        int x = BOARD_SIZE * 5 + 3 + 3 + LEFT, y = TOP + 7, w = 50, h = 8;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 15, y + 2); cout << "Ban co muon choi lai?";
        txtColor(112);
        GotoXY(x + 18, y + 5); cout << "Co";
        GotoXY(x + 32, y + 5); cout << "Khong";
        txtColor((0 << 4) | 15);
        GotoXY(x + 18, y + 5);
        cout << "Co";
        while (1) {
            char c = toupper(_getch());
            if (c == 'D') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
                currentOpt = -1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
            }
            if (c == 'A') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
                currentOpt = 1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
            }
            else if (c == 13) {
                if (currentOpt == 1) {
                    tempFile = fopen("Temporary.txt", "w");
                    fprintf(tempFile, "p ");
                    fclose(tempFile);
                    StartGame(1, pretime);
                }
                else if (currentOpt == -1) printMenu();
                break;
            }
        }
    }
}
void AskContinuePlaybot() {
    if (curlang == 0) {
        hideCursor();
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int x = BOARD_SIZE * 5 + 3 + 3 + LEFT, y = TOP + 7, w = 50, h = 8, currentOpt = 1;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 15, y + 2); cout << "Do you want to play again?";
        txtColor(112);
        GotoXY(x + 18, y + 5); cout << "Yes";
        GotoXY(x + 32, y + 5); cout << "No";
        txtColor((0 << 4) | 15);
        GotoXY(x + 18, y + 5); cout << "Yes";
        while (1) {
            char c = toupper(_getch());
            if (c == 'D') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
                currentOpt = -1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
            }
            if (c == 'A') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
                currentOpt = 1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "No";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Yes";
                }
            }
            else if (c == 13) {
                if (currentOpt == 1) {
                    tempFile = fopen("Temporary.txt", "w");
                    fprintf(tempFile, "b ");
                    fclose(tempFile);
                    StartGamewithbot(1, pretime);
                }
                else printMenu();
                break;
            }
        }
    }
    else {
        hideCursor();
        if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
        int x = BOARD_SIZE * 5 + 3 + 3 + LEFT, y = TOP + 7, w = 50, h = 8, currentOpt = 1;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        GotoXY(x + 15, y + 2); cout << "Ban co muon choi lai khong?";
        txtColor(112);
        GotoXY(x + 18, y + 5); cout << "Co";
        GotoXY(x + 32, y + 5); cout << "Khong";
        txtColor((0 << 4) | 15);
        GotoXY(x + 18, y + 5); cout << "Co";
        while (1) {
            char c = toupper(_getch());
            if (c == 'D') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
                currentOpt = -1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
            }
            if (c == 'A') {
                if (currentOpt == -1) {
                    txtColor(112);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor(112);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
                currentOpt = 1;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                if (currentOpt == -1) {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 32, y + 5);
                    cout << "Khong";
                }
                else {
                    txtColor((0 << 4) | 15);
                    GotoXY(x + 18, y + 5);
                    cout << "Co";
                }
            }
            else if (c == 13) {
                if (currentOpt == 1) {
                    tempFile = fopen("Temporary.txt", "w");
                    fprintf(tempFile, "b ");
                    fclose(tempFile);
                    StartGamewithbot(1, pretime);
                }
                else printMenu();
                break;
            }
        }
    }
}
void Count_sumTime(TIME& time, int x, int y, int& k) {
    x = x + 20;
    mutex mtx;
    lock_guard<mutex> lock(mtx);
    PrintAt(x + 4, y - 3, ":");
    if (time.seconds < 10)
        PrintAt(x + 6, y - 3, "0" + to_string(time.seconds));
    else
        PrintAt(x + 6, y - 3, to_string(time.seconds));
    if (time.minutes < 10)
        PrintAt(x + 1, y - 3, "0" + to_string(time.minutes));
    else
        PrintAt(x + 1, y - 3, to_string(time.minutes));
    while (true) {
        if (k == 2) {
            time.minutes = 0;
            time.seconds = 0;
            PrintAt(x + 1, y - 3, "       ");
            break;
        }
        if (k == 3) return;
        Sleep(1000);
        time.seconds++;
        if (time.seconds == 60) {
            time.seconds = 0;
            PrintAt(x + 6, y - 3, "0" + to_string(time.seconds));
            time.minutes++;
            if (time.minutes < 10) PrintAt(x + 1, y - 3, "0" + to_string(time.minutes));
            else PrintAt(x + 1, y - 3, to_string(time.minutes));
            continue;
        }
        if (time.seconds < 10) PrintAt(x + 6, y - 3, "0" + to_string(time.seconds));
        else PrintAt(x + 6, y - 3, to_string(time.seconds));
    }
}
void CountTime_XO(TIME& time, int x, int y, int& k, int cnttime) {
    x = x + 20;
    mutex mtx;
    lock_guard<mutex> lock(mtx);
    time.seconds = cnttime;
    if (k != 4) { //k = 4 khi cnttime = -1 tuc inf
        PrintAt(x + 3, y, to_string(time.seconds));
        while (true) {
            if (k == 1) {
                time.seconds = cnttime;
                PrintAt(x + 3, y, to_string(time.seconds));
                k = 0;
            }
            else if (k == 2) {
                time.seconds = 0;
                PrintAt(x + 3, y, "      ");
                break;
            }
            if (k == 3) return;
            Sleep(1000);
            time.seconds--;
            if (time.seconds == -1) {
                _TURN = !_TURN;
                time.seconds = cnttime;
                PrintAt(x + 3, y, to_string(time.seconds));
                if (!_TURN)
                {
                    turn_x = 0, turn_y = 1;
                    GotoXY(N + 9, M + 6);
                    txtColor(116);
                    cout << turn_x;
                    GotoXY(N + 49, M + 6);
                    txtColor(121);
                    cout << turn_y;
                    DrawNotX(BOARD_SIZE * 5 + LEFT, TOP - 1);
                    DrawIsO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
                }
                else {
                    turn_y = 1, turn_x = 0;
                    GotoXY(N + 9, M + 6);
                    txtColor(116);
                    cout << turn_x;
                    GotoXY(N + 49, M + 6);
                    txtColor(121);
                    cout << turn_y;
                    DrawIsX(BOARD_SIZE * 5 + LEFT, TOP - 1);
                    DrawNotO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
                }
            }
            if (time.seconds < 10) PrintAt(x + 3, y, "0" + to_string(time.seconds));
            else PrintAt(x + 3, y, to_string(time.seconds));
        }
    }
    else {
        PrintAt(x + 3, y, "INF");
        k = 0;
        return;
    }
}
void changeColorCursor(bool turn) {
    txtColor((15 << 4) | (turn ? 4 : 1));
    cout << "[";
    GotoXY(_X + 1, _Y);
    cout << "]";
}
void PlayGame(int k, int& win_x, int& win_y, int cnttime) {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    SmallMenu(6, TOP - 2);
    drawSmallCloud(1, 39);
    drawPhuthuy(5, 20);
    drawStart(75, 1);
    drawEnd(75, 45);
    int kt = 1;
    value = 0;
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    if (k == 0) {
        tempFile = fopen("Temporary.txt", "w");
        fprintf(tempFile, "p ");
        fflush(tempFile);
        win_x = 0; win_y = 0;
        sum.minutes = 0;
        sum.seconds = 0;
    }
    else {
        tempFile = fopen("Temporary.txt", "a");
        newGame = false;
    }
    if (curlang == 0) {
        if (!tempFile) {
            cerr << "Error opening file.";
            return;
        }
    }
    else {
        if (!tempFile) {
            cerr << "Loi mo file.";
            return;
        }
    }
    pretime = cnttime;

    if (cnttime == -1)
    {
        value = 4;
    }

    thread clock_sum(Count_sumTime, ref(sum), BOARD_SIZE * 5 + LEFT + 6, TOP + 23, ref(value));
    clock_sum.detach();
    thread clock_XO(CountTime_XO, ref(XO), BOARD_SIZE * 5 + LEFT + 7, TOP + 24, ref(value), cnttime);
    clock_XO.detach();
    drawTableResult();
    TableResult(win_x, win_y, run_x, run_y);
    int prevX = _X, prevY = _Y;
    while (kt == 1) {
        if (!_TURN) {
            DrawNotX(BOARD_SIZE * 5 + LEFT, TOP - 1);
            DrawIsO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
        }
        else {
            DrawIsX(BOARD_SIZE * 5 + LEFT, TOP - 1);
            DrawNotO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
        }
        int prevRow = (prevY - TOP - 1) / 2, prevCol = (prevX - LEFT - 2) / 4;
        if (prevX != _X || prevY != _Y) {
            GotoXY(prevX - 1, prevY);
            if (_A[prevRow][prevCol].c == -1) {
                txtColor((15 << 4) | 4);
                cout << " X ";
            }
            else if (_A[prevRow][prevCol].c == 1) {
                txtColor((15 << 4) | 1);
                cout << " O ";
            }
            else {
                txtColor((15 << 4) | 1);
                cout << "   ";
            }
        }
        GotoXY(_X - 1, _Y);
        changeColorCursor(_TURN);
        GotoXY(_X, _Y);
        prevX = _X;
        prevY = _Y;
        _COMMAND = toupper(_getch());
        if (_COMMAND == 'A' || _COMMAND == 75) MoveLeft();
        else if (_COMMAND == 'D' || _COMMAND == 77) MoveRight();
        else if (_COMMAND == 'W' || _COMMAND == 72) MoveUp();
        else if (_COMMAND == 'S' || _COMMAND == 80) MoveDown();
        else if (_COMMAND == 13) {
            if (isMusicOn) PlayMove("move.wav", L"move_sound");
            int row = (_Y - TOP - 1) / 2, col = (_X - LEFT - 2) / 4;
            result = CheckBoard(_X, _Y);
            if (result != 0) {
                value = 1;
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
                    value = 2;
                    txtColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) {
                        if (isMusicOn) PlayWin("win.wav", L"win_sound");
                        TableResult(win_x, win_y, run_x, run_y);
                        ve3();
                    }
                    else if (gameResult == -1) {
                        if (isMusicOn) PlayWin("win.wav", L"win_sound");
                        win_x++;
                        TableResult(win_x, win_y, run_x, run_y);
                        nhapnhay(winPositions, 'X');
                        ve();
                    }
                    else {
                        if (isMusicOn) PlayWin("win.wav", L"win_sound");
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
        else if (_COMMAND == 'R') {
            if (result == -1 || result == 1) {
                if (result == 1) run_y--;
                else if (result == -1) run_x--;
                GotoXY(xUndo, yUndo);
                txtColor((15 << 4) | 4);
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
        else if (_COMMAND == 27) {

            value = 3;
            PauseMenu();
            kt = 0;
        }
        TableResult(win_x, win_y, run_x, run_y);
    }
    fclose(tempFile);
}
// pause function
void ResumeGame(int gameOption) {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    char playMode, posXO;
    int posX = 0, posY = 0;
    FILE* tempFileRead = fopen("Temporary.txt", "rt");
    if (curlang == 0) {
        if (!tempFileRead) {
            cerr << "Error opening temporary save files!";
            return;
        }
        if (fscanf(tempFileRead, "%c ", &playMode) != 1) {
            fclose(tempFileRead);
            cerr << "Error reading play mode!";
            return;
        }
    }
    else {
        if (!tempFileRead) {
            cerr << "Loi mo file luu tam thoi!";
            return;
        }
        if (fscanf(tempFileRead, "%c ", &playMode) != 1) {
            fclose(tempFileRead);
            cerr << "Loi doc file che do choi!";
            return;
        }
    }
   
    int xCount = 0, oCount = 0;
    while (fscanf(tempFileRead, "%c(%d,%d) ", &posXO, &posX, &posY) != EOF) {
        int row = (posY - TOP - 1) / 2, col = (posX - LEFT - 2) / 4;
        GotoXY(posX, posY);
        if (posXO == 'X') {
            txtColor((15 << 4) | 4); cout << "X";
            _A[row][col].c = -1;
            xCount++;
            xUndo = posX; yUndo = posY;
        }
        else if (posXO == 'O') {
            txtColor((15 << 4) | 1);
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
    if (playMode == 'p') PlayGame(1, win_x, win_y, pretime);
    else if (playMode == 'b') PlaywithBot(1, win_x, win_y, pretime);
    else if (gameOption == 1) PlayGame(0, win_x, win_y, pretime);
    else if (gameOption == 2) PlaywithBot(0, win_x, win_y, pretime);
}
void SaveGameName() {
    int x = menu1_x - 5, y = menu1_y - 7, i = 0;
    GotoXY(x + 7, y + 6);
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
        if (curlang == 0) {
            cout << "Invalid input!";
        }
        else {
            cout << "Nhap khong hop le";
        }
       
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
        systemtime[numSaveFile - 1] = readSystemTime(numSaveFile - 1);
        statsSF[numSaveFile - 1] = readSumOfTime(numSaveFile - 1);
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
int getNumSaveFile(char savefiles[][MAX_FILE_LENGTH + 1]) {
    int count = 0;
    char buffer[2000], ch[20];
    allSaveFiles = fopen("allSaveFiles.txt", "rt");
    while (fgets(ch, MAX_FILE_LENGTH + 1, allSaveFiles) != NULL) {
        ch[strcspn(ch, "\n")] = '\0';
        strcpy(savefiles[count++], ch);
        fgets(buffer, sizeof(buffer), allSaveFiles);
        playModeGame[count - 1] = buffer[0];
    }
    fclose(allSaveFiles);
    pageMax = (count - 1) / 10 + 1;

    return count;
}
bool checkDuplicate(char filename[]) {
    for (int i = 0; i < MAX_FILE_SAVE; i++) {
        if (strcmp(filename, savefiles[i]) == 0) return true;
    }
    return false;
}
SystemTime getSystemTime() {
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    SystemTime currentTime;
    currentTime.day = local->tm_mday;
    currentTime.month = local->tm_mon + 1;
    currentTime.year = local->tm_year + 1900;
    currentTime.hour = local->tm_hour;
    currentTime.minute = local->tm_min;
    currentTime.second = local->tm_sec;
    return currentTime;
}
void writeSystemTime() {
    FILE* SystemTimeManage = fopen("TimeManage.txt", "a");
    if (!SystemTimeManage) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
    SystemTime now = getSystemTime();
    fprintf(SystemTimeManage, "%d/%d/%d %d:%d:%d\n", now.day, now.month, now.year, now.hour, now.minute, now.second);
    fclose(SystemTimeManage);
}
SystemTime readSystemTime(int numTimes) {
    writeSystemTime();
    SystemTime save;
    char buffer[25];
    FILE* SystemTimeManage = fopen("TimeManage.txt", "r");
    if (!SystemTimeManage) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
    }
    else {
        for (int i = 0; i < numTimes; i++) fgets(buffer, 25, SystemTimeManage);
        if (fscanf(SystemTimeManage, "%d/%d/%d %d:%d:%d\n", &save.day, &save.month, &save.year,
            &save.hour, &save.minute, &save.second) != 6) {
            if (curlang == 0) {
                cerr << "Error opening file.";
            }
            else cerr << "Loi doc file!";
        }
        fclose(SystemTimeManage);
        return save;
    }
}
void TimeMagToArray() {
    FILE* timeMag = fopen("TimeManage.txt", "r");
    SystemTime save;
    int i = 0;
    if (!timeMag) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
    while (fscanf(timeMag, "%d/%d/%d %d:%d:%d\n", &save.day, &save.month, &save.year,
        &save.hour, &save.minute, &save.second) == 6) {
        systemtime[i++] = save;
    }
    fclose(timeMag);
}

void getStats() {
    strcpy(TempStat.nameP1, name1);
    strcpy(TempStat.nameP2, name2);
    TempStat.isTurnP1 = turn_x;
    TempStat.numP1 = run_x;
    TempStat.numP2 = run_y;
    TempStat.winP1 = win_x;
    TempStat.winP2 = win_y;
    TempStat.sumSeconds = sum.seconds;
    TempStat.sumMinutes = sum.minutes;
    TempStat.countdown = cnttime;
}
void writeSumOfTime() {
    FILE* stats = fopen("Stats.txt", "a");
    if (!stats) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
    getStats();
    fprintf(stats, "%s %s %d, %d, %d, %d, %d, %d, %d %d\n", TempStat.nameP1, TempStat.nameP2, TempStat.isTurnP1, TempStat.numP1, TempStat.numP2, TempStat.winP1, TempStat.winP2, TempStat.sumSeconds, TempStat.sumMinutes, TempStat.countdown);
    fclose(stats);
}
Stats readSumOfTime(int numTimes) {
    writeSumOfTime();
    Stats a;
    char bufferChar[100];
    int bufferInt;
    FILE* stats = fopen("Stats.txt", "r");
    if (!stats) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
    }
    else {
        for (int i = 0; i < numTimes; i++) fgets(bufferChar, 100, stats);
        if (fscanf(stats, "%s %s %d, %d, %d, %d, %d, %d, %d %d\n", &a.nameP1, &a.nameP2, &a.isTurnP1, &a.numP1, &a.numP2, &a.winP1, &a.winP2, &a.sumSeconds, &a.sumMinutes, &a.countdown) != 10)
            if (curlang == 0) {
                cerr << "Error opening file.";
            }
            else cerr << "Loi mo file!";
        fclose(stats);
        return a;
    }
}
void statsToArray() {
    FILE* a = fopen("Stats.txt", "r");
    int i = 0;
    Stats save;
    if (!a) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
   while (fscanf(a, "%s %s %d, %d, %d, %d, %d, %d, %d %d\n", &save.nameP1, &save.nameP2, &save.isTurnP1, &save.numP1, &save.numP2, &save.winP1, &save.winP2, &save.sumSeconds, &save.sumMinutes, &save.countdown) == 10) {
           statsSF[i++] = save;
    }
    fclose(a);
}
bool isValidName(char filename[]) {
    if (filename[0] == '\0') return false;
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] != ' ') return true;
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
    while ((ch = fgetc(tempFile)) != EOF) fputc(ch, allSaveFiles);
    fputc('\n', allSaveFiles);
    fclose(allSaveFiles);
    fclose(tempFile);
}
void SaveGameMenu() {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    int x = menu1_x - 15 + 10, y = menu1_y - 12 + 5, w = 30, h = 10;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    if (curlang == 0) {
        if (!currentSaveFile.empty()) {
            confirmOverwrite();
            
        }
        else {
            GotoXY(x + 6, y + 2); cout << "NAME YOUR SAVE FILE:";
            txtColor(112);
            GotoXY(x + 6, y + 3); cout << "( <= 14 characters )";
            GotoXY(x + 5, y + 9); cout << "Press Esc to go back.";
            txtColor(116);
            DrawRoundedBox(x + 3, y + 5, 25, 3, 0);
            while (true) {
                SaveGameName();
                if (toupper(_getch()) == 27) break;
            }
        };
    }
    else {
        if (!currentSaveFile.empty()) {
            confirmOverwrite();
            
        }
        else {
            GotoXY(x + 6, y + 2); cout << "Nhap Ten File:";
            txtColor(112);
            GotoXY(x + 6, y + 3); cout << "( <= 14 ky tu )";
            GotoXY(x + 5, y + 9); cout << "Nhan ESC de tro lai.";
            txtColor(116);
            DrawRoundedBox(x + 3, y + 5, 25, 3, 0);
            while (true) {
                SaveGameName();
                if (toupper(_getch()) == 27) break;
            }
        }
    }
}
void confirmOverwrite() {
    if (curlang == 0) {
        int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
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
            else if (c == 13) {
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
    else {
        int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
        txtColor(112);
        GotoXY(x + 8, y + 8); cout << "Co";
        GotoXY(x + 23, y + 8); cout << "Khong";
        GotoXY(x + 8, y + 4); cout << " HANH DONG NAY";
        GotoXY(x + 9, y + 5); cout << "KHONG THE HOAN TAC!";
        txtColor(116);
        GotoXY(x + 13, y + 3); cout << "CANH BAO:";
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
            else if (c == 13) {
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
}
void overwriteSF() {
    strcpy(filename, savefiles[optionSF - 1]);
    writeTempToSF();
    char buffer[2000];
    tempFile = fopen("Temporary.txt", "r");
    if (!tempFile) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
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
    systemtime[numSaveFile - 1] = readSystemTime(numSaveFile - 1);
    statsSF[numSaveFile - 1] = readSumOfTime(numSaveFile - 1);
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
            if (board[i][j].c == 0) return false;
        }
    }
    return true;
}
int TestBoard(int row, int col, int winPositions[5][2]) {
    if (isFull(_A)) return 0;
    else {
        if (checkWin(row, col, winPositions)) return (_TURN ? -1 : 1);
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
void StartGame(int k, int cnttime) {
    system("cls");
    run_x = 0;
    run_y = 0;
    h = 1;
    ResetData();
    DrawBoard(BOARD_SIZE);
    newGame = true;
    currentSaveFile = "";
    PlayGame(k, win_x, win_y, cnttime);
}
void StartGamewithbot(int k, int cnttime) {
    system("cls");
    ResetData();
    run_x = 0;
    run_y = 0;
    DrawBoard(BOARD_SIZE);
    newGame = true;
    currentSaveFile = "";
    PlaywithBot(k, win_x, win_y, cnttime);
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
void loadGameState(char filename[]) {
    currentSaveFile = filename;
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    allSaveFiles = fopen("allSaveFiles.txt", "rt");
    tempFile = fopen("Temporary.txt", "wt");
    if (!allSaveFiles) {
        if (curlang == 0) {
            cerr << "Error opening save files!";
        }
        else {
            cerr << "Loi trong viec mo file!";
        }
        return;
    }
    char saveName[MAX_FILE_LENGTH + 1], posXO, gameMode;
    char* saveMove = new char[5000];
    int posX = 0, posY = 0, buffer;
    while (fgets(saveName, MAX_FILE_LENGTH + 1, allSaveFiles) != NULL) {
        saveName[strcspn(saveName, "\n")] = '\0';
        if (strcmp(saveName, filename) == 0) break;
        fgets(saveMove, 5000, allSaveFiles);
        saveMove[strcspn(saveMove, "\n")] = '\0';
    }
    buffer = fscanf(allSaveFiles, "\n%c ", &gameMode);
    fprintf(tempFile, "%c ", gameMode);
    while (fscanf(allSaveFiles, "%c(%d,%d) ", &posXO, &posX, &posY) != EOF) {
        if (posXO != 'X' && posXO != 'O' && posXO != 'U') break;
        fprintf(tempFile, "%c(%d,%d) ", posXO, posX, posY);
        int row = (posY - TOP - 1) / 2;
        int col = (posX - LEFT - 2) / 4;
        GotoXY(posX, posY);
        if (posXO == 'X') {
            txtColor((15 << 4) | 4);
            cout << "X";
            _A[row][col].c = -1;
            xUndo = posX;
            yUndo = posY;
        }
        else if (posXO == 'O') {
            txtColor((15 << 4) | 1);
            cout << "O";
            _A[row][col].c = 1;
            xUndo = posX;
            yUndo = posY;
        }
        else if (posXO == 'U') {
            cout << " ";
            _A[row][col].c = 0;
        }
    }
    fclose(allSaveFiles);
    fclose(tempFile);
    int xCount = 0, oCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == -1) xCount++;
            else if (_A[i][j].c == 1) oCount++;
        }
    }
    _TURN = (xCount > oCount) ? false : true;
    newGame = false;
    delete[] saveMove;

    statsToArray();
    win_x = statsSF[optionSF - 1].winP1;
    win_y = statsSF[optionSF - 1].winP2;
    run_x = statsSF[optionSF - 1].numP1;
    run_y = statsSF[optionSF - 1].numP2;
    sum.minutes = statsSF[optionSF - 1].sumMinutes;
    sum.seconds = statsSF[optionSF - 1].sumSeconds;
    strcpy(name1, statsSF[optionSF - 1].nameP1);
    strcpy(name2, statsSF[optionSF - 1].nameP2);
    switch (statsSF[optionSF - 1].countdown) {
    case 1:
        pretime = 15;
        break;
    case 2:
        pretime = 30;
        break;
    case 3:
        pretime = -1;
        break;
    }
    if (gameMode == 'p') PlayGame(1, win_x, win_y, pretime);
    else if (gameMode == 'b') PlaywithBot(1, win_x, win_y, pretime);
}
void deleteSaveFile(char* filename) {
    tempFile = fopen("Temporary.txt", "w");
    allSaveFiles = fopen("allSaveFiles.txt", "r");
    char buffer[2000];
    if (!tempFile || !allSaveFiles) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        if (tempFile) fclose(tempFile);
        if (allSaveFiles) fclose(allSaveFiles);
        return;
    }
    for (int i = 0; i < 2 * (optionSF - 1); i++) {
        if (fgets(buffer, sizeof(buffer), allSaveFiles)) fputs(buffer, tempFile);
    }
    fgets(buffer, sizeof(buffer), allSaveFiles);
    fgets(buffer, sizeof(buffer), allSaveFiles);
    while (fgets(buffer, sizeof(buffer), allSaveFiles)) fputs(buffer, tempFile);
    fclose(tempFile);
    fclose(allSaveFiles);
    tempFile = fopen("Temporary.txt", "r");
    allSaveFiles = fopen("allSaveFiles.txt", "w");
    if (!tempFile || !allSaveFiles) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        if (tempFile) fclose(tempFile);
        if (allSaveFiles) fclose(allSaveFiles);
        return;
    }
    while (fgets(buffer, sizeof(buffer), tempFile)) fputs(buffer, allSaveFiles);
    fclose(tempFile);
    fclose(allSaveFiles);
    numSaveFile = getNumSaveFile(savefiles);
    FILE* system = fopen("TimeManage.txt", "r");
    tempFile = fopen("Temporary.txt", "w");
    char bufferT[25];
    if (!system || !tempFile) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        if (system) fclose(system);
        if (tempFile) fclose(tempFile);
        return;
    }
    for (int i = 0; i < optionSF - 1; i++) {
        if (fgets(bufferT, sizeof(bufferT), allSaveFiles)) fputs(bufferT, tempFile);
    }
    fgets(buffer, sizeof(buffer), allSaveFiles);
    while (fgets(bufferT, sizeof(bufferT), allSaveFiles)) fputs(bufferT, tempFile);
    fclose(system);
    fclose(tempFile);
    system = fopen("TimeManage.txt", "w");
    tempFile = fopen("Temporary.txt", "r");
    if (!system || !tempFile) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        if (system) fclose(system);
        if (tempFile) fclose(tempFile);
        return;
    }
    while (fgets(buffer, sizeof(buffer), tempFile)) fputs(buffer, allSaveFiles);
    TimeMagToArray();
    fclose(system);
    fclose(tempFile);

    FILE* stats = fopen("Stats.txt", "r");
    tempFile = fopen("Temporary.txt", "w");
    char bufferrStats[50];
    if (!stats) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
    for (int i = 0; i < optionSF - 1; i++) {
        if (fgets(bufferrStats, sizeof(bufferrStats), stats)) fputs(bufferrStats, tempFile);
    }
    fgets(bufferrStats, sizeof(bufferrStats), stats);
    while (fgets(bufferrStats, sizeof(bufferrStats), stats)) fputs(bufferrStats, tempFile);
    fclose(stats);
    fclose(tempFile);
    stats = fopen("Stats.txt", "w");
    tempFile = fopen("Temporary.txt", "r");
    if (!tempFile) {
        if (curlang == 0) {
            cerr << "Error opening file.";
        }
        else cerr << "Loi mo file!";
        return;
    }
    while (fgets(bufferrStats, sizeof(bufferrStats), tempFile)) fputs(bufferrStats, stats);
    statsToArray();
    fclose(stats);
    fclose(tempFile);
}
void confirmMenu() {
    if (curlang == 0) {
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
        txtColor((0 << 4) | 15);
        if (x == menu1_x - 7) {
            GotoXY(menu1_x - 7 + 7, y + 5); cout << "Yes";
        }
        else {
            GotoXY(menu1_x - 7 + 25, y + 5); cout << "No";
        }
        while (kt == 1) {
            char c = toupper(_getch());
            if (c == 'A' || c == 'D' || c == 75 || c == 77) {
                txtColor(112);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 7, y + 5); cout << "Yes";
                }
                else {
                    GotoXY(menu1_x - 7 + 25, y + 5); cout << "No";
                }
                if (x == menu1_x - 7) x = menu1_x + 11;
                else if (x == menu1_x + 11) x = menu1_x - 7;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 7, y + 5); cout << "Yes";
                }
                else {
                    GotoXY(menu1_x - 7 + 25, y + 5); cout << "No";
                }
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
    else {
        int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        txtColor(112);
        GotoXY(x + 7, y + 5); cout << "Co";
        GotoXY(x + 25, y + 5); cout << "Khong";
        GotoXY(x + 4, y + 3); cout << "Hanh dong khong the hoan tac!";
        txtColor(116);
        GotoXY(x + 13, y + 2); cout << "CANH BAO:";
        txtColor((0 << 4) | 15);
        if (x == menu1_x - 7) {
            GotoXY(menu1_x - 7 + 7, y + 5); cout << "Co";
        }
        else {
            GotoXY(menu1_x - 7 + 25, y + 5); cout << "Khong";
        }
        while (kt == 1) {
            char c = toupper(_getch());
            if (c == 'A' || c == 'D' || c == 75 || c == 77) {
                txtColor(112);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 7, y + 5); cout << "Co";
                }
                else {
                    GotoXY(menu1_x - 7 + 25, y + 5); cout << "Khong";
                }
                if (x == menu1_x - 7) x = menu1_x + 11;
                else if (x == menu1_x + 11) x = menu1_x - 7;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 7, y + 5); cout << "Co";
                }
                else {
                    GotoXY(menu1_x - 7 + 25, y + 5); cout << "Khong";
                }
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
}
void loadOrDeleteMenu() {
    if (curlang == 0) {
        int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        txtColor(112);
        GotoXY(x + 8, y + 3); cout << "Load";
        GotoXY(x + 22, y + 3); cout << "Delete";
        txtColor(116);
        GotoXY(x + 8, y + 5); cout << "Press Esc to go back.";
        txtColor((0 << 4) | 15);
        if (x == menu1_x - 7) {
            GotoXY(menu1_x - 7 + 8, y + 3); cout << "Load";
        }
        else {
            GotoXY(menu1_x - 7 + 22, y + 3); cout << "Delete";
        }
        while (kt == 1) {
            char c = toupper(_getch());
            if (c == 'A' || c == 'D' || c == 75 || c == 77) {
                txtColor((7 << 4) | 0);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 8, y + 3); cout << "Load";
                }
                else {
                    GotoXY(menu1_x - 7 + 22, y + 3); cout << "Delete";
                }
                if (x == menu1_x - 7) x = menu1_x + 8;
                else if (x == menu1_x + 8) x = menu1_x - 7;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 8, y + 3); cout << "Load";
                }
                else {
                    GotoXY(menu1_x - 7 + 22, y + 3); cout << "Delete";
                }
            }
            else if (c == 27) {
                if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                LoadGame();
                kt = 0;
            }
            else if (c == 13) {
                if (x == menu1_x - 7) {
                    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                    loadGameState(savefiles[optionSF - 1]);
                    break;
                }
                else if (x == menu1_x + 8) {
                    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                    confirmMenu();
                    break;
                }
            }
        }
    }
    else {
        int x = menu1_x - 7, y = menu1_y - 8, w = 35, h = 7, kt = 1;
        DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
        DrawFull(x, y, w, h, 195, 197);
        DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
        txtColor(112);
        GotoXY(x + 8, y + 3); cout << "Tai";
        GotoXY(x + 22, y + 3); cout << "Xoa";
        txtColor(116);
        GotoXY(x + 8, y + 5); cout << "Nhan ESC de quay tro lai.";
        txtColor((0 << 4) | 15);
        if (x == menu1_x - 7) {
            GotoXY(menu1_x - 7 + 8, y + 3); cout << "Tai";
        }
        else {
            GotoXY(menu1_x - 7 + 22, y + 3); cout << "Xoa";
        }
        while (kt == 1) {
            char c = toupper(_getch());
            if (c == 'A' || c == 'D' || c == 75 || c == 77) {
                txtColor((7 << 4) | 0);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 8, y + 3); cout << "Tai";
                }
                else {
                    GotoXY(menu1_x - 7 + 22, y + 3); cout << "Xoa";
                }
                if (x == menu1_x - 7) x = menu1_x + 8;
                else if (x == menu1_x + 8) x = menu1_x - 7;
                if (isMusicOn) PlayTick("tick.wav", L"tick_sound");
                txtColor((0 << 4) | 15);
                if (x == menu1_x - 7) {
                    GotoXY(menu1_x - 7 + 8, y + 3); cout << "Tai";
                }
                else {
                    GotoXY(menu1_x - 7 + 22, y + 3); cout << "Xoa";
                }
            }
            else if (c == 27) {
                if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                LoadGame();
                kt = 0;
            }
            else if (c == 13) {
                if (x == menu1_x - 7) {
                    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                    loadGameState(savefiles[optionSF - 1]);
                    break;
                }
                else if (x == menu1_x + 8) {
                    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
                    confirmMenu();
                    break;
                }
            }
        }
    }
}
void LoadGameSelection(bool isNew) {
    int findSF[MAX_FILE_SAVE] = {};
    numSaveFile = getNumSaveFile(savefiles);
    int x = menu1_x + 16, y = menu1_y + 18, w = 60, h = 19, move, kt = 1;
    int numFindSF = numSaveFile;
    GotoXY(x + 54, y - 25); printf("%2d", numFindSF);
    if (isNew) {
        pageNumber = 1;
        optionSF = 1;
        for (int i = 0; i < MAX_FILE_SAVE; i++) findSF[i] = 0;
    }
    while (kt == 1) {
        int savePerPage = (numSaveFile > 10 * pageNumber) ? 10 * pageNumber : numSaveFile;
        int startPrint = 1;
        for (int i = 1 + (pageNumber - 1) * 10; i <= savePerPage; i++) {
            if (i == 11 + (pageNumber - 1) * 10) break;
            GotoXY(x + 2, y - 15 + startPrint);
            if (i == optionSF) txtColor((0 << 4) | 14);
            else if (findSF[i - 1] == 1) txtColor((0 << 4) | 15);
            else txtColor((7 << 4) | 0);
            char ch[5];
            if (playModeGame[i - 1] == 'p') strcpy(ch, "PvP");
            else strcpy(ch, "PvE");
            printf("%-21s %-10s %02d/%02d/%04d %02d:%02d:%02d",
                savefiles[i - 1],
                ch,
                systemtime[i - 1].day,
                systemtime[i - 1].month,
                systemtime[i - 1].year,
                systemtime[i - 1].hour,
                systemtime[i - 1].minute,
                systemtime[i - 1].second);
            startPrint++;
        }
        move = _getch(); move = toupper(move);
        if (move == 80 || move == 'S') optionSF = (optionSF == savePerPage) ? (pageNumber - 1) * 10 + 1 : optionSF + 1;
        else if (move == 72 || move == 'W') optionSF = (optionSF == (pageNumber - 1) * 10 + 1) ? savePerPage : optionSF - 1;
        else if ((move == 77 || move == 'D') && pageNumber != pageMax) {
            optionSF = pageNumber * 10 + 1;
            pageNumber++;
            DrawFull(x, y - 19, w + 1, h, 136, 32);
            DrawFull(x - 2, y - 20, w, h, 195, 197);
            DrawFull(x, y - 19, w - 4, h - 2, 119, 32);
            if (curlang == 0) {
                GotoXY(x + 25, y - 18); cout << "Page " << pageNumber;
                GotoXY(x + 9, y - 3); cout << "Press Esc to turn back to the main Menu...";
                GotoXY(x + 6, y - 16); printf("%s%20s%16s", "NAME", "GAME MODE", "TIME");
            }
            else {
                GotoXY(x + 25, y - 18); cout << "Trang " << pageNumber;
                GotoXY(x + 9, y - 3); cout << "  An Esc de tro ve Menu chinh...";
                GotoXY(x + 6, y - 16); printf("%s%20s%16s", "TEN", "CHE DO CHOI", "THOI GIAN");
            }

        }
        else if ((move == 75 || move == 'A') && pageNumber != 1) {
            pageNumber--;
            optionSF = (pageNumber - 1) * 10 + 1;
            DrawFull(x, y - 19, w + 1, h, 136, 32);
            DrawFull(x - 2, y - 20, w, h, 195, 197);
            DrawFull(x, y - 19, w - 4, h - 2, 119, 32);
            if (curlang == 0) {
                GotoXY(x + 25, y - 18); cout << "Page " << pageNumber;
                GotoXY(x + 9, y - 3); cout << "Press Esc to turn back to the main Menu...";
                GotoXY(x + 6, y - 16); printf("%s%20s%16s", "NAME", "GAME MODE", "TIME");
            }
            else {
                GotoXY(x + 25, y - 18); cout << "Trang " << pageNumber;
                GotoXY(x + 9, y - 3); cout << "     An Esc de tro ve Menu chinh...";
                GotoXY(x + 6, y - 16); printf("%s%20s%16s", "TEN", "CHE DO CHOI", "THOI GIAN");
            }
        }
        else if (move == 13) {
            if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
            loadOrDeleteMenu();
            kt = 0;
        }
        else if (move == 27) {
            if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
            printMenu();
            kt = 0;
        }
        else if (move == 'F' || move == 70) {
            numFindSF = 0;
            char findName[MAX_FILE_LENGTH + 1];
            int i = 0;
            txtColor(116);
            GotoXY(x + 7, y - 25); cout << "               ";
            GotoXY(x + 7, y - 25);
            while (true) {
                if (_kbhit()) {
                    char key = _getch();
                    if (key == 27) {
                        LoadGame();
                        return;
                    }
                    if (key == '\r') {
                        findName[i] = '\0';
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
                        findName[i++] = key;
                    }
                }
            }
            for (int i = 0; i < numSaveFile; i++) {
                if (strstr(savefiles[i], findName) != nullptr) {
                    findSF[i] = 1;
                    numFindSF++;
                }
                else findSF[i] = 0;
            }
            GotoXY(x + 54, y - 25); printf("%2d", numFindSF);
        }
    }
}
void LoadGame() {
    system("cls");
    system("color F0");
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    drawPinkBox2(5, 2);
    if (curlang == 0) {
        load(10, 6);
    }
    else taigame(60, 4);
    drawPikachu2(40, 20);
    muiten(5, 37);
    int x = menu1_x + 14, y = menu1_y - 2, w = 60, h = 19;
    numSaveFile = getNumSaveFile(savefiles);
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    if (curlang == 0) {
        GotoXY(x + 27, y + 2); cout << "Page 1";
        GotoXY(x + 11, y + 17); cout << "Press Esc to turn back to the main Menu...";
        if (numSaveFile == 0) {
            txtColor(112);
            GotoXY(x + 16, y + 5); cout << "No save file yet.";
            txtColor(116);
            while (char command = _getch()) {
                if (command == 27) printMenu();
            }
        }
        else {
            TimeMagToArray();
            GotoXY(x + 8, y + 4); printf("%s%20s%16s", "NAME", "GAME MODE", "TIME");
        }
    }
    else {
        GotoXY(x + 27, y + 2); cout << "Trang 1";
        GotoXY(x + 11, y + 17); cout << "     An Esc de tro ve Menu chinh...";
        if (numSaveFile == 0) {
            txtColor(112);
            GotoXY(x + 16, y + 5); cout << "Chua co file luu nao";
            txtColor(116);
            while (char command = _getch()) {
                if (command == 27) printMenu();
            }
        }
        else {
            TimeMagToArray();
            GotoXY(x + 8, y + 4); printf("%s%20s%16s", "TEN", "CHE DO CHOI", "THOI GIAN");
        }
    }
    if (curlang == 0) {
        loadMenuPlus();
    }
    else {
        loadMenuPlusV();
    }
    LoadGameSelection(true);
}
// play with bot
int evaluatePosition(int row, int col, int player) {
    int score = 0, dx[] = { 0, 1, 1, 1 }, dy[] = { 1, 0, 1, -1 };
    for (int dir = 0; dir < 4; ++dir) {
        int count = 1, block = 0;
        for (int step = 1; step <= 4; ++step) {
            int nx = row + step * dx[dir], ny = col + step * dy[dir];
            if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != player) {
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != 0)
                    block++;
                break;
            }
            count++;
        }
        for (int step = 1; step <= 4; ++step) {
            int nx = row - step * dx[dir], ny = col - step * dy[dir];
            if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != player) {
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE || _A[nx][ny].c != 0)
                    block++;
                break;
            }
            count++;
        }
        if (count >= 5) score += 10000;
        else if (block == 0) score += count * count;
        else if (block == 1) score += count;
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
void cursorBot(int _X, int _Y, int& preX, int& preY) {
    txtColor((15 << 4) | 4);
    GotoXY(_X - 1, _Y); cout << "[";
    GotoXY(_X + 1, _Y); cout << "]";
    int prevRow = (preY - TOP - 1) / 2, prevCol = (preX - LEFT - 2) / 4;
    if (preX != _X || preY != _Y) {
        GotoXY(preX - 1, preY);
        if (_A[prevRow][prevCol].c == -1) {
            txtColor((15 << 4) | 4); cout << " X ";
        }
        else if (_A[prevRow][prevCol].c == 1) {
            txtColor((15 << 4) | 1); cout << " O ";
        }
        else {
            txtColor((15 << 4) | 1); cout << "   ";
        }
    }
    preX = _X;
    preY = _Y;
    GotoXY(_X, _Y);
}
void LoadingEffect(int Lx, int Ly, int duration) {
    txtColor((15 << 4) | 1);
    GotoXY(Lx, Ly - 1);
    cout << "Loading...";
    for (int i = 0; i < duration; ++i) {
        GotoXY(Lx + i, Ly);
        cout << char(219);
        Sleep(100);
    }
    GotoXY(Lx, Ly);
    for (int i = 0; i < duration; i++)
    {
        cout << " ";
    }
    GotoXY(Lx, Ly - 1);
    cout << "          ";
    txtColor(7);
}

void PlaywithBot(int k, int& win_x, int& win_y, int cnttime) {
    if (isMusicOn) PlayMo("mo.wav", L"mo_sound");
    hideCursor();
    SmallMenu(6, TOP - 2);
    drawSmallCloud(1, 39);
    drawPhuthuy(5, 20);
    drawStart(75, 1);
    drawEnd(75, 45);
    int xUndo, yUndo, kt = 1;
    value = 0;
    result = 0;
    bool validEnter = true;

    int preX = _X, preY = _Y;
    txtColor((15 << 4) | 4);
    GotoXY(_X - 1, _Y); cout << "[";
    GotoXY(_X + 1, _Y); cout << "]";
    if (k == 0) {
        tempFile = fopen("Temporary.txt", "w");
        fprintf(tempFile, "b ");
        fflush(tempFile);
        win_x = 0; win_y = 0;
        sum.minutes = 0;
        sum.seconds = 0;
    }
    else
    {
        tempFile = fopen("Temporary.txt", "a");
        newGame = false;
    }
    pretime = cnttime;
    if (cnttime == -1)
    {
        value = 4;
    }


    thread clock_XO(CountTime_XO, ref(XO), BOARD_SIZE * 5 + LEFT + 7, TOP + 24, ref(value), cnttime);
    clock_XO.detach();
    thread clock_sum(Count_sumTime, ref(sum), BOARD_SIZE * 5 + LEFT + 6, TOP + 23, ref(value));
    clock_sum.detach();
    drawTableResult();
    TableResult(win_x, win_y, run_x, run_y);
    DrawIsX(BOARD_SIZE * 5 + LEFT, TOP - 1);
    DrawNotO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
    int shortSecs = 0;
    int delayMiliSecs = cnttime * 1000;    
    while (kt == 1) {
        while (_TURN == true) {
            shortSecs = 0;
            while (shortSecs < delayMiliSecs || cnttime == -1) {
                if (cnttime != -1) {
                    Sleep(100);
                    shortSecs += 100;
                }
                if (_kbhit()) {
                    _COMMAND = toupper(_getch());
                    if (_COMMAND == 27) {
                        value = 3;
                        PauseMenu();
                        kt = 0;
                    }
                    else if (_COMMAND == 'A' || _COMMAND == 75) {
                        MoveLeft();
                        cursorBot(_X, _Y, preX, preY);
                    }
                    else if (_COMMAND == 'D' || _COMMAND == 77) {
                        MoveRight();
                        cursorBot(_X, _Y, preX, preY);
                    }
                    else if (_COMMAND == 'W' || _COMMAND == 72) {
                        MoveUp();
                        cursorBot(_X, _Y, preX, preY);
                    }
                    else if (_COMMAND == 'S' || _COMMAND == 80) {
                        MoveDown();
                        cursorBot(_X, _Y, preX, preY);
                    }
                    else if (_COMMAND == 13) {
                        if (isMusicOn) PlayMove("move.wav", L"move_sound");
                        value = 1;
                        run_x++;
                        DrawIsX(BOARD_SIZE * 5 + LEFT, TOP - 1);
                        DrawNotO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
                        result = CheckBoard(_X, _Y);
                        if (result != 0) {
                            GotoXY(_X, _Y);
                            txtColor((15 << 4) | 4); cout << 'X';
                            fprintf(tempFile, "X(%d,%d) ", _X, _Y);
                            fflush(tempFile);
                            xUndo = _X;
                            yUndo = _Y;
                            int row = (_Y - TOP - 1) / 2, col = (_X - LEFT - 2) / 4;
                            int winPositions[5][2], gameResult = TestBoard(row, col, winPositions);
                            if (gameResult != 2) {
                                value = 2;
                                GotoXY(0, BOARD_SIZE * 2 + 2);
                                if (gameResult == 0) ve3();
                                else {
                                    if (gameResult == -1) {
                                        if (isMusicOn) PlayWin("win.wav", L"win_sound");
                                        win_x++;
                                        TableResult(win_x, win_y, run_x, run_y);
                                        nhapnhay(winPositions, 'X');
                                        ve();
                                    }
                                    else {
                                        if (isMusicOn) PlayWin("win.wav", L"win_sound");
                                        win_y++;
                                        TableResult(win_x, win_y, run_x, run_y);
                                        nhapnhay(winPositions, 'O');
                                        ve2();
                                    }
                                }
                                AskContinuePlaybot();
                            }
                            _TURN = !_TURN;
                        }
                        break;
                    }
                }
            }
            if (_TURN) _TURN = !_TURN;
            TableResult(win_x, win_y, run_x, run_y);

            while (!_TURN) {
                int delayMiliSecsBot = 2000;

                shortSecs = 0;
                while (shortSecs < delayMiliSecsBot) {
                    Sleep(100);
                    shortSecs += 100;
                    if (_kbhit()) {
                        _COMMAND = toupper(_getch());
                        if (_COMMAND == 'R') {
                            if (result == -1 || result == 1) {
                                run_x--;
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
                if (_TURN) _TURN = !_TURN;
                if (!_TURN) {
                    value = 1;
                    int loadPosX = 100;
                    int loadPosY = 6;
                    LoadingEffect(loadPosX, loadPosY, 10);
                    int pX, pY;
                    BotMove(pX, pY);
                    result = CheckBoard(pX, pY);
                    DrawIsX(BOARD_SIZE * 5 + LEFT, TOP - 1);
                    DrawNotO(BOARD_SIZE * 5 + 37 + LEFT, TOP - 1);
                    if (result != 0) {
                        run_y++;
                        GotoXY(pX, pY);
                        txtColor((15 << 4) | 1);
                        if (isMusicOn) PlayMove("move.wav", L"move_sound");
                        cout << 'O';
                        fprintf(tempFile, "O(%d,%d) ", pX, pY);
                        fflush(tempFile);
                        int row = (pY - TOP - 1) / 2, col = (pX - LEFT - 2) / 4;
                        int winPositions[5][2], gameResult = TestBoard(row, col, winPositions);
                        if (gameResult != 2) {
                            value = 2;
                            GotoXY(0, BOARD_SIZE * 2 + 2);
                            if (gameResult == 0) {
                                ve3();
                            }
                            else {
                                if (gameResult == -1) {
                                    win_x++;
                                    TableResult(win_x, win_y, run_x, run_y);
                                    if (isMusicOn) PlayWin("win.wav", L"win_sound");
                                    nhapnhay(winPositions, 'X');
                                    ve();
                                }
                                else {
                                    if (isMusicOn) PlayWin("win.wav", L"win_sound");
                                    win_y++;
                                    TableResult(win_x, win_y, run_x, run_y);
                                    nhapnhay(winPositions, 'O');
                                    ve2();
                                }
                            }
                            AskContinuePlaybot();
                        }
                        _TURN = !_TURN;
                        if (cnttime != -1) delayMiliSecs = (cnttime - 2) * 27000 / 26;
                    }
                }
            }
            TableResult(win_x, win_y, run_x, run_y);
        }
        fclose(tempFile);
    }
}
// hieu ung noi bat chuoi x hoac o
void nhapnhay(const int winPositions[5][2], char symbol) {
    int blinkTime = 500, duration = 3000, elapsed = 0;
    const int blackBold = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
    while (elapsed < duration) {
        txtColor(blackBold);
        for (int i = 0; i < 5; ++i) {
            int x = LEFT + 2 + winPositions[i][1] * 4, y = TOP + 1 + winPositions[i][0] * 2;
            GotoXY(x, y); cout << symbol;
        }
        Sleep(blinkTime);
        txtColor(7);
        for (int i = 0; i < 5; ++i) {
            int x = LEFT + 2 + winPositions[i][1] * 4, y = TOP + 1 + winPositions[i][0] * 2;
            GotoXY(x, y); cout << ' ';
        }
        Sleep(blinkTime);
        elapsed += 2 * blinkTime;
    }
    txtColor(blackBold);
    for (int i = 0; i < 5; ++i) {
        int x = LEFT + 2 + winPositions[i][1] * 4, y = TOP + 1 + winPositions[i][0] * 2;
        GotoXY(x, y); cout << symbol;
    }
    txtColor(7);
}
void TableResult(int& win_x, int& win_y, int& run_x, int& run_y) {
    if (_TURN) turn_x = 1, turn_y = 0;
    else turn_y = 1, turn_x = 0;
    txtColor(116);
    GotoXY(N + 9, M + 6); cout << turn_x;
    GotoXY(N + 9, M + 8); cout << run_x;
    GotoXY(N + 9, M + 10); cout << win_x;
    txtColor(121);
    GotoXY(N + 49, M + 6); cout << turn_y;
    GotoXY(N + 49, M + 8); cout << run_y;
    GotoXY(N + 49, M + 10); cout << win_y;
}
void drawTableResult() {
    int t = 219, t2 = 219, t3 = 205, t4 = 179;
    txtColor(124);
    for (int i = LEFT - 2; i <= 4 * BOARD_SIZE + LEFT + 2; i++) {
        GotoXY(i, TOP - 1); cout << char(t2);
        GotoXY(i, BOARD_SIZE * 2 + TOP + 1); cout << char(t2);
    }
    for (int i = TOP; i <= BOARD_SIZE * 2 + TOP; i++) {
        GotoXY(LEFT - 1, i); cout << char(t);
        GotoXY(LEFT - 2, i); cout << char(t);
        GotoXY(4 * BOARD_SIZE + LEFT + 1, i); cout << char(t);
        GotoXY(4 * BOARD_SIZE + LEFT + 2, i); cout << char(t);
    }
    txtColor(116);
    int w = 20, h = 13;
    if (curlang == 0) {
        DrawFull(N - 2, M, 20, 13, 135, 32);
        DrawFull(N - 4, M - 1, 20, 13, 68, 32);
        DrawFull(N - 2, M, 20 - 4, 13 - 2, 121, 32);
        GotoXY(N, M + 1); cout << "   Player";
        GotoXY(N, M + 3); cout << name1;
        Box(N - 1, M + 2, 14, 2);
        GotoXY(N - 1, M + 6);
        cout << "    Turn: ";
        GotoXY(N - 1, M + 8);
        cout << "    Run: ";
        GotoXY(N - 1, M + 10);
        cout << "    Win: ";
        txtColor(121);
        DrawFull(N + 38, M, w, h, 136, 32);
        DrawFull(N + 36, M - 1, w, h, 151, 32);
        DrawFull(N + 38, M, w - 4, h - 2, 119, 32);
        txtColor(121);
        Box(N + 39, M + 2, 14, 2);
        GotoXY(N + 42, M + 1);
        if (newGameOpt == 1) {
            cout << " Player";
            GotoXY(N + 40, M + 3); cout << name2;
        }
        else {
            GotoXY(N + 45, M + 1); cout << "Bot";
        }
        GotoXY(N + 39, M + 6); cout << "    Turn: ";
        GotoXY(N + 39, M + 8); cout << "    Run: ";
        GotoXY(N + 39, M + 10); cout << "    Win: ";
        txtColor(15 * 16);
        Box(BOARD_SIZE * 5 + LEFT + 25, TOP + 18, 11, 3);
        GotoXY(BOARD_SIZE * 5 + LEFT + 26, TOP + 19);
        txtColor(15); cout << "TOTAL TIME";
        txtColor(15 * 16);
        Box(BOARD_SIZE * 5 + LEFT + 25, TOP + 22, 11, 3);
        GotoXY(BOARD_SIZE * 5 + LEFT + 26, TOP + 23); cout << "COUNTDOWN";
    }
    else {
        DrawFull(N - 2, M, 20, 13, 135, 32);
        DrawFull(N - 4, M - 1, 20, 13, 68, 32);
        DrawFull(N - 2, M, 20 - 4, 13 - 2, 121, 32);
        GotoXY(N, M + 1); cout << "  Nguoi choi";
        GotoXY(N, M + 3); cout << name1;
        Box(N - 1, M + 2, 14, 2);
        GotoXY(N - 1, M + 6);
        cout << "  Luot: ";
        GotoXY(N - 1, M + 8);
        cout << "  Tong: ";
        GotoXY(N - 1, M + 10);
        cout << "  Thang: ";
        txtColor(121);
        DrawFull(N + 38, M, w, h, 136, 32);
        DrawFull(N + 36, M - 1, w, h, 151, 32);
        DrawFull(N + 38, M, w - 4, h - 2, 119, 32);
        txtColor(121);
        Box(N + 39, M + 2, 14, 2);
        GotoXY(N + 42, M + 1);
        if (newGameOpt == 1) {
            cout << "Nguoi choi";
            GotoXY(N + 40, M + 3); cout << name2;
        }
        else {
            GotoXY(N + 45, M + 1); cout << "May";
        }
        GotoXY(N + 39, M + 6); cout << "  Luot: ";
        GotoXY(N + 39, M + 8); cout << "  Tong: ";
        GotoXY(N + 39, M + 10); cout << "  Thang: ";
        txtColor(15 * 16);
        Box(BOARD_SIZE * 5 + LEFT + 25, TOP + 18, 11, 3);
        GotoXY(BOARD_SIZE * 5 + LEFT + 26, TOP + 19);
        txtColor(15); cout << "   TONG   ";
        txtColor(15 * 16);
        Box(BOARD_SIZE * 5 + LEFT + 25, TOP + 22, 11, 3);
        txtColor(15);
        GotoXY(BOARD_SIZE * 5 + LEFT + 26, TOP + 23); cout << "  CON LAI ";
    }
}
void drawPhuthuy(int x, int y) {
    char phuthuy[22][16] = {
        "    5D         ",
        "   55DD        ",
        "  5 56D        ",
        "    55DD       ",
        "    556D       ",
        "   565DDDD     ",
        " 55555DDDDDD   ",
        "5558E3EE355    ",
        "  88EE777      ",
        "  8878747      ",
        "  8578777      ",
        "  5587778      ",
        "  5587878     3",
        " 5555787D    3 ",
        " 5555787DD  3  ",
        " 5 5557D DDE   ",
        "3E35557D  3    ",
        "33356DDD       ",
        "33355DD6       ",
        "  55DDDD       ",
        " 565D6DD       ",
        "5555DDDDD      ",
    };
    for (int i = 0; i <= 21; i++) {
        DrawLine(phuthuy[i], 15, x, y);
        y++;
    }
}
void drawStart(int x, int y) {
    char start[4][31] = {
        "              C              ",
        " C           CCC           C ",
        "C CCCCCCCCC CC CC CCCCCCCCC C",
        " C         CC   CC         C "
    };
    for (int i = 0; i <= 3; i++) {
        DrawLine(start[i], 30, x, y);
        y++;
    }
}
void drawEnd(int x, int y) {
    char end[4][31] = {
        " C         CC   CC         C ",
        "C CCCCCCCCC CC CC CCCCCCCCC C",
        " C           CCC           C ",
        "              C              "
    };
    for (int i = 0; i <= 3; i++) {
        DrawLine(end[i], 30, x, y);
        y++;
    }
}
void SmallMenu(int x, int y) {
    if (curlang == 0) {
        txtColor(15);
        Box(x - 2, y - 2, 23, 11);
        GotoXY(x, y); cout << "HOW TO PLAY :\n";
        txtColor(240);
        GotoXY(x, y + 1); cout << "R : UNDO\n";
        GotoXY(x, y + 2); cout << "W : UP\n";
        GotoXY(x, y + 3); cout << "A : LEFT\n";
        GotoXY(x, y + 4); cout << "S : DOWN\n";
        GotoXY(x, y + 5); cout << "D : RIGHT\n";
        GotoXY(x, y + 6); cout << "ESC : MORE OPTION\n";
        GotoXY(x, y + 7); cout << "ENTER : CHOOSE\n";
    }
    else {
        txtColor(15);
        Box(x - 2, y - 2, 23, 11);
        GotoXY(x, y); cout << "CACH CHOI :\n";
        txtColor(240);
        GotoXY(x, y + 1); cout << "R : QUAY LAI\n";
        GotoXY(x, y + 2); cout << "W : LEN\n";
        GotoXY(x, y + 3); cout << "A : TRAI\n";
        GotoXY(x, y + 4); cout << "S : XUONG\n";
        GotoXY(x, y + 5); cout << "D : PHAI\n";
        GotoXY(x, y + 6); cout << "ESC : THEM LUA CHON\n";
        GotoXY(x, y + 7); cout << "ENTER : CHON\n";
    }
}
