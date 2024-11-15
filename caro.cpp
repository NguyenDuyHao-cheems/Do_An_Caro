#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1
#define menu1_x LEFT+41
#define menu1_y TOP+12

void printMenu();
void PlayGame();
void PlaywithBot();

struct _POINT {
    int x, y, c;
};

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    SetWindowLong(consoleWindow, GWL_STYLE, style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void GotoXY(int x, int y) {
    COORD coord = { SHORT(x), SHORT(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2;
            _A[i][j].y = 2 * i + TOP + 1;
            _A[i][j].c = 0;
        }
    }
    _TURN = true;
    _X = _A[0][0].x;
    _Y = _A[0][0].y;
}

void txtColor(int k) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void DrawFull(int x, int y, int w, int h, int color, int ch) {
    txtColor(color);
    for (int i = x; i <= x + w; i++) {
        for (int j = y; j <= y + h; j++) {
            GotoXY(i, j);
            std::cout << char(ch);
        }
    }
    txtColor(116);
}

void Box(int x, int y, int w, int h) {
    if (w <= 1 || h <= 1) return;
    for (int ix = x; ix <= x + w; ix++) {
        GotoXY(ix, y);
        std::cout << char(196);
        GotoXY(ix, y + h);
        std::cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++) {
        GotoXY(x, iy);
        std::cout << char(179);
        GotoXY(x + w, iy);
        std::cout << char(179);
    }
    GotoXY(x, y); std::cout << char(218);
    GotoXY(x + w, y); std::cout << char(191);
    GotoXY(x, y + h); std::cout << char(192);
    GotoXY(x + w, y + h); std::cout << char(217);
}

void DrawBoard(int pSize) {
    for (int i = 0; i < pSize; i++) {
        for (int j = 0; j < pSize; j++) {
            Box(LEFT + 4 * i, TOP + 2 * j, 4, 2);
        }
    }
    int i, j;
    j = TOP;
    i = LEFT + 4;
    while (i <= (pSize) * 4) {
        GotoXY(i, j);
        std::cout << char(194);
        i = i + 4;
    }
    i = LEFT + 4;
    j = TOP + pSize * 2;
    while (i <= (pSize) * 4) {
        GotoXY(i, j);
        std::cout << char(193);
        i = i + 4;
    }
    j = TOP + 2;
    i = LEFT;
    while (j <= (pSize) * 2) {
        GotoXY(i, j);
        std::cout << char(195);
        j = j + 2;
    }
    j = TOP + 2;
    i = LEFT + pSize * 4;
    while (j <= (pSize) * 2) {
        GotoXY(i, j);
        std::cout << char(180);
        j = j + 2;
    }
    for (int i = 1; i <= pSize - 1; i++) {
        for (int j = 1; j <= pSize - 1; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            std::cout << char(197);
        }
    }
    system("color 74");
}

int CheckBoard(int pX, int pY) {
    int row = (pY - TOP - 1) / 2;
    int col = (pX - LEFT - 2) / 4;
    if (_A[row][col].c == 0) {
        _A[row][col].c = _TURN ? -1 : 1;
        return _A[row][col].c;
    }
    return 0;
}

bool checkWin(int row, int col) {
    int current = _A[row][col].c;
    if (current == 0) return false;
    int count;
    count = 1;
    for (int j = col - 1; j >= 0 && _A[row][j].c == current; j--) count++;
    for (int j = col + 1; j < BOARD_SIZE && _A[row][j].c == current; j++) count++;
    if (count >= 5) return true;
    count = 1;
    for (int i = row - 1; i >= 0 && _A[i][col].c == current; i--) count++;
    for (int i = row + 1; i < BOARD_SIZE && _A[i][col].c == current; i++) count++;
    if (count >= 5) return true;
    count = 1;
    for (int i = 1; row - i >= 0 && col - i >= 0 && _A[row - i][col - i].c == current; i++) count++;
    for (int i = 1; row + i < BOARD_SIZE && col + i < BOARD_SIZE && _A[row + i][col + i].c == current; i++) count++;
    if (count >= 5) return true;
    count = 1;
    for (int i = 1; row + i < BOARD_SIZE && col - i >= 0 && _A[row + i][col - i].c == current; i++) count++;
    for (int i = 1; row - i >= 0 && col + i < BOARD_SIZE && _A[row - i][col + i].c == current; i++) count++;
    if (count >= 5) return true;
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

int TestBoard(int row, int col) {
    if (isFull(_A)) return 0;
    else {
        if (checkWin(row, col)) {
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

void DrawSquare(int x, int y, int color) {
    txtColor(color);

    for (int i = x; i < x + 2; i++) {
        GotoXY(i, y);
        cout << char(219);

    }
    txtColor(116);
}

void DrawLine(char a[120], int x, int x2, int y2)
{
    for (int j = 0; j < x; j++)
    {
        if (a[j] == '0') DrawSquare(x2 + 2 * j, y2, 0);
        else if (a[j] == '1') DrawSquare(x2 + 2 * j, y2, 1);
        else if (a[j] == '2') DrawSquare(x2 + 2 * j, y2, 2);
        else if (a[j] == '3') DrawSquare(x2 + 2 * j, y2, 3);
        else if (a[j] == '4') DrawSquare(x2 + 2 * j, y2, 4);
        else if (a[j] == '5') DrawSquare(x2 + 2 * j, y2, 5);
        else if (a[j] == '6') DrawSquare(x2 + 2 * j, y2, 6);
        else if (a[j] == '7') DrawSquare(x2 + 2 * j, y2, 7);
        else if (a[j] == '8') DrawSquare(x2 + 2 * j, y2, 8);
        else if (a[j] == '9') DrawSquare(x2 + 2 * j, y2, 9);
        else if (a[j] == 'A') DrawSquare(x2 + 2 * j, y2, 10);
        else if (a[j] == 'B') DrawSquare(x2 + 2 * j, y2, 11);
        else if (a[j] == 'C') DrawSquare(x2 + 2 * j, y2, 12);
        else if (a[j] == 'D') DrawSquare(x2 + 2 * j, y2, 13);
        else if (a[j] == 'E') DrawSquare(x2 + 2 * j, y2, 14);
        else if (a[j] == 'F') DrawSquare(x2 + 2 * j, y2, 15);
    }
}

void DrawNotX(int x, int y)
{
    char NotX[20][20] = { " 0000     0000 ",
                          "066660   066660",
                          "066660   066660",
                          "0666660 0666660",
                          "046666606666640",
                          "044666666666440",
                          "004466666664400",
                          " 0044EEEEE4400 ",
                          "  006666666600 ",
                          "  06666666660  ",
                          " 0666664666660 ",
                          "066666444666660",
                          "066664404466660",
                          "044444000444440",
                          "0444400 0044440",
                          "000000   000000" };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(NotX[i], 15, x, y);
        y++;
    }
}

void DrawIsX(int x, int y)
{
    char IsX[20][20] = {  " 8888     8888 ",
                          "8EEEE8   8EEEE8",
                          "8EEEE8   8EEEE8",
                          "8EEEEE8 8EEEEE8",
                          "8CEEEEE8EEEEEC8",
                          "8CCEEEEEEEEECC8",
                          "88CCEEEEEEECC88",
                          " 88CCCCCCCCC88 ",
                          "  88EEEEEEEE88 ",
                          "  8EEEEEEEEE8  ",
                          " 8EEEEECEEEEE8 ",
                          "8EEEEECCCEEEEE8",
                          "8EEEECC8CCEEEE8",
                          "8CCCCC888CCCCC8",
                          "8CCCC88 88CCCC8",
                          "888888   888888" };
    for (int i = 0; i <= 15; i++) 
    {
        DrawLine(IsX[i], 15, x, y);
        y++;
    }
}

void DrawNotO(int x, int y)
{
    char NotO[20][20] = {
        "   0000000   ",
        "  011111110  ",
        " 01111111110 ",
        "0111111111110",
        "01111BBB11110",
        "01111BBB11110",
        "0111100011110",
        "088880 088880",
        "033330 033330",
        "0333300033330",
        "0333333333330",
        "0B333333333B0",
        "0BB3333333BB0",
        "00BBBBBBBBB00",
        " 00BBBBBBB00 ",
        "  000000000  "
    };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(NotO[i], 13, x, y);
        y++;
    }
}

void DrawIsO(int x, int y)
{
    char IsO[20][20] = {
        "   0000000   ",
        "  033333330  ",
        " 03333333330 ",
        "0333333333330",
        "03333FFF33330",
        "03333FFF33330",
        "0333300033330",
        "077770 077770",
        "0BBBB0 0BBBB0",
        "0BBBB000BBBB0",
        "0BBBBBBBBBBB0",
        "0FBBBBBBBBBF0",
        "0FFBBBBBBBFF0",
        "00FFFFFFFFF00",
        " 00FFFFFFF00 ",
        "  000000000  "
    };
    for (int i = 0; i <= 15; i++)
    {
        DrawLine(IsO[i], 13, x, y);
        y++;
    }
}

void StartGame() {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    PlayGame();
}

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

void Help() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    int i = 2;
    GotoXY(x + 20, y + 2);
    std::cout << "Control: ";
    GotoXY(x + 5, y + 3 + i);
    std::cout << "W A S D: Move";
    GotoXY(x + 5, y + 4 + i);
    std::cout << "Enter: choose";
    GotoXY(x + 5, y + 5 + i);
    std::cout << "L: Save Game";
    GotoXY(x + 5, y + 6 + i);
    std::cout << "Esc: Exit Game without saving";
    GotoXY(x + 5, y + 8 + i);
    std::cout << "Press Enter to turn back the main Menu...";
    while (1 > 0) {
        if (_getch() == 13) printMenu();
    }
}

void Exit() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2);
    std::cout << "Do you want to exit game.";
    GotoXY(x + 10, y + 5);
    std::cout << "Yes";
    GotoXY(x + 40, y + 5);
    std::cout << "No";
    GotoXY(x + 7, y + 10);
    std::cout << "Press y to exit, n to back to menu.";
    char c;
    while (1) {
        c = _getch();
        if (c == 121) {
            system("cls");
            exit(0);
        }
        else if (c == 110) {
            printMenu();

        }
    }
}

