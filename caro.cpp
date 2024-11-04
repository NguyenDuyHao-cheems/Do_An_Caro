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
            cout << char(ch);
        }
    }
    txtColor(116);
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

void StartGame() {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
    PlayGame();
}

void Help() {
    int x = menu1_x - 15, y = menu1_y-8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    int i = 2;
    GotoXY(x + 20, y + 2);
    cout << "Control: ";
    GotoXY(x + 5, y + 3 + i);
    cout << "W A S D: Move";
    GotoXY(x + 5, y + 4 + i);
    cout << "Enter: choose";
    GotoXY(x + 5, y + 5 + i);
    cout << "L: Save Game";
    GotoXY(x + 5, y + 6 + i);
    cout << "Esc: Exit Game without saving";
    GotoXY(x + 5, y + 8 + i);
    cout << "Press Enter to turn back the main Menu...";
    while (1>0) {
        if (_getch() == 13) printMenu();
    }
}

void Exit() {
    int x = menu1_x - 15, y = menu1_y - 8, w = 50, h = 13;
    DrawFull(x + 2, y + 1, w + 1, h, 136, 32);
    DrawFull(x, y, w, h, 195, 197);
    DrawFull(x + 2, y + 1, w - 4, h - 2, 119, 32);
    GotoXY(x + 15, y + 2);
    cout << "Do you want to exit game.";
    GotoXY(x + 10, y + 5);
    cout << "Yes";
    GotoXY(x + 40, y + 5);
    cout << "No";
    GotoXY(x + 7, y + 10);
    cout << "Press y to exit, enter to back to menu.";
    char c;
    while (1) {
        c = _getch();
        if (c == 121) {
            system("cls");
            exit(0);
        }
        else if (c == 13) {
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
    cout << "Member:";
    GotoXY(x + 5, y + 3);
    cout << "1. MSSV: 24120306 - Nguyen Duy Hao";
    GotoXY(x + 5, y + 5);
    cout << "2. MSSV: 24120295 - Pham Xuan Duy";
    GotoXY(x + 5, y + 7);
    cout << "3. MSSV: 24120224 - Nguyen Anh Thai";
    GotoXY(x + 5, y + 9);
    cout << "4. MSSV: 24120289 - Nguyen Anh Duc";
    GotoXY(x + 5, y + 11);
    cout << "5. MSSV: 24120237 - Nguyen Dinh Tuan";
    GotoXY(x + 5, y + 13);
    cout << "Press Enter to turn back the main Menu...";
    while (1>0) {
        if (_getch() == 13) printMenu();
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

void PlayGame() {
    bool validEnter = true;
    while (true) {
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
                cout << (result == -1 ? 'X' : 'O');
                int row = (_Y - TOP - 1) / 2;
                int col = (_X - LEFT - 2) / 4;
                int gameResult = TestBoard(row, col);
                if (gameResult != 2) {
                    GotoXY(0, BOARD_SIZE * 2 + 2);
                    if (gameResult == 0) cout << "Hoa nhau";
                    else
                        cout << (gameResult == -1 ? "X Thang!" : "O Thang!") << endl;
                    AskContinue();
                }
                _TURN = !_TURN;
            }
        }
    }
}

void SelectMenu(int k) {
    switch (k) {
    case menu1_y:
        StartGame();
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
    while (kt==1) {
        move = _getch();
        move = toupper(move);
        if (move == 80 || move == 'S') {
            GotoXY(x-4 , y);
            cout << "    ";
            GotoXY(x + 25, y);
            cout << "    ";
            if (y == menu1_y + 10) y = menu1_y;
            else y+=2;
            GotoXY(x-4, y);
            cout << "--->";
            GotoXY(x + 25, y);
            cout << "<---";
        }
        if (move == 72 || move == 'W') {
            GotoXY(x-4, y);
            cout << "    ";
            GotoXY(x + 25, y);
            cout << "    ";
            if (y == menu1_y) y = menu1_y + 10;
            else y-=2;
            GotoXY(x-4, y);
            cout << "--->";
            GotoXY(x + 25, y);
            cout << "<---";
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
    Box(menu1_x +3, menu1_y - 1, 19, 2);
    GotoXY(menu1_x+5, menu1_y);
    cout << "    NEW GAME     " << endl;
    Box(menu1_x + 3, menu1_y +1 , 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 1);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 1);
    cout << char(180);
    GotoXY(menu1_x+5, menu1_y + 2);
    cout << "    LOAD GAME    " << endl;
    Box(menu1_x + 3, menu1_y + 3, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 3);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 3);
    cout << char(180);
    GotoXY(menu1_x+5, menu1_y + 4);
    cout << "      HELP       " << endl;
    Box(menu1_x + 3, menu1_y + 5, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 5);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 5);
    cout << char(180);
    GotoXY(menu1_x+5, menu1_y + 6);
    cout << "      ABOUT      " << endl;
    Box(menu1_x + 3, menu1_y + 7, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 7);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 7);
    cout << char(180);
    GotoXY(menu1_x+5, menu1_y + 8);
    cout << "      EXIT       " << endl;
    Box(menu1_x + 3, menu1_y + 9, 19, 2);
    GotoXY(menu1_x + 3, menu1_y + 9);
    cout << char(195);
    GotoXY(menu1_x + 22, menu1_y + 9);
    cout << char(180);
    GotoXY(menu1_x+5, menu1_y + 10);
    cout << "     SETTINGS    " << endl;
    GotoXY(menu1_x-4, menu1_y);
    cout << "--->";
    GotoXY(menu1_x + 25, menu1_y);
    cout << "<---";
    MenuSelection();
}

int main() {
    FixConsoleWindow();
    printMenu();
}
