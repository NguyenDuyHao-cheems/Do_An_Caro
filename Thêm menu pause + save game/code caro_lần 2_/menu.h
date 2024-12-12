#pragma once 
#include "game.h"
void DrawRoundedBox(int x, int y, int width, int height, int color);
void CharToWChar(const char* charArray, wchar_t* wcharArray, int size);
void PlayMusic(const char* filePath, const wchar_t* alias);
void PlayTick(const char* filePath, const wchar_t* alias);
void PlayWin(const char* filePath, const wchar_t* alias);
void PlayMove(const char* filePath, const wchar_t* alias);
void PlayMo(const char* filePath, const wchar_t* alias);
void StopAllSounds();

void SelectMenu(int k); // ham dieu huong lua chon khi an enter
void MenuSelection(); // ham ve mui ten lua chon
void printMenu(); //ham in cac chu newgame,exit,help...
void DrawFull(int x, int y, int w, int h, int color, int ch); //ham ve mot khoi 
void Box(int x, int y, int w, int h); //ham ve khung
void Help(); // ham huong dan choi
void Exit(); //ham thoat game
void About(); // ham gioi thieu ve nhom
void Setting(); //setting am thanh

void drawCaro(); // ve chu caro
void DrawSquare(int x, int y, int color); // ve hinh vuong rong 2 dai 1 ki tu 219
void DrawLine(char a[120], int x, int x2, int y2);
void DrawNotX(int x, int y);
void DrawIsX(int x, int y);
void DrawNotO(int x, int y);
void DrawIsO(int x, int y);
void drawpoke(int x, int y);
void drawpoke2(int x, int y);
void drawTable(int x, int y);
void drawHowtoPlay(int x, int y);
void drawPinkBox(int x, int y);
void drawPauseBox(int x, int y);
void drawESC(int x, int y);
void DrawMenuOption(int x, int y, const char* text, int color);
void drawExit(int x, int y);
void drawY(int x, int y  	);
void drawE(int x, int y  );

void drawS(int x, int y  );

void drawYes(int x, int y  );

void drawtrueY(int x, int y);

void drawtrueE(int x, int y);

void drawtrueS(int x, int y);

void drawtrueYes(int x, int y);

void drawNo(int x, int y);

void drawtrueno(int x, int y);

void drawNo(int x, int y, int choose);
void cha(int x, int y);

void Settingve(int x, int y);

void setg(int x, int y);

void muiten(int x, int y);

void drawPinkBox2(int x, int y);

void load(int x, int y);

void des(int x, int y);

void PauseMenu();
void PauseSelection(int option);
void SaveGameMenu();
void duplicateNameMenu();
void SaveSuccessMenu();
void maxNumSFMenu();
void SettingPause();
void loadOrDeleteMenu();
void confirmOverwrite();
// ham ve hieu ung thang thua hoa
void ve();
void ve2();
void ve3();
//new game
void NewGameSelection();
void NewGame();
void drawBigCloud(int x, int y);

void drawSmallCloud(int x, int y);

void drawInformation(int x, int y);

void playerName_withPlayer();

void playerName_withBot();

void drawPlayername(int x, int y);