void About() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 15;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 20, y + 1);
    std::cout << "Member:";
    GotoXY(x + 5, y + 3);
    std::cout << "1. MSSV: 24120306 - Nguyen Duy Hao";
    GotoXY(x + 5, y + 5);
    std::cout << "2. MSSV: 24120295 - Pham Xuan Duy";
    GotoXY(x + 5, y + 7);
    std::cout << "3. MSSV: 24120224 - Nguyen Anh Thai";
    GotoXY(x + 5, y + 9);
    std::cout << "4. MSSV: 24120289 - Nguyen Anh Duc";
    GotoXY(x + 5, y + 11);
    std::cout << "5. MSSV: 24120237 - Nguyen Dinh Tuan";
    GotoXY(x + 5, y + 13);
    std::cout << "Press Enter to turn back the main Menu...";
    while (1 > 0) {
        if (_getch() == 13) printMenu();
    }
}

void AskContinue() {
    GotoXY(0, BOARD_SIZE * 2 + 4);
    std::cout << "Nhan 'y' de choi tiep, phim bat ky de thoat: ";
    char c = toupper(_getch());
    if (c == 'Y') {
        StartGame();
    }
    else {
        system("cls");
        exit(0);
    }
}

int evaluatePosition( int row, int col, int player) {
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
                score += evaluatePosition( i, j, -1);
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
    bool validEnter = true;
    while (true) {
        if (_TURN == true) {
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
                int result = CheckBoard(_X, _Y);
                if (result != 0) {
                    GotoXY(_X, _Y);
                    cout << 'X';
                    int row = (_Y - TOP - 1) / 2;
                    int col = (_X - LEFT - 2) / 4;
                    int gameResult = TestBoard(row, col);
                    if (gameResult != 2) {
                        GotoXY(0, BOARD_SIZE * 2 + 2);
                        if (gameResult == 0) cout << "Hoa nhau";
                        else
                            cout << (gameResult == -1 ? "Nguoi choi Thang!" : "May Thang!") << endl;
                        AskContinue();
                    }
                    _TURN = !_TURN;
                }
            }
        }
        else {
            int pX, pY;
            BotMove(pX, pY);
            int result = CheckBoard(pX, pY);
            if (result != 0) {
                GotoXY(pX, pY);
                cout << 'O';
                int row = (pY - TOP - 1) / 2;
                int col = (pX - LEFT - 2) / 4;
                int gameResult = TestBoard(row, col);
                if (gameResult != 2) {
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) cout << "Hoa nhau";
                    else
                        cout << (gameResult == -1 ? "Nguoi choi Thang!" : "May Thang!") << endl;
                    AskContinue();
                }
                _TURN =! _TURN;
            }
        }
    }
}

