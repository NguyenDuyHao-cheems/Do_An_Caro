#include "menu.h"
#include "game.h"
#include "board.h"
#include <iostream>
#include <conio.h>

using namespace std;
int _COMMAND = 0;
void AskContinue() {
    GotoXY(0, BOARD_SIZE * 2 + 4);
    cout << "Nhan 'y' de choi tiep, phim bat ky de thoat: ";
    char c = toupper(_getch());
    if (c == 'Y') {
        StartGame();
    }
    else {
        printMenu();
    }
}
void AskContinuePlaybot() {
    GotoXY(0, BOARD_SIZE * 2 + 4);
    cout << "Nhan 'y' de choi tiep, phim bat ky de thoat: ";
    char c = toupper(_getch());
    if (c == 'Y') {
        StartGamewithbot();
    }
    else {
        printMenu();
    }
}

//ver 2
void PlayGame() {
    int result = 0;
    int xUndo, yUndo;
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    bool validEnter = true;
    while (true) {
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
        _COMMAND = toupper(_getch());
        if (_COMMAND == 27) {
            system("cls");
            return;
        }
        else if (_COMMAND == 'A') MoveLeft();
        else if (_COMMAND == 'D') MoveRight();
        else if (_COMMAND == 'W') MoveUp();
        else if (_COMMAND == 'S') MoveDown();
        else if (_COMMAND == 13) {
            result = CheckBoard(_X, _Y);
            if (result != 0) {
                GotoXY(_X, _Y);
                if (result == -1) {
                    txtColor((7<<4)|4);
                    cout << "X";
                }
                else {
                    txtColor(FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    cout << "O";
                }
                xUndo = _X;
                yUndo = _Y;
                int row = (_Y - TOP - 1) / 2;
                int col = (_X - LEFT - 2) / 4;
                int winPositions[5][2];
                int gameResult = TestBoard(row, col, winPositions);
                if (gameResult != 2) {
                    txtColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) {
                        cout << "Hoa nhau";
                        ve3();
                    }
                    else if (gameResult == -1) {
                        nhapnhay(winPositions, 'X');
                        ve();

                    }
                    else {
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
                GotoXY(xUndo, yUndo);
                std::cout << " ";
                _TURN = !_TURN;
                int row = (yUndo - TOP - 1) / 2;
                int col = (xUndo - LEFT - 2) / 4;
                _A[row][col].c = 0;
                result = 0;
            }
            GotoXY(_X, _Y);
        }
    }
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
    showCursor();
    ResetData();
    DrawBoard(BOARD_SIZE);
    PlayGame();
}
void StartGamewithbot() {
    system("cls");
    showCursor();
    ResetData();
    DrawBoard(BOARD_SIZE);
    PlaywithBot();
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
    DrawBoard(BOARD_SIZE);
    FILE* input = fopen(filename, "rt");
    if (!input)
    {
        cerr << "Error loading save file.";
        return;
    }
    char ch;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (fscanf(input, " %c-", &ch) == 1)
            {
                if (ch == 'X')
                {
                    _A[i][j].c = -1;
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    std::cout << 'X';
                }
                else if (ch == 'O')
                {
                    _A[i][j].c = 1;
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    std::cout << 'O';
                }
                else
                {
                    _A[i][j].c = 0;
                }
            }
        }
    }
    fclose(input);
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
    PlayGame();
}

void LoadGameSelection() {
    char savefiles[10][20] = { "savefile1.txt", "whatevername.txt" };
    int x = menu1_x - 15, y = menu1_y - 8;
    int move;
    int kt = 1;
    int option = 1;
    GotoXY(x + 20, y + 5);
    while (kt == 1) {
        GotoXY(x + 12, y + 5);
        std::cout << "--->";
        GotoXY(x + 33, y + 5);
        std::cout << "<---";
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S')
        {
            GotoXY(x + 12, y + 5);
            std::cout << "    ";
            GotoXY(x + 33, y + 5);
            std::cout << "    ";
            if (y == menu1_y - 7) y = menu1_y - 8;
            else y += 1;
            GotoXY(x + 12, y + 5);
            std::cout << "--->";
            GotoXY(x + 33, y + 5);
            std::cout << "<---";
            if (option == 2) option = 1;
            else option++;
        }
        if (move == 72 || move == 'W')
        {
            GotoXY(x + 12, y + 5);
            std::cout << "    ";
            GotoXY(x + 33, y + 5);
            std::cout << "    ";
            if (y == menu1_y - 8) y = menu1_y - 7;
            else y -= 1;
            GotoXY(x + 12, y + 5);
            std::cout << "--->";
            GotoXY(x + 33, y + 5);
            std::cout << "<---";
            if (option == 1) option = 2;
            else option--;
        }
        if (move == 13)
        {
            loadGameState(savefiles[option - 1]);
            kt = 0;
        }
        if (move == 27)
        {
            printMenu();
            kt = 0;
        }
    }
}

void LoadGame()
{
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);

    char savefiles[10][20] = { "savefile1", "whatevername" };

    GotoXY(x + 17, y + 2);
    std::cout << "Choose a Save File:";
    for (int i = 1; i < 3; i++)
    {
        GotoXY(x + 20, y + 2 + i + 2);
        std::cout << savefiles[i - 1];
    }
    GotoXY(x + 5, y + 8 + 2);
    std::cout << "Press Esc to turn back the main Menu...";

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

void PlaywithBot() {
    int xUndo, yUndo;
    int result = 0;
    bool validEnter = true;
    while (true) {
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
                system("cls");
                return;
            }
            else if (_COMMAND == 'A') MoveLeft();
            else if (_COMMAND == 'D') MoveRight();
            else if (_COMMAND == 'W') MoveUp();
            else if (_COMMAND == 'S') MoveDown();
            else if (_COMMAND == 13) {
                result = CheckBoard(_X, _Y);
                if (result != 0) {
                    GotoXY(_X, _Y);
                    txtColor(FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    cout << 'X';
                    xUndo = _X;
                    yUndo = _Y;
                    int row = (_Y - TOP - 1) / 2;
                    int col = (_X - LEFT - 2) / 4;
                    int winPositions[5][2];
                    int gameResult = TestBoard(row, col, winPositions);
                    if (gameResult != 2) {
                        GotoXY(0, BOARD_SIZE * 2 + 2);
                        if (gameResult == 0) {
                            cout << "Hoa nhau";
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
                int result = CheckBoard(pX, pY);
                if (result != 0) {
                    GotoXY(pX, pY);
                    txtColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
                    cout << 'O';
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
    }
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


