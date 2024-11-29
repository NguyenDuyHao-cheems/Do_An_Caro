#include "Console.h"

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    SetWindowLong(consoleWindow, GWL_STYLE, style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void GotoXY(int x, int y) {
    COORD coord = { SHORT(x), SHORT(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void txtColor(int k) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void SetConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
<<<<<<< Updated upstream
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
=======
    windowSize.Right = width - 2;
    windowSize.Bottom = height - 2;
>>>>>>> Stashed changes
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void SetFontSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = width;   
    cfi.dwFontSize.Y = height; 
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");  
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}