void PlayGame() {
    int result = 0;
    int xUndo, yUndo;
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
        else if (_COMMAND == 'A' || _COMMAND == 75) MoveLeft();
        else if (_COMMAND == 'D' || _COMMAND == 77) MoveRight();
        else if (_COMMAND == 'W' || _COMMAND == 72) MoveUp();
        else if (_COMMAND == 'S' || _COMMAND == 80) MoveDown();
        else if (_COMMAND == 13) {
            result = CheckBoard(_X, _Y);
            if (result != 0) {
                GotoXY(_X, _Y);
                std::cout << (result == -1 ? 'X' : 'O');
                xUndo = _X;
                yUndo = _Y;
                int row = (_Y - TOP - 1) / 2;
                int col = (_X - LEFT - 2) / 4;
                int gameResult = TestBoard(row, col);
                if (gameResult != 2) 
                {
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) std::cout << "Hoa nhau";
                    else
                        std::cout << (gameResult == -1 ? "X Thang!" : "O Thang!") << endl;
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

void SelectMenu(int k) {
    switch (k) {
    case menu1_y:
        StartGame();
        break;
    case menu1_y + 2:
        LoadGame();
        break;
    case menu1_y + 4:
        Help();
        break;
    case menu1_y + 6:
        About();
        break;
    case menu1_y + 8:
        Exit();
        break;
    }
}

void MenuSelection() {
    int x = menu1_x, y = menu1_y;
    int move;
    int kt = 1;
    while (kt == 1) {
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S') {
            GotoXY(x - 4, y);
            std::cout << "    ";
            GotoXY(x + 25, y);
            std::cout << "    ";
            if (y == menu1_y + 10) y = menu1_y;
            else y += 2;
            GotoXY(x - 4, y);
            std::cout << "--->";
            GotoXY(x + 25, y);
            std::cout << "<---";
        }
        if (move == 72 || move == 'W') {
            GotoXY(x - 4, y);
            std::cout << "    ";
            GotoXY(x + 25, y);
            std::cout << "    ";
            if (y == menu1_y) y = menu1_y + 10;
            else y -= 2;
            GotoXY(x - 4, y);
            std::cout << "--->";
            GotoXY(x + 25, y);
            std::cout << "<---";
        }
        if (move == 13) {
            SelectMenu(y);
            kt = 0;
        }
    }
}

void printMenu() {
    system("cls");
    system("color B0");
    Box(menu1_x + 3, menu1_y - 1, 19, 2);
    GotoXY(menu1_x + 5, menu1_y);
    std::cout << "    NEW GAME     " << endl;
    Box(menu1_x + 3, menu1_y + 1, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 1);
    std::cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 1);
    std::cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 2);
    std::cout << "    LOAD GAME    " << endl;
    Box(menu1_x + 3, menu1_y + 3, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 3);
    std::cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 3);
    std::cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 4);
    std::cout << "      HELP       " << endl;
    Box(menu1_x + 3, menu1_y + 5, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 5);
    std::cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 5);
    std::cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 6);
    std::cout << "      ABOUT      " << endl;
    Box(menu1_x + 3, menu1_y + 7, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 7);
    std::cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 7);
    std::cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 8);
    std::cout << "      EXIT       " << endl;
    Box(menu1_x + 3, menu1_y + 9, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 9);
    std::cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 9);
    std::cout << char(180);
    GotoXY(menu1_x + 5, menu1_y + 10);
    std::cout << "     SETTINGS    " << endl;
    GotoXY(menu1_x - 4, menu1_y);
    std::cout << "--->";
    GotoXY(menu1_x + 25, menu1_y);
    std::cout << "<---";
    MenuSelection();
}

int main() {
    SetConsoleOutputCP(437);
    FixConsoleWindow();
    printMenu();
}
