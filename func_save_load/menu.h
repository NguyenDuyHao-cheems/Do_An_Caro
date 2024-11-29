#pragma once 

<<<<<<< Updated upstream


=======
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
// ham ve hieu ung thang thua hoa
void ve();
void ve2();

//new game
 void NewGameSelection();
=======
void PauseMenu();
void PauseSelection(int option);
void SaveGameMenu();
void duplicateNameMenu();
void SaveSuccessMenu();
void maxNumSFMenu();
void SettingPause();

// ham ve hieu ung thang thua hoa
void ve();
void ve2();
void ve3();
//new game
void NewGameSelection();
>>>>>>> Stashed changes
void NewGame();

void DrawRoundedBox(int x, int y, int width, int height, int color);
void PlayMusic(bool isPlaying);