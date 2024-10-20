#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0;
		}
	}
	_TURN = true; _COMMAND = -1;
	_X = _A[0][0].x; _Y = _A[0][0].y;
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

void StarGame() {
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
}


void ExitGame() {
	system("cls");
}

int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin) {
	case -1:
		printf_s("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);
		break;
	case 1:
		printf_s("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true);
		break;
	case 0:
		printf_s("Nguoi choi %d da hoa voi nguoi choi %d\n", false, true);
		break;
	case 2:
		_TURN = !_TURN;
	}
	GotoXY(_X, _Y);
	return pWhoWin;
}

int  AskContinue() {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y+4);
	printf_s("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(_getch());
}

bool checkWin(_POINT a[BOARD_SIZE][BOARD_SIZE], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		int truy = 1;
		for (int i = 0; i < m - 1; i++)
		{
			if ((a[i][j].c == a[i + 1][j].c) && (a[i][j].c != 0))
			{
				truy++;
				if (truy == 5)
				{
					return true;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int truy = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if ((a[i][j].c == a[i + 1][j].c) && (a[i][j].c != 0))
			{
				truy++;
				if (truy == 5)
				{
					return true;
				}
			}
		}
	}
	for (int i = 1; i < m; i++) {
		int truy = 1;
		int k = i;
		int j = 0;
		while (k > 0 && j < n - 1) {
			if (a[k][j].c == a[k - 1][j + 1].c && a[k][j].c != 0) truy++;
			if (truy == 5) return true;
			else {
				truy = 1;
			}
			k--; j++;
		}
	}
	for (int j = 1; j < n - 1; j++) {
		int truy = 1;
		int i = m - 1;
		int k = j;
		while (i > 0 && k < n - 1) {
			if (a[i][k].c == a[i - 1][k + 1].c && a[i][k].c != 0) truy++;
			if (truy == 5) return true;
			else {
				truy = 1;
			}
			i--; k++;
		}
	}
	for (int i = 1; i < m; i++) {
		int truy = 1;
		int j = n - 1;
		int k = i;
		while (k > 0 && j > 0) {
			if (a[k][j].c == a[k - 1][j - 1].c && a[k][j].c != 0) truy++;
			if (truy == 5) return true;
			else {
				truy = 1;
			}
			k--; j--;
		}
	}
	for (int j = n - 2; j > 0; j--) {
		int truy = 1;
		int i = m - 1;
		int k = j;
		while (i > 0 && k > 0) {
			if (a[i][k].c == a[i - 1][k - 1].c && a[i][k].c != 0) truy++;
			if (truy == 5) return true;
			else {
				truy = 1;
			}
			i--; k--;
		}
	}
	return false;
}

int TestBoard() {
	int dem = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == -1 || _A[i][j].c == 1) dem++;
		}
	}
	if (dem==144) return 0;
	else {
		if (checkWin(_A, BOARD_SIZE, BOARD_SIZE)) {
			return (_TURN == true ? -1 : 1);
		}
		else return 2;
	}
}

int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1;
				else _A[i][j].c= 1;
				return _A[i][j].c;
			}
		}
	}
	return 0;
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

void main() {
	FixConsoleWindow();
	StarGame();
	bool validEnter = true;
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			ExitGame();
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13) {
				switch (CheckBoard(_X, _Y)) {
				case -1:
					printf_s("X");
					break;
				case 1:
					printf_s("O");
					break;
				case 0: validEnter = false;
				}
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard())) {
					case -1: case 1: case 0:
						if (AskContinue() != 'Y') {
							ExitGame();
							return ;
						}
						else StarGame();
					}
				}
				validEnter = true;
			}
		}
	}
}