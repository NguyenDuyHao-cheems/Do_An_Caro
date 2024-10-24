#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1

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

void DrawBoard(int pSize) {
    for (int i = 0; i <= pSize; i++) {
        for (int j = 0; j <= pSize; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            cout << ".";
        }
    }
    system("color 74");
}

void Box(int x, int y, int w, int h) {
    if (w <= 1 || h <= 1) return;
    for (int ix = x; ix <= x + w; ix++) {
        GotoXY(ix, y);
        cout << char(196);
        GotoXY(ix, y + h);
        cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++) {
        GotoXY(x, iy);
        cout << char(179);
        GotoXY(x + w, iy);
        cout << char(179);
    }
    GotoXY(x, y); cout << char(218);
    GotoXY(x + w, y); cout << char(191);
    GotoXY(x, y + h); cout << char(192);
    GotoXY(x + w, y + h); cout << char(217);
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
        cout << char(194);
        i = i + 4;
    }
    i = LEFT + 4;
    j = TOP + pSize * 2;
    while (i <= (pSize) * 4) {
        GotoXY(i, j);
        cout << char(193);
        i = i + 4;
    }
    j = TOP + 2;
    i = LEFT;
    while (j <= (pSize ) * 2) {
        GotoXY(i, j);
        cout << char(195);
        j = j + 2;
    }
    j = TOP + 2;
    i = LEFT+pSize*4;
    while (j <= (pSize) * 2) {
        GotoXY(i, j);
        cout << char(180);
        j = j + 2;
    }
    for (int i = 1; i <= pSize - 1; i++) {
        for (int j = 1; j <= pSize - 1; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            cout << char(197);
        }
    }
    system("color 74");
}

void StartGame() {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
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


void AskContinue() {
    GotoXY(0, BOARD_SIZE * 2 + 4);
    cout << "Nhan 'y' de choi tiep, phim bat ky de thoat: ";
    char c = toupper(_getch());
    if (c == 'Y') {
        StartGame();
    }
    else {
        system("cls");
        exit(0);
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

int main() {
    FixConsoleWindow();
    StartGame();
    bool validEnter = true;
    while (true) {
        _COMMAND = toupper(_getch());
        if (_COMMAND == 27) {
            system("cls");
            return 0;
        }
        else if (_COMMAND == 'A') MoveLeft();
        else if (_COMMAND == 'D') MoveRight();
        else if (_COMMAND == 'W') MoveUp();
        else if (_COMMAND == 'S') MoveDown();
        else if (_COMMAND == 13) {
            int result = CheckBoard(_X, _Y);
            if (result != 0) {
                GotoXY(_X, _Y);
                cout << (result == -1 ? 'X' : 'O');
                int row = (_Y - TOP - 1) / 2;
                int col = (_X - LEFT - 2) / 4;
                int gameResult = TestBoard(row, col);
                if (gameResult != 2) {
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) cout << "Hoa nhau";
                    else
                    cout << (gameResult == -1 ? "X Thang!" : "O Thang!" ) << endl;
                    AskContinue();
                }
                _TURN = !_TURN;
            }
        }
    }
}
